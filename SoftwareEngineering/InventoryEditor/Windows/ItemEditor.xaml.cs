using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using Xceed.Wpf.Toolkit;

namespace InventoryEditor
{
    /// <summary>
    /// Interaction logic for ItemEditor.xaml
    /// </summary>
    public partial class ItemEditor : Window
    {
        static TaskCompletionSource<ItemModel> completionTask;

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
            completionTask = new TaskCompletionSource<ItemModel>();

            var win = new ItemEditor();
            win.Show();

            return completionTask.Task;
        }
        
        public static Task<ItemModel> OpenItem(ItemModel item)
        {
            completionTask = new TaskCompletionSource<ItemModel>();

            var win = new ItemEditor();
            win.Show();

            win.ClearControls();
            win.DrawControls();

            win.SetControlValues(item);

            return completionTask.Task;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            var type = Models.ItemTypes.GetTypes().FirstOrDefault(x => x.Type == TypeComboBox.SelectedItem);
            var infos = type.GetPropertyInfo();
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
            var infos = type.GetPropertyInfo();
            Item = new ItemModel(type.Type, type.Properties.ToList());

            foreach (var val in infos)
            {
                string value = "";

                switch (val.Type)
                {
                    case "int":
                        ((IntegerUpDown) controls.FirstOrDefault(x => x.Name == val.Name)).Value = int.Parse(item.Properties[val.Name]);
                        break;
                    case "string":
                        ((WatermarkTextBox)controls.FirstOrDefault(x => x.Name == val.Name)).Text = item.Properties[val.Name];
                        break;
                    case "bool":
                        ((CheckBox)controls.FirstOrDefault(x => x.Name == val.Name)).IsChecked = Convert.ToBoolean(item.Properties[val.Name]);
                        break;
                    case "combo":
                        ((ComboBox)controls.FirstOrDefault(x => x.Name == val.Name)).SelectedValue = item.Properties[val.Name];
                        break;
                }
                Item.SetProperty(val.Name, value);
            }
        }

        void DrawControls()
        {
            var type = Models.ItemTypes.GetTypes().FirstOrDefault(x => x.Type == TypeComboBox.SelectedItem);
            var infos = type.GetPropertyInfo();
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
                        valueControl.Name = Property.Name; ;
                        break;
                    case "bool":
                        valueControl = new CheckBox();
                        valueControl.Name = Property.Name; ;
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
