using Microsoft.Win32;
using System;
using System.Diagnostics;
using System.Linq;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Controls.Primitives;
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

        public static ItemDBModel Database { get; set; } = new ItemDBModel();

        public MainWindow()
        {
            InitializeComponent();

            StatusBar.Items.Add("Program Opened");

            Models.ItemTypes.Init();
            UpdateStatusBar("Items Initialized");
            Models.EffectTypes.Init();
            UpdateStatusBar("Effects Initialized");
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
            Database = new ItemDBModel();
            Database.GetGameDirectory();
            Redraw();
            UpdateStatusBar("New Database created");
        }

        private void OpenDB_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = FILTER;
            ofd.InitialDirectory = Database.GameDirectory;
            if (ofd.ShowDialog() == true)
            {
                lastSaveLocation = ofd.FileName;
                Database = ItemDBModel.Load(ofd.FileName);
            }
            Redraw();
            UpdateStatusBar("Opened Database file");
        }

        private void SaveDB_Click(object sender, RoutedEventArgs e)
        {
            if (string.IsNullOrEmpty(Database.GameDirectory))
            {
                SaveAsDB_Click(sender, e);
                return;
            }

            lastSaveLocation = Database.GameDirectory + "\\db.kkc";
            Database.Save(lastSaveLocation);
            UpdateStatusBar("Saved Database file");
        }

        private void SaveAsDB_Click(object sender, RoutedEventArgs e)
        {
            while (Database.GameDirectory == String.Empty)
            {
                if(MessageBox.Show("Game Directory not set! Please set it now!", "Hang On!", MessageBoxButton.OK, MessageBoxImage.Stop) == MessageBoxResult.OK)
                    Database.GetGameDirectory();
            }


            if (Database.GameDirectory != String.Empty)
            {
                if (MessageBox.Show(
                        "Are you sure you want to Save As? Doing so will change the \"Game Directory\" and will break any selected files or directories!",
                        "Hang On!", MessageBoxButton.YesNo, MessageBoxImage.Stop) == MessageBoxResult.Yes)
                {
                    Database.GetGameDirectory();
                    lastSaveLocation = Database.GameDirectory + "\\db.kkc";
                    Database.Save(lastSaveLocation);
                    UpdateStatusBar("Saved Database file");
                }
            }
        }

        private async void NewItem_Click(object sender, RoutedEventArgs e)
        {
            var item = await ItemEditor.RequestItem();
            Database.Items.Add(item);
            Redraw();
            UpdateStatusBar("Added new item");
        }

        private async void NewInventory_Click(object sender, RoutedEventArgs e)
        {
            var item = await Windows.InventoryEditor.GetInventory();
            Database.Inventories.Add(item);
            Redraw();
            UpdateStatusBar("Added new inventory");
        }
        
        void Redraw()
        {
            ItemList.Items.Clear();
            InventoryList.Items.Clear();
            foreach (var item in Database.Items)
            {
                var node = new TreeViewItem() {Header = $"{item.Type}: {item.Properties["m_id"]}"};
                node.MouseDoubleClick += async (sender, args) =>
                {
                    int index = Database.Items.IndexOf(item);
                    Database.Items[index] = await ItemEditor.OpenItem(item);
                    UpdateStatusBar("Updated item");
                    Redraw();
                };
                node.MouseRightButtonUp += (sender, args) =>
                {
                    ContextMenu menu = new ContextMenu();

                    var deleteBtn = new MenuItem();
                    deleteBtn.Header = "Remove Selected";

                    deleteBtn.Click += (o, args1) =>
                    {
                        Database.Items.Remove(item);
                        Redraw();
                    };

                    menu.Items.Add(deleteBtn);

                    menu.Placement = PlacementMode.MousePoint;
                    menu.IsOpen = true;
                };
                ItemList.Items.Add(node);
            }

            foreach (var item in Database.Inventories)
            {
                var node = new TreeViewItem() { Header = $"{item.m_owner}: {item.m_id}" };
                node.MouseDoubleClick += async (sender, args) =>
                {
                    int index = Database.Inventories.IndexOf(item);
                    Database.Inventories[index] = await Windows.InventoryEditor.GetInventory(item);
                    UpdateStatusBar("Updated item");
                    Redraw();
                };

                node.MouseRightButtonUp += (sender, args) =>
                {
                    ContextMenu menu = new ContextMenu();

                    var deleteBtn = new MenuItem();
                    deleteBtn.Header = "Remove Selected";

                    deleteBtn.Click += (o, args1) =>
                    {
                        Database.Inventories.Remove(item);
                        Redraw();
                    };

                    menu.Items.Add(deleteBtn);

                    menu.Placement = PlacementMode.MousePoint;
                    menu.IsOpen = true;
                };
                InventoryList.Items.Add(node);
            }
        }

        void UpdateStatusBar(string status)
        {
            StatusBar.Items[0] = DateTime.Now.TimeOfDay.ToString(@"hh\:mm\:ss") + ": " + status;
        }

        private void MainWindow_OnKeyDown(object sender, KeyEventArgs e)
        {
            if (e.Key == Key.S && Keyboard.Modifiers == ModifierKeys.Control)
            {
                SaveDB_Click(null, null);
            }
        }
    }
}
