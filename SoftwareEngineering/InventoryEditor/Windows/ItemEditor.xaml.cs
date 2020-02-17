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

            Item.SetProperty("m_id", TxtId.Text);
            Item.SetProperty("m_name", TxtName.Text);

            completionTask.SetResult(Item);

            this.Close();
        }
    }
}
