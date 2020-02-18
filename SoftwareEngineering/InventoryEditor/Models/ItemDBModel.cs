using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

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
            ItemDBModel model = new ItemDBModel();
            List<ItemModel> items = new List<ItemModel>();

            string json = File.ReadAllText(path);
            JObject jObj = JObject.Parse(json);
            JArray jItems = (JArray)jObj["Items"];
            for (int i = 0; i < jItems.Count; i++)
            {
                string type = jItems[i]["Type"].Value<string>();
                var props = jItems[i]["Properties"].Values();
                Dictionary<string, string> propsDictionary = new Dictionary<string, string>();
                foreach (var prop in props)
                {
                    propsDictionary.Add(((JProperty)prop.Parent).Name, prop.Value<string>());
                }
                ItemModel item = new ItemModel(type, propsDictionary);
                items.Add(item);
            }

            model.Items = items;
            return model;
            // string json = File.ReadAllText(path);
            //MessageBox.Show(json, "Opening file...", MessageBoxButton.OK);
            //return JsonConvert.DeserializeObject<ItemDBModel>(json);
        }
    }
}
