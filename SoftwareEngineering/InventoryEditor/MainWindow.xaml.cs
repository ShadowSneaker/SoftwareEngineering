using Microsoft.Win32;
using System;
using System.Diagnostics;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Input;

namespace InventoryEditor
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        const string FILTER = "Item Database File (.kkc)|*.kkc";
        string lastSaveLocation = "";

        ItemDBModel db = new ItemDBModel();

        public MainWindow()
        {
            InitializeComponent();

            Models.ItemTypes.Init();
        }

        private void Quit_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void SupportEmail_Click(object sender, RoutedEventArgs e)
        {
            Process.Start("mailto:2CONSJ16@solent.ac.uk?subject=Inventory Editor Support Ticket: " + DateTime.Now.ToString("F"));
        }

        private void NewDB_Click(object sender, RoutedEventArgs e)
        {
            lastSaveLocation = null;
            db = new ItemDBModel();
            db.GetGameDirectory();
            Redraw();
        }

        private void OpenDB_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = FILTER;
            ofd.InitialDirectory = db.GameDirectory;
            if (ofd.ShowDialog() == true)
            {
                lastSaveLocation = ofd.FileName;
                db = ItemDBModel.Load(ofd.FileName);
            }
            Redraw();
        }

        private void SaveDB_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrEmpty(lastSaveLocation))
            {
                SaveAsDB_Click(sender, e);
                return;
            }

            db.Save(lastSaveLocation);
        }

        private void SaveAsDB_Click(object sender, RoutedEventArgs e)
        {
            while (db.GameDirectory == String.Empty)
            {
                if(MessageBox.Show("Game Directory not set! Please set it now!", "Hang On!", MessageBoxButton.OK, MessageBoxImage.Stop) == MessageBoxResult.OK)
                    db.GetGameDirectory();
            }

            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = FILTER;
            sfd.InitialDirectory = db.GameDirectory;
            if (sfd.ShowDialog() == true)
            {
                lastSaveLocation = sfd.FileName;
                db.Save(sfd.FileName);
            }
        }

        private async void NewItem_Click(object sender, RoutedEventArgs e)
        {
            var item = await ItemEditor.RequestItem();
            db.Items.Add(item);
            Redraw();
        }

        private void NewInventory_Click(object sender, RoutedEventArgs e)
        {

        }

        private void NewEffect_Click(object sender, RoutedEventArgs e)
        {

        }

        void Redraw()
        {
            ItemList.Items.Clear();
            foreach (var item in db.Items)
            {
                var node = new TreeViewItem() {Header = $"{item.Type}: {item.Properties["m_id"]}"};
                node.MouseDoubleClick += async (sender, args) =>
                {
                    int index = db.Items.IndexOf(item);
                    db.Items[index] = await ItemEditor.OpenItem(item);
                    Redraw();
                };
                ItemList.Items.Add(node);
            }
        }
    }
}
