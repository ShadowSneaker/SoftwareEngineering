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
using System.Windows.Navigation;
using System.Windows.Shapes;
using Microsoft.Win32;

namespace InventoryEditor.Controls
{
    /// <summary>
    /// Interaction logic for FileSelector.xaml
    /// </summary>
    public partial class FileSelector : UserControl
    {
        private string path;
        public string FilePath
        {
            get { return path; }
            set
            {
                path = value;
                fileLoc.Text = value;
            }
        }
        private ItemDBModel db;

        public FileSelector()
        {
            InitializeComponent();
            db = MainWindow.Database;
        }

        private void ButtonBase_OnClick(object sender, RoutedEventArgs e)
        {
            while (db.GameDirectory == String.Empty)
            {
                if (MessageBox.Show("Game Directory not set! Please set it now!", "Hang On!", MessageBoxButton.OK, MessageBoxImage.Stop) == MessageBoxResult.OK)
                    db.GetGameDirectory();
            }

            OpenFileDialog ofd = new OpenFileDialog();
            ofd.InitialDirectory = db.GameDirectory;
            ofd.Filter = "Image Files|*.jpg;*.jpeg;*.png;*.gif;*.tif";
            if (ofd.ShowDialog() == true)
            {
                if(!ofd.FileName.StartsWith(db.GameDirectory))
                {
                    MessageBox.Show("File is not within the selected Game Directory!" + $" ({db.GameDirectory})", "Hang On!", MessageBoxButton.OK,
                        MessageBoxImage.Stop);
                }
                else
                {
                    FilePath = ofd.FileName;
                }
            }
        }
    }
}
