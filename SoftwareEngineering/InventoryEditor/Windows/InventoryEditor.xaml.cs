using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;
using InventoryEditor.Models;

namespace InventoryEditor.Windows
{
    /// <summary>
    /// Interaction logic for InventoryEditor.xaml
    /// </summary>
    public partial class InventoryEditor : Window
    {
        private TaskCompletionSource<InventoryModel> task;

        InventoryModel inventory = new InventoryModel();

        public InventoryEditor()
        {
            InitializeComponent();
        }

        public static Task<InventoryModel> GetInventory(InventoryModel model= null)
        {
            InventoryEditor win =new InventoryEditor();
            win.task = new TaskCompletionSource<InventoryModel>();
            win.Show();

            if (model != null)
            {
                win.inventory = model;
                win.IdBox.Text = win.inventory.m_owner;
                win.InventoryIdBox.Text = win.inventory.m_id;
                win.Redraw();
            }

            return win.task.Task;
        }

        private void Save_Click(object sender, RoutedEventArgs e)
        {
            inventory.m_owner = IdBox.Text;
            inventory.m_id = InventoryIdBox.Text;
            task.SetResult(inventory);
            Close();
        }

        private void Cancel_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void Id_OnTextInput(object sender, TextCompositionEventArgs e)
        {
            inventory.m_owner = e.Text;
        }

        private void List_OnMouseRightButtonDown(object sender, MouseButtonEventArgs e)
        {
            ContextMenu menu = new ContextMenu();

            var deleteBtn = new MenuItem();
            deleteBtn.Header = "Remove Selected";
            if (ListView.SelectedIndex == -1)
                deleteBtn.IsEnabled = false;

            deleteBtn.Click += (o, args) =>
            {
                inventory.items.RemoveAt(ListView.SelectedIndex);
                Redraw();
            };

            var addBtn = new MenuItem();
            addBtn.Header = "Add Item";
            addBtn.Click += async (o, args) =>
            {
                var item = await ItemListWindow.GetItem();
                inventory.items.Add(item.Id);
                Redraw();
            };

            menu.Items.Add(addBtn);
            menu.Items.Add(deleteBtn);

            menu.Placement = PlacementMode.MousePoint;
            menu.IsOpen = true;
        }

        void Redraw()
        {
            ListView.Items.Clear();
            foreach (var item in inventory.items.ToArray())
            {
                var it = MainWindow.Database.GetItemById(item);
                if (it != null)
                    ListView.Items.Add(it);
                else
                    inventory.items.Remove(item);
            }
        }
    }
}
