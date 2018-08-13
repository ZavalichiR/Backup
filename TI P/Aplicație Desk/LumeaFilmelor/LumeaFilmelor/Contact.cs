using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LumeaFilmelor
{
    public partial class Contact : Form
    {
        public Contact()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 form = new Form1();
            this.Close();
            form.Show();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            Filme form = new Filme();
            this.Hide();
            form.Show();

        }

        private void button4_Click(object sender, EventArgs e)
        {
            //Detalii form = new Detalii();
            // this.Hide();
            //form.Show();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            Contact form = new Contact();
            this.Hide();
            form.Show();
        }

        private void button6_Click(object sender, EventArgs e)
        {
            Sitemapcs form = new Sitemapcs();
            this.Hide();
            form.Show();
        }
    }
}
