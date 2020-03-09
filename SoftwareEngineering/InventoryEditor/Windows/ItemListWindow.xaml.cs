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

namespace InventoryEditor.Windows
{
    /// <summary>
    /// Interaction logic for ItemListWindow.xaml
    /// </summary>
    public partial class ItemListWindow : Window
    {
        private TaskCompletionSource<ItemModel> task;

        public ItemListWindow()
        {
            InitializeComponent();
            foreach (var item in MainWindow.Database.Items)
            {
                ListView.Items.Add(item);
            }
        }

        public static Task<ItemModel> GetItem()
        {
            ItemListWindow win = new ItemListWindow();
            win.task = new TaskCompletionSource<ItemModel>();
            win.Show();

            return win.task.Task;
        }

        private void ListView_OnMouseDoubleClick(object sender, MouseButtonEventArgs e)
        {
            if (ListView.SelectedIndex != -1)
            {
                task.SetResult(MainWindow.Database.Items[ListView.SelectedIndex]);
                Close();
            }
        }
    }
}
