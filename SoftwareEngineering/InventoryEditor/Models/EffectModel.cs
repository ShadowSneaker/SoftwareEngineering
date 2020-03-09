using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryEditor.Models
{
    public class EffectModel
    {
        public string EffectClass { get; set; }
        public object EffectProperty { get; set; }

        public EffectModel Clone()
        {
            return new EffectModel() {EffectClass = EffectClass, EffectProperty = EffectProperty};
        }
    }
}
