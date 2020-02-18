using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Forms;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;

namespace InventoryEditor
{
    public class ItemDBModel
    {
        public List<ItemModel> Items = new List<ItemModel>();
        public string GameDirectory = "";

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

            model.Items = items;
            Cursor.Current = Cursors.Default;
            return model;
        }
    }
}
