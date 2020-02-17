using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Newtonsoft.Json;

namespace InventoryEditor
{
    public class ItemDBModel
    {
        public List<ItemModel> Items = new List<ItemModel>();

        public void Save(string path)
        {
            string json = JsonConvert.SerializeObject(this);
            File.WriteAllText(path, json);
        }

        public static ItemDBModel Load(string path)
        {
            return JsonConvert.DeserializeObject<ItemDBModel>(File.ReadAllText(path));
        }
    }
}
