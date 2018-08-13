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
    public partial class DespreFilm : Form
    {
        public DespreFilm()
        {
            InitializeComponent();
        }
        public DespreFilm(Film film)
        {
            InitializeComponent();
            label1.Text = film.getTitlu();
            label10.Text = film.getOriginalTitlu();
            label11.Text = film.getGen();
            label12.Text = film.getDurata();
            label13.Text = film.getRegizor();
            label14.Text = film.getAn().ToString();
            label15.Text = film.getLimba();
            label16.Text = film.getActori();
            label17.Text = film.getPremiera();
            richTextBox2.Text = film.getDescriere();
            button7.Text = "";
            string url = film.getImagine().Replace("/", "\\");
            string startupPath = System.IO.Directory.GetCurrentDirectory();
            startupPath = startupPath.Substring(0, startupPath.LastIndexOf('\\'));
            startupPath = startupPath.Substring(0, startupPath.LastIndexOf('\\'));

            button7.Image = Image.FromFile(startupPath + "\\" + url);

        }
        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 form = new Form1();
            this.Hide();
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

        private void button7_MouseLeave(object sender, EventArgs e)
        {
            button7.Width = 135;
            button7.Height = 163;
        }

        private void button7_MouseHover(object sender, EventArgs e)
        {
            button7.Width = 145;
            button7.Height = 173;
        }

        private void button11_Click(object sender, EventArgs e)
        {
            Wiki wk = new Wiki();
            wk.Show();
        }
    }
}
