using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;
using System.Net;
using System.Text;
using System.Windows.Forms;
using Newtonsoft.Json;
using System.Drawing;

namespace LumeaFilmelor
{
    public partial class Form1 : Form
    {
        private List<Film> film;
        public Form1()
        {
            InitializeComponent();
            this.MouseWheel += new MouseEventHandler(Panel1_MouseWheel);

            panel1.AutoScroll = false;
            //panel1.AutoScrollMinSize = new AutoScrollMinSize(0, 1000);
            panel1.VerticalScroll.Enabled = true;
            panel1.VerticalScroll.Visible = true;

            panel1.AutoScroll = true;


            // Create a request for the URL. 		
            WebRequest request = WebRequest.Create("http://localhost:8080/LumeaFilmelorWebServices/api/filme");
            // If required by the server, set the credentials.
            request.Credentials = CredentialCache.DefaultCredentials;
            // Get the response.
            HttpWebResponse response = (HttpWebResponse)request.GetResponse();
            // Display the status.
            Console.WriteLine(response.StatusDescription);
            // Get the stream containing content returned by the server.
            Stream dataStream = response.GetResponseStream();
            // Open the stream using a StreamReader for easy access.
            StreamReader reader = new StreamReader(dataStream);
            // Read the content.
            string responseFromServer = reader.ReadToEnd();
            // Display the content.
            Console.WriteLine(responseFromServer);
            // Cleanup the streams and the response.
            reader.Close();
            dataStream.Close();
            response.Close();

            film = JsonConvert.DeserializeObject<List<Film>>(responseFromServer);
            string startupPath = System.IO.Directory.GetCurrentDirectory();
            startupPath = startupPath.Substring(0, startupPath.LastIndexOf('\\'));
            startupPath = startupPath.Substring(0, startupPath.LastIndexOf('\\'));
            string url;

            //Filmul anului
            button7.Text = "";
            url = film[0].getImagine().Replace("/", "\\");
            button7.Image = Image.FromFile(startupPath + "\\" + url);
            richTextBox2.Text = film[0].getDescriere();

            //Film 1
            button8.Text = "";
            label1.Text = film[1].getTitlu();
            url = film[1].getImagine().Replace("/", "\\");
            button8.Image = Image.FromFile(startupPath + "\\" + url);
            richTextBox3.Text = film[0].getDescriere();
            //Film 2
            button9.Text = "";
            label2.Text = film[2].getTitlu();
            url = film[2].getImagine().Replace("/", "\\");
            button9.Image = Image.FromFile(startupPath + "\\" + url);
            richTextBox4.Text = film[0].getDescriere();
            //Film 3

            label3.Text = film[3].getTitlu();
            button10.Text = "";
            url = film[3].getImagine().Replace("/", "\\");
            button10.Image = Image.FromFile(startupPath + "\\" + url);
            richTextBox5.Text = film[0].getDescriere();
        }

        private void Panel1_MouseWheel(object sender, MouseEventArgs e)
        {
            panel1.Focus();
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
            Detalii form = new Detalii();
            form.Show();
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

        private void button7_MouseHover(object sender, EventArgs e)
        {
            button7.Width = 174;
            button7.Height = 220;
        }

        private void button7_MouseLeave(object sender, EventArgs e)
        {
            button7.Width = 164;
            button7.Height = 210;
        }

        private void button8_MouseHover(object sender, EventArgs e)
        {
            button8.Width = 145;
            button8.Height = 198;

        }

        private void button8_MouseLeave(object sender, EventArgs e)
        {
            button8.Width = 135;
            button8.Height = 188;
        }

        private void button9_MouseHover(object sender, EventArgs e)
        {
            button9.Width = 145;
            button9.Height = 198;
        }

        private void button9_MouseLeave(object sender, EventArgs e)
        {
            button9.Width = 135;
            button9.Height = 188;
        }

        private void button10_MouseHover(object sender, EventArgs e)
        {
            button10.Width = 145;
            button10.Height = 198;
        }

        private void button10_MouseLeave(object sender, EventArgs e)
        {
            button10.Width = 135;
            button10.Height = 188;
        }

        private void button7_Click(object sender, EventArgs e)
        {
            DespreFilm form = new DespreFilm(film[0]);
            this.Hide();
            form.Show();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            DespreFilm form = new DespreFilm(film[1]);
            this.Hide();
            form.Show();
        }

        private void button9_Click(object sender, EventArgs e)
        {
            DespreFilm form = new DespreFilm(film[2]);
            this.Hide();
            form.Show();
        }

        private void button10_Click(object sender, EventArgs e)
        {
            DespreFilm form = new DespreFilm(film[3]);
            this.Hide();
            form.Show();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            Wiki wk = new Wiki();
            wk.Show();
        }
    }
}
