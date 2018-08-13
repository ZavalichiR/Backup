using System;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace L8_Numeric
{

    public partial class Ceas : Form
    {
        public bool flag=false;
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

        [DllImport("kernel32.dll")]
        public static extern void GetLocalTime(out SystemTime time);
        public Ceas()
        {
            InitializeComponent();
            timer1.Tick += new EventHandler(timer_Tick);
            timer1.Interval = (1000) * (1);              // Timer will tick evert second
            timer1.Enabled = true;                       // Enable the timer
            timer1.Start();

        }

        private void Ceas_Load(object sender, EventArgs e)
        {
            SystemTime data;
            GetLocalTime(out data);
            richTextBox1.Text = (data.wHour < 10 ? "0" + data.wHour : "" + data.wHour);
            richTextBox2.Text = (data.wMinute < 10 ? "0" + data.wMinute : "" + data.wMinute);
            richTextBox3.Text = (data.wSecond < 10 ? "0" + data.wSecond : "" + data.wSecond);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            timer1.Enabled = true;                       // Enable the timer
            timer1.Start();

        }

        void timer_Tick(object sender, EventArgs e)
        {
            SystemTime data;

            GetLocalTime(out data);
            richTextBox1.Text = (data.wHour < 10 ? "0" + data.wHour : "" + data.wHour);
            richTextBox2.Text = (data.wMinute < 10 ? "0" + data.wMinute : "" + data.wMinute);
            richTextBox3.Text = (data.wSecond < 10 ? "0" + data.wSecond : "" + data.wSecond);
        }
        private void button3_Click(object sender, EventArgs e)
        {
            timer1.Enabled = false;                       // Enable the timer
            timer1.Stop();
        }
    }
}
    
