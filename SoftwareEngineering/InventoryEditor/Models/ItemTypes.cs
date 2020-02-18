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
            types.Add(new ItemType("Equipable", new List<string>() { "m_slot|combo(head,body,legs,feed)" }));
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

            properties.AddRange(new string[] { "m_id|string", "m_name|string", "m_icon|file", "m_isQuestItem|bool", "m_stackable|bool", "m_value|int", "m_weight|int" });

            Properties = properties.ToArray();
        }
    }
}
