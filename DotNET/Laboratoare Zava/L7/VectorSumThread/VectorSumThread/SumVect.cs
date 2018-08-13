using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VectorSumThread
{
    public partial class SumVect : Form
    {
        public int[] vector;
        public int milliseconds = 2000;
        public SumVect()
        {
            InitializeComponent();
            int dim = 20;
            vector = new int[dim];
            int i;
            for (i = 0; i < dim; ++i)
            {
                vector[i] = i + 1;
                richTextBox1.AppendText(Convert.ToString(vector[i]) + ", ");
            }
        }

        
        
        public void Sum(StreamWriter fisierOut)
        {
            int dim = vector.Length;
            int nrThreads = 0;
            bool ok = false;
            int i = 0;

            if (dim % 2 == 1)
            {
                ok = true;
            }
            do
            {
                nrThreads = dim / 2;
                Thread[] thread = new Thread[nrThreads + 1];

                for (i = 0; i < nrThreads; ++i)
                {
                    int a = vector[2 * i];
                    int b = vector[2 * i + 1];
                    thread[i] = new Thread(() => Sum(a, b, i, fisierOut));
                    thread[i].Start();
                }
                for (i = 0; i < nrThreads; ++i)
                {
                    thread[i].Join(); // suspenda firul principal pana celalalt isi termina executia
                }

                if (ok)
                {
                    int a = vector[2 * i];
                    thread[i] = new Thread(() => Sum(a, 0, i, fisierOut));
                    thread[i].Start();
                    thread[i].Join();

                    dim = dim / 2 + 1;

                    if (dim % 2 == 0)
                    {
                        ok = false;
                    }

                }
                else
                {
                    dim = dim / 2;
                    if (dim % 2 == 1)
                    {
                        ok = true;
                    }
                }

            } while (dim > 1);


        }

        public void Sum(int a, int b, int index, StreamWriter fisierOut)
        {
            int result = a + b;
            vector[index] = result;

            lock (fisierOut)
            {
                Thread.Sleep(200);
                listBox1.Items.Add("Index("+ index +"): "+a+"+"+b+"="+result);
            }
        }

        private void SumVect_Load(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {

            textBox1.Text = "Verificati fisierul Rezultat.out";
            StreamWriter fisierOut = new StreamWriter(new FileStream("Rezultat.out", FileMode.Create));
            Sum(fisierOut);
            fisierOut.Close();

            
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
