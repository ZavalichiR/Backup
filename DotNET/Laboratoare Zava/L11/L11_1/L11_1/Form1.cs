using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Resources;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L11_1
{
    public partial class Form1 : Form
    {
        public struct SystemTime
        {
            public short wYear;
            public short wMonth;
            public short wDayOfWeek;
            public short wDay;
            public short wHour;
            public short wMinute;
            public short wSecond;
            public short wMilliseconds;
        }
        int index = 0;

        private ResourceManager rm;
        [DllImport("kernel32.dll")]
        public static extern void GetLocalTime(out SystemTime time);
        public Form1()
        {
            InitializeComponent();
            rm = new ResourceManager("L11_1.resurse", typeof(Form1).Assembly);

            timer1.Tick += new EventHandler(timer_Tick);
            timer1.Interval = (1000) * (2);              // Timer will tick evert second
            timer1.Enabled = true;                       // Enable the timer
            timer1.Start();


        }
    
        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            String limba = comboBox1.Text;
            
            switch (limba)
            {
                case "RO":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("ro");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("ro");
                    label1.Text = rm.GetString("mesaj");
                    break;
                case "EN":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("en");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("en");
                    label1.Text = rm.GetString("mesaj");
                    break;
                case "FR":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("fr");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("fr");
                    label1.Text = rm.GetString("mesaj");
                    break;
                case "Spanish":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("es-ES");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("es-ES");
                    label1.Text = rm.GetString("mesaj");
                    break;
                case "Chinese":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("zh-CN");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("zh-CN");
                    label1.Text = rm.GetString("mesaj");
                    break;
                case "Japain":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("ja-JP");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("ja-JP");
                    label1.Text = rm.GetString("mesaj");
                    break;
                default:
                    break;
            }
        }

        void timer_Tick(object sender, EventArgs e)
        {
            if (index == 6)
                index = 0;
            SystemTime data;
            GetLocalTime(out data);
            int ss = data.wSecond;
            int mm = data.wMinute;
            int hh = data.wHour;

            

            String[] limba = { "RO", "EN", "FR","Spanish", "Chinese", "Japain" };
            switch (limba[index])
            {
                case "RO":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("ro");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("ro");
                    label1.Text = rm.GetString("mesaj");
                    label1.BackColor = Color.Green;
                    break;
                case "EN":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("en");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("en");
                    label1.Text = rm.GetString("mesaj");
                    label1.BackColor = Color.Red;
                    break;
                case "FR":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("fr");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("fr");
                    label1.Text = rm.GetString("mesaj");
                    label1.BackColor = Color.Red;
                    break;
                case "Spanish":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("es-ES");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("es-ES");
                    label1.Text = rm.GetString("mesaj");
                    label1.BackColor = Color.Red;
                    break;
                case "Chinese":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("zh-CN");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("zh-CN");
                    label1.Text = rm.GetString("mesaj");
                    label1.BackColor = Color.Red;
                    break;
                case "Japain":
                    Thread.CurrentThread.CurrentCulture = new System.Globalization.CultureInfo("ja-JP");
                    Thread.CurrentThread.CurrentUICulture = new System.Globalization.CultureInfo("ja-JP");
                    label1.Text = rm.GetString("mesaj");
                    label1.BackColor = Color.Red;
                    break;
                default:
                    break;
            }
            index++;
        }


    }
}
