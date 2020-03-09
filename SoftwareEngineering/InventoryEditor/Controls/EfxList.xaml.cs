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
using InventoryEditor.Models;
using InventoryEditor.Windows;

namespace InventoryEditor.Controls
{
    /// <summary>
    /// Interaction logic for EfxList.xaml
    /// </summary>
    public partial class EfxList : UserControl
    {
        private List<EffectModel> effects;

        public List<EffectModel> Effects
        {
            get { return effects; }
            set { effects = value;
                Label.Content = "Effect Count: " + (effects != null ? effects.Count.ToString() : "0");
            }
        }

        public EfxList()
        {
            InitializeComponent();
        }

        private async void ButtonBase_OnClick(object sender, RoutedEventArgs e)
        {
            Effects = await EfxListWindow.GetEffects(effects);
        }
    }
}
