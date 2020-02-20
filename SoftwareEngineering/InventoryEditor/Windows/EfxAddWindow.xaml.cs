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
using InventoryEditor.Models;

namespace InventoryEditor.Windows
{
    /// <summary>
    /// Interaction logic for EfxAddWindow.xaml
    /// </summary>
    public partial class EfxAddWindow : Window
    {
        private TaskCompletionSource<EffectModel> task;

        public EfxAddWindow()
        {
            InitializeComponent();
            foreach (var type in EffectTypes.GetTypes())
            {
                var item = new ListViewItem();
                item.Content = $"{type.EffectClass}";
                item.MouseDoubleClick += (sender, args) =>
                {
                    var effect = EffectTypes.GetTypes().FirstOrDefault(x => x.EffectClass == type.EffectClass);
                    if (effect != null)
                    {
                        task.SetResult(effect);
                        Close();
                    }
                };
                ListView.Items.Add(item);
            }
        }

        public static Task<EffectModel> GetEffect()
        {
            EfxAddWindow win = new EfxAddWindow();
            win.Show();
            win.task = new TaskCompletionSource<EffectModel>();

            return win.task.Task;
        }
    }
}
