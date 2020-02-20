using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryEditor.Models
{
    public static class EffectTypes
    {
        static List<EffectModel> types = new List<EffectModel>();

        public static void Init()
        {
            types.Add(new EffectModel(){EffectClass = "DamageBuffEffect", EffectProperty = 0});
            types.Add(new EffectModel() { EffectClass = "HealthEffect", EffectProperty = 0 });
            types.Add(new EffectModel() { EffectClass = "StaminaEffect", EffectProperty = 0 });
        }

        public static EffectModel[] GetTypes() { return types.ToArray(); }
    }
}
