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
        public Dictionary<string, object> Properties;

        public ItemModel(string type, List<string> properties)
        {
            Type = type;
            Properties = new Dictionary<string, object>(properties.Count);
            foreach (var item in properties)
            {
                Properties.Add(item, "");
            }
        }

        public void SetProperty(string name, object val)
        {
            if (Properties.ContainsKey(name))
                Properties[name] = val;
            else
                Properties.Add(name, val);
        }
    }
}
