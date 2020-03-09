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
using InventoryEditor.Controls;
using InventoryEditor.Models;

namespace InventoryEditor.Windows
{
    public partial class EfxListWindow : Window
    {
        private List<EffectModel> effects;

        private TaskCompletionSource<List<EffectModel>> task;

        public EfxListWindow()
        {
            InitializeComponent();
            
        }

        public static Task<List<EffectModel>> GetEffects(List<EffectModel> effects)
        {
            EfxListWindow win =new EfxListWindow();
            win.Show();
            win.task = new TaskCompletionSource<List<EffectModel>>();

            if(effects == null)
                effects = new List<EffectModel>();

            win.effects = effects;
            win.Redraw();

            return win.task.Task;
        }

        void Redraw()
        {
            list.Items.Clear();
            foreach (var effect in effects)
            {
                list.Items.Add(effect);
            }
        }

        private void SaveButton_OnClick(object sender, RoutedEventArgs e)
        {
            task.SetResult(effects);

            Close();
        }

        private void Cancel_OnClick(object sender, RoutedEventArgs e)
        {
            Close();
        }

        private void List_OnMouseRightButtonUp(object sender, MouseButtonEventArgs e)
        {
            ContextMenu menu = new ContextMenu();

            var deleteBtn = new MenuItem();
            deleteBtn.Header = "Remove Selected";
            if (list.SelectedIndex == -1)
                deleteBtn.IsEnabled = false;

            deleteBtn.Click += (o, args) =>
            {
                effects.RemoveAt(list.SelectedIndex);
                Redraw();
            };

            var addBtn = new MenuItem();
            addBtn.Header = "Add Effect";
            addBtn.Click += async (o, args) =>
            {
                effects.Add(await EfxAddWindow.GetEffect());
                Redraw();
            };

            menu.Items.Add(addBtn);
            menu.Items.Add(deleteBtn);

            menu.Placement = PlacementMode.MousePoint;
            menu.IsOpen = true;
        }
    }
}
