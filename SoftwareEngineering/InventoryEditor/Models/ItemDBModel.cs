using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Forms;
using InventoryEditor.Models;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace InventoryEditor
{
    public class ItemDBModel
    {
        public List<ItemModel> Items = new List<ItemModel>();
        public List<InventoryModel> Inventories = new List<InventoryModel>();
        public string GameDirectory = "";

        public ItemModel GetItemById(string id)
        {
            return Items.FirstOrDefault(x => x.Properties["m_id"] == id);
        }

        public void GetGameDirectory()
        {
            using (var dialog = new FolderBrowserDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    GameDirectory = dialog.SelectedPath;
                }
            }
        }

        public void Save(string path)
        {
            GameDirectory = Path.GetDirectoryName(path);
            Cursor.Current = Cursors.WaitCursor;
            string json = JsonConvert.SerializeObject(this);
            File.WriteAllText(path, json);
            Cursor.Current = Cursors.Default;
        }

        public static ItemDBModel Load(string path)
        {
            Cursor.Current = Cursors.WaitCursor;
            ItemDBModel model = new ItemDBModel();
            List<ItemModel> items = new List<ItemModel>();

            model.Inventories = new List<InventoryModel>();

            string json = File.ReadAllText(path);
            JObject jObj = JObject.Parse(json);
            model.GameDirectory = jObj["GameDirectory"]?.Value<string>();
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

            JArray jInventories = (JArray)jObj["Inventories"];
            for (int i = 0; i < jInventories.Count; i++)
            {
                InventoryModel inventory = new InventoryModel();

                inventory.items = new List<string>();
                inventory.m_id = jInventories[i]["m_id"].Value<string>();
                inventory.m_owner = jInventories[i]["m_owner"].Value<string>();
                foreach (var value in jInventories[i]["items"].Values())
                {
                    inventory.items.Add(value.Value<string>());
                }
                model.Inventories.Add(inventory);
            }

            model.Items = items;
            Cursor.Current = Cursors.Default;
            model.GameDirectory = Path.GetDirectoryName(path);
            return model;
        }
    }
}
