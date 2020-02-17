using Microsoft.Win32;
using System;
using System.Diagnostics;
using System.Windows;

namespace InventoryEditor
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        const string FILTER = "Item Database File (*.kkc)|.kkc";
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
            Redraw();
        }

        private void OpenDB_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = FILTER;
            if(ofd.ShowDialog() == true)
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
            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = FILTER;
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
                ItemList.Items.Add($"{item.Type}: {item.Properties["m_id"]}");
            }
        }
    }
}
