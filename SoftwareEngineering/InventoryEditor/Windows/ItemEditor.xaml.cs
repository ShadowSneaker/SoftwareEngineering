using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using InventoryEditor.Controls;
using InventoryEditor.Models;
using Newtonsoft.Json;
using Xceed.Wpf.Toolkit;

namespace InventoryEditor
{
    /// <summary>
    /// Interaction logic for ItemEditor.xaml
    /// </summary>
    public partial class ItemEditor : Window
    {
        private TaskCompletionSource<ItemModel> completionTask;

        ItemModel Item;
        List<Control> controls = new List<Control>();
        public ItemEditor()
        {
            InitializeComponent();

            foreach (var item in Models.ItemTypes.GetTypes())
            {
                TypeComboBox.Items.Add(item.Type);
            }
            TypeComboBox.SelectedIndex = 0;
        }

        public static Task<ItemModel> RequestItem()
        {
            var win = new ItemEditor();
            win.completionTask = new TaskCompletionSource<ItemModel>();

            win.Show();

            return win.completionTask.Task;
        }
        
        public static Task<ItemModel> OpenItem(ItemModel item)
        {
            var win = new ItemEditor();
            win.completionTask = new TaskCompletionSource<ItemModel>();

            win.Show();

            win.Item = item;

            win.ClearControls();
            win.DrawControls();

            win.SetControlValues(item);

            return win.completionTask.Task;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            var type = Models.ItemTypes.GetTypes().FirstOrDefault(x => x.Type == TypeComboBox.SelectedItem);
            var infos = type.GetPropertiesInfo();
            Item = new ItemModel(type.Type, type.Properties.ToList());

            foreach (var val in infos)
            {
                string value = "";

                switch (val.Type)
                {
                    case "int":
                        value = ((IntegerUpDown)controls.FirstOrDefault(x => x.Name == val.Name)).Value.Value.ToString();
                        break;
                    case "string":
                        value = ((WatermarkTextBox) controls.FirstOrDefault(x=> x.Name == val.Name)).Text;
                        break;
                    case "bool":
                        value = ((CheckBox)controls.FirstOrDefault(x => x.Name == val.Name)).IsChecked.Value.ToString();
                        break;
                    case "combo":
                        value = ((ComboBox)controls.FirstOrDefault(x => x.Name == val.Name)).SelectedValue.ToString();
                        break;
                    case "file":
                        value = ((FileSelector) controls.FirstOrDefault(x => x.Name == val.Name)).FilePath;
                        break;
                    case "efxlist":
                        value = JsonConvert.SerializeObject(((EfxList) controls.FirstOrDefault(x => x.Name == val.Name)).Effects);
                        break;
                }
                Item.SetProperty(val.Name, value);
            }
            completionTask.SetResult(Item);

            this.Close();
        }

        void ClearControls()
        {
            foreach (var control in controls)
            {
                theGrid.Children.Remove(control);
            }
            controls.Clear();
        }

        void SetControlValues(ItemModel item)
        {
            var type = Models.ItemTypes.GetTypes().FirstOrDefault(x => x.Type == TypeComboBox.SelectedItem);
            var infos = type.GetPropertiesInfo();
            Item = new ItemModel(type.Type, type.Properties.ToList());

            foreach (var val in infos)
            {
                string value = "";

                switch (val.Type)
                {
                    case "int":
                        if (item.Properties.ContainsKey(val.Name))
                            ((IntegerUpDown)controls.FirstOrDefault(x => x.Name == val.Name)).Value = int.Parse(item.Properties[val.Name]);
                        break;
                    case "string":
                        if (item.Properties.ContainsKey(val.Name))
                            ((WatermarkTextBox)controls.FirstOrDefault(x => x.Name == val.Name)).Text = item.Properties[val.Name];
                        break;
                    case "bool":
                        if (item.Properties.ContainsKey(val.Name))
                            ((CheckBox)controls.FirstOrDefault(x => x.Name == val.Name)).IsChecked = Convert.ToBoolean(item.Properties[val.Name]);
                        break;
                    case "combo":
                        if (item.Properties.ContainsKey(val.Name))
                            ((ComboBox)controls.FirstOrDefault(x => x.Name == val.Name)).SelectedValue = item.Properties[val.Name];
                        break;
                    case "file":
                        if (item.Properties.ContainsKey(val.Name))
                            ((FileSelector)controls.FirstOrDefault(x => x.Name == val.Name)).FilePath = item.Properties[val.Name];
                        break;
                    case "efxlist":
                        if(item.Properties.ContainsKey(val.Name))
                            ((EfxList)controls.FirstOrDefault(x => x.Name == val.Name)).Effects = JsonConvert.DeserializeObject<List<EffectModel>>(item.Properties[val.Name]);
                        break;
                }
                Item.SetProperty(val.Name, value);
            }
        }

        void DrawControls()
        {
            var type = Models.ItemTypes.GetTypes().FirstOrDefault(x => x.Type == TypeComboBox.SelectedItem);
            var infos = type.GetPropertiesInfo();
            int propIndex = 1;
            foreach (var Property in infos)
            {
                Control valueControl = null;
                Label nameTxt = new Label();
                nameTxt.Content = Property.DisplayName;
                switch (Property.Type)
                {
                    case "int":
                        valueControl = new IntegerUpDown();
                        valueControl.Name = Property.Name;
                        ((IntegerUpDown) valueControl).Value = 0;
                        break;
                    case "string":
                        valueControl = new WatermarkTextBox();
                        ((WatermarkTextBox)valueControl).Watermark = "...";
                        valueControl.Name = Property.Name;
                        break;
                    case "bool":
                        valueControl = new CheckBox();
                        valueControl.Name = Property.Name;
                        break;
                    case "file":
                        valueControl = new FileSelector();
                        valueControl.Name = Property.Name;
                        break;
                    case "efxlist":
                        valueControl = new EfxList();
                        valueControl.Name = Property.Name;
                        break;
                    case "combo":
                        valueControl = new ComboBox();
                        valueControl.Name = Property.Name;
                        foreach (var s in Property.Metadata)
                        {
                            ((ComboBox)valueControl).Items.Add(s);
                        }
                        ((ComboBox)valueControl).SelectedIndex = 0;
                        break;
                }

                theGrid.Children.Add(nameTxt);
                controls.Add(nameTxt);
                nameTxt.Margin = new Thickness(0, (propIndex * 26) + 5, 0, 0);
                if (valueControl != null)
                {
                    Grid.SetColumn(valueControl, 1);
                    valueControl.VerticalAlignment = VerticalAlignment.Top;
                    valueControl.HorizontalContentAlignment = HorizontalAlignment.Stretch;
                    valueControl.Margin = new Thickness(0, (propIndex * 26) + 5, 0, 0);
                    valueControl.Height = 26;
                    theGrid.Children.Add(valueControl);
                    controls.Add(valueControl);
                }

                propIndex++;

            }
            this.MinHeight = (propIndex + 1 * 26) * 10;
            this.Height = (propIndex + 1 * 26) * 10;
        }

        private void TypeComboBox_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ClearControls();
            DrawControls();
        }
    }
}
