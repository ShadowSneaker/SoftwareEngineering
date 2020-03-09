using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace InventoryEditor
{
    public class ItemModel
    {
        public string Type;
        public Dictionary<string, string> Properties;

        public string Id
        {
            get { return Properties["m_id"]; }
        }

        public string Name
        {
            get { return Properties["m_name"]; }
        }

        public string ItemType
        {
            get { return Type; }
        }

        public ItemModel(string type, List<string> properties)
        {
            Type = type;
            Properties = new Dictionary<string, string>(properties.Count);
            foreach (var item in properties)
            {
                Properties.Add(item, "");
            }
        }

        public ItemModel(string type, Dictionary<string, string> properties)
        {
            Type = type;
            Properties = properties;
        }

        public void SetProperty(string name, string val)
        {
            if (Properties.ContainsKey(name))
                Properties[name] = val;
            else
                Properties.Add(name, val);
        }
    }
}
