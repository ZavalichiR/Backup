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

namespace VectorSortThread
{
    public partial class SortVect : Form
    {
        int[] vector = { 11, 8, 75, 5, 22, 129, 9, 6, 4, 1024, 1};
        int dim = 11;
        StreamWriter fisierOut = new StreamWriter(new FileStream("Rezultat.out", FileMode.Create));
        public SortVect()
        {
            InitializeComponent();
            richTextBox1.Text = "Vectorul initial\n";
            for (int i = 0; i < dim; ++i)
            {
                richTextBox1.AppendText(Convert.ToString(vector[i]) + ", ");
            }
        }



       
        public void Sort(int[] vector, int left, int right)
        {
            int mid;
            if (right > left)
            {
                mid = (right + left) / 2;
                Thread t1 = new Thread(() => Sort(vector, left, mid));
                Thread t2 = new Thread(() => Sort(vector, (mid + 1), right));
                t1.Start();
                t2.Start();
                t1.Join();
                t2.Join();
                MergeSort(vector, left, mid, right);
                
            }
        }

        public void MergeSort(int[] vector, int left, int mid, int right)
        {
            int[] temp = new int[37];
            int h, i, j, k;
            h = left;
            i = left;
            j = mid + 1;

            while ((h <= mid) && (j <= right))
            {
                if (vector[h] <= vector[j])
                {
                    temp[i] = vector[h];
                    h++;
                }
                else
                {
                    temp[i] = vector[j];
                    j++;
                }
                i++;
            }

            if (h > mid)
            {
                for (k = j; k <= right; k++)
                {
                    temp[i] = vector[k];
                    i++;
                }
            }
            else
            {
                for (k = h; k <= mid; k++)
                {
                    temp[i] = vector[k];
                    i++;
                }
            }

            string v = "";
            for (k = left; k <= right; k++)
            {
                vector[k] = temp[k];
                v = v + vector[k]+" ";
                
            }
            lock (fisierOut)
            {
                Thread.Sleep(500);
                listBox1.Items.Add(v);
            }
        }


        private void button1_Click_1(object sender, EventArgs e)
        {
            
            Sort(vector, 0, dim - 1);

            string v = " ";
            for (int i = 0; i < dim; ++i)
            {
                v+= vector[i] + " ";
            }
            richTextBox2.AppendText(Convert.ToString("Vectorul sortat\n"+v));
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
