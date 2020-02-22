using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InventoryEditor.Models
{
    public class InventoryModel
    {
        public string m_owner;
        public string m_id;
        public List<string> items = new List<string>();
    }
}
