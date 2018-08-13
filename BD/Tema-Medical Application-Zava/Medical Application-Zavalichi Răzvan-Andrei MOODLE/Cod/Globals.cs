using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MedicalDB
{
    public class Globals
    {

        static string startupPath = System.IO.Directory.GetCurrentDirectory();
        public static string connString;

        static Globals()
        {
            //-Fara installer-//
            startupPath = startupPath.Substring(0, startupPath.LastIndexOf('\\'));
            startupPath = startupPath.Substring(0, startupPath.LastIndexOf('\\'));

            //-Pentru installer se lasa locatia din debug- //
            connString = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=" + startupPath + @"\MedicalDatabase.mdf;Integrated Security=True";
        }
        //VS:2015   (LocalDB)\MSSQLLocalDB  -database
        //VS>2012   (LocalDB)\v11.0         -database2

    }

}
