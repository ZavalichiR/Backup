using System;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Drawing;

namespace L8_Numeric
{

    public partial class Ceas2 : Form
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
        public Ceas2()
        {
            InitializeComponent();
            this.BackColor = Color.Bisque;
            panel1.BackColor = Color.Bisque;
            panel2.BackColor = Color.Bisque;
            panel3.BackColor = Color.Bisque;
            panel4.BackColor = Color.Bisque;
            this.Text = "Analog Clock";
        }
        int WIDTH = 300, HEIGHT = 300, secHAND = 140, minHAND = 110, hrHAND = 80;

        //center
        int cx, cy;
        Bitmap bmp;
        Graphics g;

        private void Ceas_Load(object sender, EventArgs e)
        {
            //timer1.Tick += new EventHandler(timer_Tick);
            //timer1.Interval = (1000) * (1);              // Timer will tick evert second
            //timer1.Enabled = true;                       // Enable the timer
            //timer1.Start();

            //creare bitmap
            bmp = new Bitmap(WIDTH + 1, HEIGHT + 1);

            //centru
            cx = WIDTH / 2;
            cy = HEIGHT / 2;

            //timer
            timer1.Interval = 1000; //in milisecunde
            timer1.Tick += new EventHandler(this.t_Tick);
            timer1.Start();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        void timer_Tick(object sender, EventArgs e)
        {
            SystemTime data;

            GetLocalTime(out data);
            richTextBox1.Text = (data.wHour < 10 ? "0" + data.wHour : "" + data.wHour);
            richTextBox2.Text = (data.wMinute < 10 ? "0" + data.wMinute : "" + data.wMinute);
            richTextBox3.Text = (data.wSecond < 10 ? "0" + data.wSecond : "" + data.wSecond);
        }



        //Timer t = new Timer();

       
        private void t_Tick(object sender, EventArgs e)
        {
            SystemTime data;
            GetLocalTime(out data);
            richTextBox1.Text = (data.wHour < 10 ? "0" + data.wHour : "" + data.wHour);
            richTextBox2.Text = (data.wMinute < 10 ? "0" + data.wMinute : "" + data.wMinute);
            richTextBox3.Text = (data.wSecond < 10 ? "0" + data.wSecond : "" + data.wSecond);

            //creare grafic
            g = Graphics.FromImage(bmp);

            //timpul actual
            int ss = data.wSecond;
            int mm = data.wMinute;
            int hh = data.wHour;

            int[] handCoord = new int[2];

            //golire grafic
            g.Clear(Color.White);

            //desenare cerc
            g.DrawEllipse(new Pen(Color.SandyBrown,200f), 0, 0, WIDTH, HEIGHT);

            //desenare numere
            g.DrawString("12", new Font("Arial", 14), Brushes.Black, new Point(140, 2));
            g.DrawString("1", new Font("Arial", 10), Brushes.Black, new Point(213, 20));
            g.DrawString("2", new Font("Arial", 10), Brushes.Black, new Point(260, 70));
            g.DrawString("3", new Font("Arial", 14), Brushes.Black, new Point(284, 140));
            g.DrawString("4", new Font("Arial", 10), Brushes.Black, new Point(260, 210));
            g.DrawString("5", new Font("Arial", 10), Brushes.Black, new Point(213, 260));
            g.DrawString("6", new Font("Arial", 14), Brushes.Black, new Point(142, 278));
            g.DrawString("7", new Font("Arial", 10), Brushes.Black, new Point(75, 260));
            g.DrawString("8", new Font("Arial", 10), Brushes.Black, new Point(18, 210));
            g.DrawString("9", new Font("Arial", 14), Brushes.Black, new Point(0, 140));
            g.DrawString("10", new Font("Arial", 10), Brushes.Black, new Point(18, 70));
            g.DrawString("11", new Font("Arial", 10), Brushes.Black, new Point(70, 20));
            int s = 0;
            for(int i=0;i<60;++i)
            {
                if (s%5 !=0)
                {
                    handCoord = msCoord(s, secHAND-5);
                    g.DrawString("*", new Font("Arial", 7), Brushes.Black, new Point(handCoord[0] - 5, handCoord[1] - 5));
                }
                    s++;
            }

            //limba secundar
            handCoord = msCoord(ss, secHAND);
            g.DrawLine(new Pen(Color.Red, 1f), new Point(cx, cy), new Point(handCoord[0], handCoord[1]));

            //limba minutar
            handCoord = msCoord(mm, secHAND);
            g.DrawLine(new Pen(Color.Black, 2f), new Point(cx, cy), new Point(handCoord[0], handCoord[1]));

            //limba ore
            handCoord = hrCoord(hh % 12, mm, secHAND);
            g.DrawLine(new Pen(Color.Gray, 3f), new Point(cx, cy), new Point(handCoord[0], handCoord[1]));

            //incarcarea imaginei 
            pictureBox1.Image = bmp;
            
            //dispose
            g.Dispose();

        }
        //coordonate pentru minute si secunde
        private int[] msCoord(int val, int hlen)
        {

            int[] coord = new int[2];
            val *= 6;
            if (val >= 0 && val <= 180)
            {
                coord[0] = cx + (int)(hlen * Math.Sin(Math.PI * val / 180));
                coord[1] = cy - (int)(hlen * Math.Cos(Math.PI * val / 180));
            }
            else
            {
                coord[0] = cx - (int)(hlen * -Math.Sin(Math.PI * val / 180));
                coord[1] = cy - (int)(hlen * Math.Cos(Math.PI * val / 180));
            }
            return coord;
        }
        //coordonate pentru ore
        private int[] hrCoord(int hval, int mval, int hlen)
        {
            int[] coord = new int[2];
            //each hour makes 30 degree
            //esch min makes 0.5 degree
            int val = (int)((hval * 30) + (mval * 0.5));

            if (val >= 0 && val <= 180)
            {
                coord[0] = cx + (int)(hlen * Math.Sin(Math.PI * val / 180));
                coord[1] = cy - (int)(hlen * Math.Cos(Math.PI * val / 180));
            }
            else
            {
                coord[0] = cx - (int)(hlen * -Math.Sin(Math.PI * val / 180));
                coord[1] = cy - (int)(hlen * Math.Cos(Math.PI * val / 180));
            }
            return coord;
        }
    }
}
    
