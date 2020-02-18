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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            this.Close();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            var type = Models.ItemTypes.GetTypes().FirstOrDefault(x => x.Type == TypeComboBox.SelectedItem);
            Item = new ItemModel(type.Type, type.Properties.ToList());

            foreach (var val in Item.Properties.ToArray())
            {
                var split = val.Key.Split('|');
                var name = split[0];
                var propType = split[1].TrimEnd(')');
                var propValues = "";
                split = propType.Split('(');
                if (split.Length > 0)
                {
                    propType = split[0];
                    if (split.Length > 1)
                        propValues = split[1];
                }

                string value = "";

                switch (propType)
                {
                    case "int":
                        break;
                    case "string":
                        value = ((TextBox) controls.FirstOrDefault(x=> x.Name == name)).Text;
                        break;
                    case "bool":
                        value = ((CheckBox)controls.FirstOrDefault(x => x.Name == name)).IsChecked.Value.ToString();
                        break;
                    case "combo":
                        value = ((ComboBox)controls.FirstOrDefault(x => x.Name == name)).SelectedValue.ToString();
                        break;
                }
                Item.SetProperty(name, value);
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

        private void TypeComboBox_OnSelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            ClearControls();
            var type = Models.ItemTypes.GetTypes().FirstOrDefault(x => x.Type == TypeComboBox.SelectedItem);
            int propIndex = 1;
            foreach (var Property in type.Properties)
            {
                var split = Property.Split('|');
                var name = split[0];
                var propType = split[1].TrimEnd(')');
                var propValues = "";
                split = propType.Split('(');
                if (split.Length > 0)
                {
                    propType = split[0];
                    if(split.Length > 1)
                        propValues = split[1];
                }

                Control valueControl = null;
                Label nameTxt = new Label();
                nameTxt.Content = name.TrimStart('m');
                switch (propType)
                {
                    case "int":
                        break;
                    case "string":
                        valueControl = new TextBox();
                        valueControl.Name = name;
                        break;
                    case "bool":
                        valueControl = new CheckBox();
                        valueControl.Name = name;
                        break;
                    case "combo":
                        valueControl = new ComboBox();
                        valueControl.Name = name;
                        split = propValues.Split(',');
                        foreach (var s in split)
                        {
                            ((ComboBox) valueControl).Items.Add(s);
                        }
                        break;
                }

                theGrid.Children.Add(nameTxt);
                controls.Add(nameTxt);
                nameTxt.Margin = new Thickness(0, (propIndex * 26) + 5,0,0);
               // nameTxt.Height = 26;
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
        }
    }
}
