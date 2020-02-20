using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryEditor.Models
{
    public static class ItemTypes
    {
        static List<ItemType> types = new List<ItemType>();

        public static void Init()
        {
            types.Add(new ItemType("Consumable", new List<string>() { "m_effects|efxlist" }));
            types.Add(new ItemType("Equippable", new List<string>() { "m_slot|combo(head,body,legs,feed)", "m_effects|efxlist" }));
            types.Add(new ItemType("Switchable", new List<string>() { "m_effects|efxlist" }));
            types.Add(new ItemType("Item", null));
        }

        public static ItemType[] GetTypes() { return types.ToArray(); }
    }

    public class ItemType
    {
        public string Type;
        public string[] Properties;

        public struct ProperyInfo
        {
            public string DisplayName;
            public string Name;
            public string Type;
            public string[] Metadata;
        }


        public ProperyInfo[] GetPropertiesInfo()
        {
            List<ProperyInfo> infos = new List<ProperyInfo>();
            foreach (var Property in Properties)
            {
                var split = Property.Split('|');
                var name = split[0];
                var propType = split[1].TrimEnd(')');
                var propValues = "";
                split = propType.Split('(');
                if (split.Length > 0)
                {
                    propType = split[0];
                    if (split.Length > 1)
                        propValues = split[1];
                }

                string trimmedName = name.TrimStart('m','_');
                trimmedName = System.Globalization.CultureInfo.CurrentCulture.TextInfo.ToTitleCase(trimmedName.ToLower());

                infos.Add(new ProperyInfo(){DisplayName = trimmedName, Name = name, Type = propType, Metadata = propValues.Split(',')});
            }

            return infos.ToArray();
        }

        public ItemType(string type, List<string> properties)
        {
            Type = type;

            if (properties == null)
                properties = new List<string>();

            properties.AddRange(new string[] { "m_id|string", "m_name|string", "m_icon|file", "m_isQuestItem|bool", "m_stackable|bool", "m_value|int", "m_weight|int" });

            Properties = properties.ToArray();
        }
    }
}
