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
            types.Add(new ItemType("Consumable", null));
            types.Add(new ItemType("Equipable", new List<string>() { "m_slot" }));
            types.Add(new ItemType("Switchable", null));
        }

        public static ItemType[] GetTypes() { return types.ToArray(); }
    }

    public class ItemType
    {
        public string Type;
        public string[] Properties;

        public ItemType(string type, List<string> properties)
        {
            Type = type;

            if (properties == null)
                properties = new List<string>();

            properties.AddRange(new string[] { "m_id", "m_name", "m_icon", "m_isQuestItem", "m_stackable", "m_value", "m_weight" });

            Properties = properties.ToArray();
        }
    }
}
