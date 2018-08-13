using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;


namespace P20_Examen
{
    public partial class Form1 : Form
    {
        double r = 0;
        public Form1()
        {
            
            InitializeComponent();
            label1.Text = "Sirul de numere: ";
            for (int i = 0; i < ConfigurationSettings.AppSettings.Count; i++)
            {
                label1.Text+=" " +Double.Parse(ConfigurationSettings.AppSettings[i]);
               
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double[] vector = new double[3];

            for (int i = 0; i < ConfigurationSettings.AppSettings.Count; i++)
                {
                    vector[i] = Double.Parse(ConfigurationSettings.AppSettings[i]);
                    r += vector[i];
                }
            label2.Text = r.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            XmlTextWriter textWriter = new XmlTextWriter("rezultat.xml", Encoding.ASCII);
            textWriter.WriteStartDocument();

            textWriter.WriteStartElement("node");
            textWriter.WriteAttributeString("rezultat", r.ToString());
            textWriter.WriteEndElement();
            textWriter.WriteEndDocument();
            MessageBox.Show("rezultat salvat");
            textWriter.Close();
        }
    }
}
