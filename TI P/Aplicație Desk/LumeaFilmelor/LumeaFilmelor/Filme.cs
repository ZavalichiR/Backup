using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace LumeaFilmelor
{
    public partial class Filme : Form
    {
        List<Film> film;
        int i;
        int dim;
        string startupPath = System.IO.Directory.GetCurrentDirectory();
        
        string url;


        public Filme()
        {
            InitializeComponent();

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

            i = 0;
            label1.Text = film[i].getTitlu();
            richTextBox2.Text = film[0].getDescriere();
            button7.Text = "";
            startupPath = startupPath.Substring(0, startupPath.LastIndexOf('\\'));
            startupPath = startupPath.Substring(0, startupPath.LastIndexOf('\\'));
            url = film[i].getImagine().Replace("/", "\\");
            button7.Image = Image.FromFile(startupPath + "\\" + url);

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
            button7.Width = 145;
            button7.Height = 173;
        }

        private void button7_MouseLeave(object sender, EventArgs e)
        {
            button7.Width = 135;
            button7.Height = 163;
        }

        private void button9_Click(object sender, EventArgs e)
        {
            i--;
            if(i< film.Count())
            {
                i = film.Count();
            }
            
            label1.Text = film[i].getTitlu();
            richTextBox2.Text = film[i].getDescriere();
            button7.Text = "";
            url = film[i].getImagine().Replace("/", "\\");
            button7.Image.Dispose();
            button7.Image = Image.FromFile(startupPath + "\\" + url);

        }

        private void button8_Click(object sender, EventArgs e)
        {
            i++;
            if(i>film.Count()-1)
            {
                i = 0;
            }
            label1.Text = film[i].getTitlu();
            richTextBox2.Text = film[i].getDescriere();
            button7.Text = "";
            url = film[i].getImagine().Replace("/", "\\");
            button7.Image.Dispose();
            button7.Image = Image.FromFile(startupPath + "\\" + url);

        }

        private void button7_Click(object sender, EventArgs e)
        {
            DespreFilm form = new DespreFilm(film[i]);
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
