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
        public MainWindow()
        {
            InitializeComponent();
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

        }

        private void OpenDB_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            if(ofd.ShowDialog() == true)
            {

            }
        }

        private void SaveDB_Click(object sender, RoutedEventArgs e)
        {
            SaveFileDialog sfd = new SaveFileDialog();
            //sfd.Filter
        }

        private void SaveAsDB_Click(object sender, RoutedEventArgs e)
        {

        }

        private void NewItem_Click(object sender, RoutedEventArgs e)
        {

        }

        private void NewInventory_Click(object sender, RoutedEventArgs e)
        {

        }

        private void NewEffect_Click(object sender, RoutedEventArgs e)
        {

        }
    }
}
