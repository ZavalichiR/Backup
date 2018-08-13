using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Data.SqlClient;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Excel
{

    public partial class Form1 : Form
    {
        
        private string constr = @"Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\zzava\Desktop\Semestrul II\SD\L9\Excel\Excel\Excel.mdf;Integrated Security=True";
        private string poz;
        private FontStyle stil;
        private string font;
        private Int32 dim = 9;
        private Color Fcolor;
        private Color Bcolor;
        private object obiectSelectat;
        private struct Celula
        {
            public string Ctext;
            public FontStyle Cstil;
            public Int32 Cdim;
            public string Cfont;
            public Color Fcolor;
            public Color Bcolor;
        }
        private struct Number
        {
            public string A;
            public string B;
        }
        private Celula[] cell = new Celula[81];
        private string[] Cell=new string[81];
        
        public Form1()
        {
            InitializeComponent();
            for(int i=1; i<81; ++i)
            {
                Cell[i]="";

                cell[i].Ctext = "";
                cell[i].Cdim = 9;
                cell[i].Cfont = "Microsoft Sans Serif";
                cell[i].Cstil = FontStyle.Regular;
                cell[i].Fcolor = Color.Black;
                cell[i].Bcolor = Color.White;

            }

            Update();

        }

        private void richTextBox_TextChanged(object sender, EventArgs e)
        {
            
            richTextBox82.Clear();
            richTextBox82.Text = sender.ToString().Substring(40);
            string text = richTextBox82.Text;
            
            //=A1+A1
            if(text.Length==6 && text[0].Equals('='))
            {
                richTextBox82.Text = "merge";
                functie(text);
                
            }
            
            obiectSelectat = sender;
            poz= ((RichTextBox)sender).Name.ToString().Substring(11);

            Cell[Convert.ToInt16(poz)] = richTextBox82.Text;

            cell[Convert.ToInt16(poz)].Ctext = richTextBox82.Text;
            

        }

        private void richTextBox_MouseClick(object sender, MouseEventArgs e)
        {
            obiectSelectat = sender;
            richTextBox82.Clear();
            richTextBox82.Text = sender.ToString().Substring(40);
            string text = richTextBox82.Text;
            if (text.Length == 6 && text[0].Equals('='))
            {
                richTextBox82.Text = "merge";
                functie(text);

            }
            ((RichTextBox)sender).BorderStyle =BorderStyle.Fixed3D;
            //richTextBox82.Text = ((RichTextBox)sender).Name.ToString().Substring(11);


        }
        private void richTextBox_MouseLeave(object sender, EventArgs e)
        {
            ((RichTextBox)sender).BorderStyle = BorderStyle.None;     
        }


        private void listBox1_SelectedValueChanged(object sender, EventArgs e)
        {

            font = listBox1.GetItemText(listBox1.SelectedItem);
            if(((RichTextBox)obiectSelectat).SelectionFont!=null)
                ((RichTextBox)obiectSelectat).SelectionFont = new Font(font, dim, FontStyle.Regular);

            cell[Convert.ToInt16(poz)].Cfont = font;
        }
        private void listBox2_SelectedValueChanged(object sender, EventArgs e)
        {
            Int16 dim2 = Convert.ToInt16(listBox2.GetItemText(listBox2.SelectedItem));
            if (((RichTextBox)obiectSelectat).SelectionFont != null)
                ((RichTextBox)obiectSelectat).SelectionFont = new Font(font, dim2, FontStyle.Regular);

            cell[Convert.ToInt16(poz)].Cdim = dim2;
        }

        // B
        private void button1_Click(object sender, EventArgs e)
        {
          
            //((RichTextBox)sender).SelectionColor = Color.Red;
            stil = FontStyle.Bold;
            if (((RichTextBox)obiectSelectat).SelectionFont != null)
                ((RichTextBox)obiectSelectat).SelectionFont = new Font(Font,FontStyle.Bold);

            cell[Convert.ToInt16(poz)].Cstil = stil;
        }

        // I
        private void button20_Click(object sender, EventArgs e)
        {
            stil = FontStyle.Italic;
            if (((RichTextBox)obiectSelectat).SelectionFont != null)
                ((RichTextBox)obiectSelectat).SelectionFont = new Font(Font, FontStyle.Italic);
            cell[Convert.ToInt16(poz)].Cstil = stil;
        }

        //U
        private void button21_Click(object sender, EventArgs e)
        {
            stil = FontStyle.Underline;
            if (((RichTextBox)obiectSelectat).SelectionFont != null)
                ((RichTextBox)obiectSelectat).SelectionFont = new Font(Font, FontStyle.Underline);
            cell[Convert.ToInt16(poz)].Cstil = stil;
        }

        //Font
        private void button25_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                button25.BackColor = colorDialog1.Color;
                Bcolor = colorDialog1.Color;
                if(Bcolor==Color.Black)
                {
                    button25.ForeColor = Color.White;
                }
                else
                {
                    button25.ForeColor = Color.Black;
                }
                ((RichTextBox)obiectSelectat).BackColor = Bcolor;
                cell[Convert.ToInt16(poz)].Bcolor = Bcolor;
            }
        }

        //BackColor
        private void button22_Click(object sender, EventArgs e)
        {
            if (colorDialog1.ShowDialog() == DialogResult.OK)
            {
                button22.ForeColor = colorDialog1.Color;
                Fcolor = colorDialog1.Color;
                if (Fcolor == Color.White)
                {
                    button22.BackColor = Color.Black;
                }
                else
                {
                    button22.BackColor = Color.White;
                }
               ((RichTextBox)obiectSelectat).ForeColor = Fcolor;
                cell[Convert.ToInt16(poz)].Fcolor = Fcolor;
            }
        }

        
        private void button2_Click(object sender, EventArgs e)
        {
            if (richTextBox1.BackColor == System.Drawing.Color.White)
            {
                richTextBox1.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox2.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox3.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox4.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox5.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox6.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox7.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox8.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox9.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox10.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox1.BackColor = System.Drawing.Color.White;
                richTextBox2.BackColor = System.Drawing.Color.White;
                richTextBox3.BackColor = System.Drawing.Color.White;
                richTextBox4.BackColor = System.Drawing.Color.White;
                richTextBox5.BackColor = System.Drawing.Color.White;
                richTextBox6.BackColor = System.Drawing.Color.White;
                richTextBox7.BackColor = System.Drawing.Color.White;
                richTextBox8.BackColor = System.Drawing.Color.White;
                richTextBox9.BackColor = System.Drawing.Color.White;
                richTextBox10.BackColor = System.Drawing.Color.White;
            }
            
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (richTextBox11.BackColor == System.Drawing.Color.White)
            {
                richTextBox11.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox12.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox13.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox14.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox15.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox16.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox17.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox18.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox19.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox20.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox11.BackColor = System.Drawing.Color.White;
                richTextBox12.BackColor = System.Drawing.Color.White;
                richTextBox13.BackColor = System.Drawing.Color.White;
                richTextBox14.BackColor = System.Drawing.Color.White;
                richTextBox15.BackColor = System.Drawing.Color.White;
                richTextBox16.BackColor = System.Drawing.Color.White;
                richTextBox17.BackColor = System.Drawing.Color.White;
                richTextBox18.BackColor = System.Drawing.Color.White;
                richTextBox19.BackColor = System.Drawing.Color.White;
                richTextBox20.BackColor = System.Drawing.Color.White;
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (richTextBox21.BackColor == System.Drawing.Color.White)
            {
                richTextBox21.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox22.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox23.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox24.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox25.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox26.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox27.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox28.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox29.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox30.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox21.BackColor = System.Drawing.Color.White;
                richTextBox22.BackColor = System.Drawing.Color.White;
                richTextBox23.BackColor = System.Drawing.Color.White;
                richTextBox24.BackColor = System.Drawing.Color.White;
                richTextBox25.BackColor = System.Drawing.Color.White;
                richTextBox26.BackColor = System.Drawing.Color.White;
                richTextBox27.BackColor = System.Drawing.Color.White;
                richTextBox28.BackColor = System.Drawing.Color.White;
                richTextBox29.BackColor = System.Drawing.Color.White;
                richTextBox30.BackColor = System.Drawing.Color.White;
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (richTextBox31.BackColor == System.Drawing.Color.White)
            {
                richTextBox31.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox32.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox33.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox34.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox35.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox36.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox37.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox38.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox39.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox40.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox31.BackColor = System.Drawing.Color.White;
                richTextBox32.BackColor = System.Drawing.Color.White;
                richTextBox33.BackColor = System.Drawing.Color.White;
                richTextBox34.BackColor = System.Drawing.Color.White;
                richTextBox35.BackColor = System.Drawing.Color.White;
                richTextBox36.BackColor = System.Drawing.Color.White;
                richTextBox37.BackColor = System.Drawing.Color.White;
                richTextBox38.BackColor = System.Drawing.Color.White;
                richTextBox39.BackColor = System.Drawing.Color.White;
                richTextBox40.BackColor = System.Drawing.Color.White;
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            if (richTextBox41.BackColor == System.Drawing.Color.White)
            {
                richTextBox41.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox42.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox43.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox44.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox45.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox46.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox47.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox48.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox49.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox50.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox41.BackColor = System.Drawing.Color.White;
                richTextBox42.BackColor = System.Drawing.Color.White;
                richTextBox43.BackColor = System.Drawing.Color.White;
                richTextBox44.BackColor = System.Drawing.Color.White;
                richTextBox45.BackColor = System.Drawing.Color.White;
                richTextBox46.BackColor = System.Drawing.Color.White;
                richTextBox47.BackColor = System.Drawing.Color.White;
                richTextBox48.BackColor = System.Drawing.Color.White;
                richTextBox49.BackColor = System.Drawing.Color.White;
                richTextBox50.BackColor = System.Drawing.Color.White;
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            if (richTextBox51.BackColor == System.Drawing.Color.White)
            {
                richTextBox51.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox52.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox53.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox54.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox55.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox56.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox57.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox58.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox59.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox60.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox51.BackColor = System.Drawing.Color.White;
                richTextBox52.BackColor = System.Drawing.Color.White;
                richTextBox53.BackColor = System.Drawing.Color.White;
                richTextBox54.BackColor = System.Drawing.Color.White;
                richTextBox55.BackColor = System.Drawing.Color.White;
                richTextBox56.BackColor = System.Drawing.Color.White;
                richTextBox57.BackColor = System.Drawing.Color.White;
                richTextBox58.BackColor = System.Drawing.Color.White;
                richTextBox59.BackColor = System.Drawing.Color.White;
                richTextBox60.BackColor = System.Drawing.Color.White;
            }
        }

        private void button8_Click(object sender, EventArgs e)
        {
            if (richTextBox61.BackColor == System.Drawing.Color.White)
            {
                richTextBox61.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox62.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox63.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox64.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox65.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox66.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox67.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox68.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox69.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox70.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox61.BackColor = System.Drawing.Color.White;
                richTextBox62.BackColor = System.Drawing.Color.White;
                richTextBox63.BackColor = System.Drawing.Color.White;
                richTextBox64.BackColor = System.Drawing.Color.White;
                richTextBox65.BackColor = System.Drawing.Color.White;
                richTextBox66.BackColor = System.Drawing.Color.White;
                richTextBox67.BackColor = System.Drawing.Color.White;
                richTextBox68.BackColor = System.Drawing.Color.White;
                richTextBox69.BackColor = System.Drawing.Color.White;
                richTextBox70.BackColor = System.Drawing.Color.White;
            }
        }

        private void button9_Click(object sender, EventArgs e)
        {
            if (richTextBox71.BackColor == System.Drawing.Color.White)
            {
                richTextBox71.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox72.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox73.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox74.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox75.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox76.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox77.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox78.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox79.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox80.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox71.BackColor = System.Drawing.Color.White;
                richTextBox72.BackColor = System.Drawing.Color.White;
                richTextBox73.BackColor = System.Drawing.Color.White;
                richTextBox74.BackColor = System.Drawing.Color.White;
                richTextBox75.BackColor = System.Drawing.Color.White;
                richTextBox76.BackColor = System.Drawing.Color.White;
                richTextBox77.BackColor = System.Drawing.Color.White;
                richTextBox78.BackColor = System.Drawing.Color.White;
                richTextBox79.BackColor = System.Drawing.Color.White;
                richTextBox80.BackColor = System.Drawing.Color.White;
            }
        }

        private void button10_Click(object sender, EventArgs e)
        {
            if (richTextBox1.BackColor == System.Drawing.Color.White)
            {
                richTextBox1.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox11.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox21.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox31.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox41.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox51.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox61.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox71.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox1.BackColor = System.Drawing.Color.White;
                richTextBox11.BackColor = System.Drawing.Color.White;
                richTextBox21.BackColor = System.Drawing.Color.White;
                richTextBox31.BackColor = System.Drawing.Color.White;
                richTextBox41.BackColor = System.Drawing.Color.White;
                richTextBox51.BackColor = System.Drawing.Color.White;
                richTextBox61.BackColor = System.Drawing.Color.White;
                richTextBox71.BackColor = System.Drawing.Color.White;

            }
        }

        private void button11_Click(object sender, EventArgs e)
        {
            if (richTextBox2.BackColor == System.Drawing.Color.White)
            {
                richTextBox2.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox12.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox22.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox32.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox42.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox52.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox62.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox72.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox2.BackColor = System.Drawing.Color.White;
                richTextBox12.BackColor = System.Drawing.Color.White;
                richTextBox22.BackColor = System.Drawing.Color.White;
                richTextBox32.BackColor = System.Drawing.Color.White;
                richTextBox42.BackColor = System.Drawing.Color.White;
                richTextBox52.BackColor = System.Drawing.Color.White;
                richTextBox62.BackColor = System.Drawing.Color.White;
                richTextBox72.BackColor = System.Drawing.Color.White;

            }
        }

        private void button12_Click(object sender, EventArgs e)
        {
            if (richTextBox3.BackColor == System.Drawing.Color.White)
            {
                richTextBox3.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox13.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox23.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox33.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox43.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox53.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox63.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox73.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox3.BackColor = System.Drawing.Color.White;
                richTextBox13.BackColor = System.Drawing.Color.White;
                richTextBox23.BackColor = System.Drawing.Color.White;
                richTextBox33.BackColor = System.Drawing.Color.White;
                richTextBox43.BackColor = System.Drawing.Color.White;
                richTextBox53.BackColor = System.Drawing.Color.White;
                richTextBox63.BackColor = System.Drawing.Color.White;
                richTextBox73.BackColor = System.Drawing.Color.White;

            }
        }

        private void button13_Click(object sender, EventArgs e)
        {
            if (richTextBox4.BackColor == System.Drawing.Color.White)
            {
                richTextBox4.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox14.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox24.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox34.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox44.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox54.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox64.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox74.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox4.BackColor = System.Drawing.Color.White;
                richTextBox14.BackColor = System.Drawing.Color.White;
                richTextBox24.BackColor = System.Drawing.Color.White;
                richTextBox34.BackColor = System.Drawing.Color.White;
                richTextBox44.BackColor = System.Drawing.Color.White;
                richTextBox54.BackColor = System.Drawing.Color.White;
                richTextBox64.BackColor = System.Drawing.Color.White;
                richTextBox74.BackColor = System.Drawing.Color.White;

            }
        }

        private void button14_Click(object sender, EventArgs e)
        {
            if (richTextBox5.BackColor == System.Drawing.Color.White)
            {
                richTextBox5.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox15.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox25.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox35.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox45.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox55.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox65.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox75.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox5.BackColor = System.Drawing.Color.White;
                richTextBox15.BackColor = System.Drawing.Color.White;
                richTextBox25.BackColor = System.Drawing.Color.White;
                richTextBox35.BackColor = System.Drawing.Color.White;
                richTextBox45.BackColor = System.Drawing.Color.White;
                richTextBox55.BackColor = System.Drawing.Color.White;
                richTextBox65.BackColor = System.Drawing.Color.White;
                richTextBox75.BackColor = System.Drawing.Color.White;

            }
        }

        private void button15_Click(object sender, EventArgs e)
        {
            if (richTextBox6.BackColor == System.Drawing.Color.White)
            {
                richTextBox6.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox16.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox26.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox36.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox46.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox56.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox66.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox76.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox6.BackColor = System.Drawing.Color.White;
                richTextBox16.BackColor = System.Drawing.Color.White;
                richTextBox26.BackColor = System.Drawing.Color.White;
                richTextBox36.BackColor = System.Drawing.Color.White;
                richTextBox46.BackColor = System.Drawing.Color.White;
                richTextBox56.BackColor = System.Drawing.Color.White;
                richTextBox66.BackColor = System.Drawing.Color.White;
                richTextBox76.BackColor = System.Drawing.Color.White;

            }
        }

        private void button16_Click(object sender, EventArgs e)
        {
            if (richTextBox7.BackColor == System.Drawing.Color.White)
            {
                richTextBox7.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox17.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox27.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox37.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox47.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox57.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox67.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox77.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox7.BackColor = System.Drawing.Color.White;
                richTextBox17.BackColor = System.Drawing.Color.White;
                richTextBox27.BackColor = System.Drawing.Color.White;
                richTextBox37.BackColor = System.Drawing.Color.White;
                richTextBox47.BackColor = System.Drawing.Color.White;
                richTextBox57.BackColor = System.Drawing.Color.White;
                richTextBox67.BackColor = System.Drawing.Color.White;
                richTextBox77.BackColor = System.Drawing.Color.White;

            }
        }

        private void button17_Click(object sender, EventArgs e)
        {
            if (richTextBox8.BackColor == System.Drawing.Color.White)
            {
                richTextBox8.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox18.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox28.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox38.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox48.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox58.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox68.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox78.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox8.BackColor = System.Drawing.Color.White;
                richTextBox18.BackColor = System.Drawing.Color.White;
                richTextBox28.BackColor = System.Drawing.Color.White;
                richTextBox38.BackColor = System.Drawing.Color.White;
                richTextBox48.BackColor = System.Drawing.Color.White;
                richTextBox58.BackColor = System.Drawing.Color.White;
                richTextBox68.BackColor = System.Drawing.Color.White;
                richTextBox78.BackColor = System.Drawing.Color.White;

            }
        }

        private void button18_Click(object sender, EventArgs e)
        {
            if (richTextBox9.BackColor == System.Drawing.Color.White)
            {
                richTextBox9.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox19.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox29.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox39.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox49.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox59.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox69.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox79.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox9.BackColor = System.Drawing.Color.White;
                richTextBox19.BackColor = System.Drawing.Color.White;
                richTextBox29.BackColor = System.Drawing.Color.White;
                richTextBox39.BackColor = System.Drawing.Color.White;
                richTextBox49.BackColor = System.Drawing.Color.White;
                richTextBox59.BackColor = System.Drawing.Color.White;
                richTextBox69.BackColor = System.Drawing.Color.White;
                richTextBox79.BackColor = System.Drawing.Color.White;

            }
        }

        private void button19_Click(object sender, EventArgs e)
        {
            if (richTextBox10.BackColor == System.Drawing.Color.White)
            {
                richTextBox10.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox20.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox30.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox40.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox50.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox60.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox70.BackColor = System.Drawing.Color.Gainsboro;
                richTextBox80.BackColor = System.Drawing.Color.Gainsboro;
            }
            else
            {
                richTextBox10.BackColor = System.Drawing.Color.White;
                richTextBox20.BackColor = System.Drawing.Color.White;
                richTextBox30.BackColor = System.Drawing.Color.White;
                richTextBox40.BackColor = System.Drawing.Color.White;
                richTextBox50.BackColor = System.Drawing.Color.White;
                richTextBox60.BackColor = System.Drawing.Color.White;
                richTextBox70.BackColor = System.Drawing.Color.White;
                richTextBox80.BackColor = System.Drawing.Color.White;

            }
        }

        private void UpdateCellText()
        {
            richTextBox1.Text = cell[1].Ctext;
            richTextBox2.Text = cell[2].Ctext;
            richTextBox3.Text = cell[3].Ctext;
            richTextBox4.Text = cell[4].Ctext;
            richTextBox5.Text = cell[5].Ctext;
            richTextBox6.Text = cell[6].Ctext;
            richTextBox7.Text = cell[7].Ctext;
            richTextBox8.Text = cell[8].Ctext;
            richTextBox9.Text = cell[9].Ctext;
            richTextBox10.Text = cell[10].Ctext;
            richTextBox11.Text = cell[11].Ctext;
            richTextBox12.Text = cell[12].Ctext;
            richTextBox13.Text = cell[13].Ctext;
            richTextBox14.Text = cell[14].Ctext;
            richTextBox15.Text = cell[15].Ctext;
            richTextBox16.Text = cell[16].Ctext;
            richTextBox17.Text = cell[17].Ctext;
            richTextBox18.Text = cell[18].Ctext;
            richTextBox19.Text = cell[19].Ctext;
            richTextBox20.Text = cell[20].Ctext;
            richTextBox21.Text = cell[21].Ctext;
            richTextBox22.Text = cell[22].Ctext;
            richTextBox23.Text = cell[23].Ctext;
            richTextBox24.Text = cell[24].Ctext;
            richTextBox25.Text = cell[25].Ctext;
            richTextBox26.Text = cell[26].Ctext;
            richTextBox27.Text = cell[27].Ctext;
            richTextBox28.Text = cell[28].Ctext;
            richTextBox29.Text = cell[29].Ctext;
            richTextBox30.Text = cell[30].Ctext;
            richTextBox31.Text = cell[31].Ctext;
            richTextBox32.Text = cell[32].Ctext;
            richTextBox33.Text = cell[33].Ctext;
            richTextBox34.Text = cell[34].Ctext;
            richTextBox35.Text = cell[35].Ctext;
            richTextBox36.Text = cell[36].Ctext;
            richTextBox37.Text = cell[37].Ctext;
            richTextBox38.Text = cell[38].Ctext;
            richTextBox39.Text = cell[39].Ctext;
            richTextBox40.Text = cell[40].Ctext;
            richTextBox41.Text = cell[41].Ctext;
            richTextBox42.Text = cell[42].Ctext;
            richTextBox43.Text = cell[43].Ctext;
            richTextBox44.Text = cell[44].Ctext;
            richTextBox45.Text = cell[45].Ctext;
            richTextBox46.Text = cell[46].Ctext;
            richTextBox47.Text = cell[47].Ctext;
            richTextBox48.Text = cell[48].Ctext;
            richTextBox49.Text = cell[49].Ctext;
            richTextBox50.Text = cell[50].Ctext;
            richTextBox51.Text = cell[51].Ctext;
            richTextBox52.Text = cell[52].Ctext;
            richTextBox53.Text = cell[53].Ctext;
            richTextBox54.Text = cell[54].Ctext;
            richTextBox55.Text = cell[55].Ctext;
            richTextBox56.Text = cell[56].Ctext;
            richTextBox57.Text = cell[57].Ctext;
            richTextBox58.Text = cell[58].Ctext;
            richTextBox59.Text = cell[59].Ctext;
            richTextBox60.Text = cell[60].Ctext;
            richTextBox61.Text = cell[61].Ctext;
            richTextBox62.Text = cell[62].Ctext;
            richTextBox63.Text = cell[63].Ctext;
            richTextBox64.Text = cell[64].Ctext;
            richTextBox65.Text = cell[65].Ctext;
            richTextBox66.Text = cell[66].Ctext;
            richTextBox67.Text = cell[67].Ctext;
            richTextBox68.Text = cell[68].Ctext;
            richTextBox69.Text = cell[69].Ctext;
            richTextBox70.Text = cell[70].Ctext;
            richTextBox71.Text = cell[71].Ctext;
            richTextBox72.Text = cell[72].Ctext;
            richTextBox73.Text = cell[73].Ctext;
            richTextBox74.Text = cell[74].Ctext;
            richTextBox75.Text = cell[75].Ctext;
            richTextBox76.Text = cell[76].Ctext;
            richTextBox77.Text = cell[77].Ctext;
            richTextBox78.Text = cell[78].Ctext;
            richTextBox79.Text = cell[79].Ctext;
            richTextBox80.Text = cell[80].Ctext;
        }
        private void UpdateCellFont()
        {
            richTextBox1.SelectionFont = new Font(cell[1].Cfont, cell[1].Cdim, cell[1].Cstil);
            richTextBox2.SelectionFont = new Font(cell[2].Cfont, cell[2].Cdim, cell[2].Cstil);
            richTextBox3.SelectionFont = new Font(cell[3].Cfont, cell[3].Cdim, cell[3].Cstil);
            richTextBox4.SelectionFont = new Font(cell[4].Cfont, cell[4].Cdim, cell[4].Cstil);
            richTextBox5.SelectionFont = new Font(cell[5].Cfont, cell[5].Cdim, cell[5].Cstil);
            richTextBox6.SelectionFont = new Font(cell[6].Cfont, cell[6].Cdim, cell[6].Cstil);
            richTextBox7.SelectionFont = new Font(cell[7].Cfont, cell[7].Cdim, cell[7].Cstil);
            richTextBox8.SelectionFont = new Font(cell[8].Cfont, cell[8].Cdim, cell[8].Cstil);
            richTextBox9.SelectionFont = new Font(cell[9].Cfont, cell[9].Cdim, cell[9].Cstil);
            richTextBox10.SelectionFont = new Font(cell[10].Cfont, cell[10].Cdim, cell[10].Cstil);
            richTextBox11.SelectionFont = new Font(cell[11].Cfont, cell[11].Cdim, cell[11].Cstil);
            richTextBox12.SelectionFont = new Font(cell[12].Cfont, cell[12].Cdim, cell[12].Cstil);
            richTextBox13.SelectionFont = new Font(cell[13].Cfont, cell[13].Cdim, cell[13].Cstil);
            richTextBox14.SelectionFont = new Font(cell[14].Cfont, cell[14].Cdim, cell[14].Cstil);
            richTextBox15.SelectionFont = new Font(cell[15].Cfont, cell[15].Cdim, cell[15].Cstil);
            richTextBox16.SelectionFont = new Font(cell[16].Cfont, cell[16].Cdim, cell[16].Cstil);
            richTextBox17.SelectionFont = new Font(cell[17].Cfont, cell[17].Cdim, cell[17].Cstil);
            richTextBox18.SelectionFont = new Font(cell[18].Cfont, cell[18].Cdim, cell[18].Cstil);
            richTextBox19.SelectionFont = new Font(cell[19].Cfont, cell[19].Cdim, cell[19].Cstil);
            richTextBox20.SelectionFont = new Font(cell[20].Cfont, cell[20].Cdim, cell[20].Cstil);
            richTextBox21.SelectionFont = new Font(cell[21].Cfont, cell[21].Cdim, cell[21].Cstil);
            richTextBox22.SelectionFont = new Font(cell[22].Cfont, cell[22].Cdim, cell[22].Cstil);
            richTextBox23.SelectionFont = new Font(cell[23].Cfont, cell[23].Cdim, cell[23].Cstil);
            richTextBox24.SelectionFont = new Font(cell[24].Cfont, cell[24].Cdim, cell[24].Cstil);
            richTextBox25.SelectionFont = new Font(cell[25].Cfont, cell[25].Cdim, cell[25].Cstil);
            richTextBox26.SelectionFont = new Font(cell[26].Cfont, cell[26].Cdim, cell[26].Cstil);
            richTextBox27.SelectionFont = new Font(cell[27].Cfont, cell[27].Cdim, cell[27].Cstil);
            richTextBox28.SelectionFont = new Font(cell[28].Cfont, cell[28].Cdim, cell[28].Cstil);
            richTextBox29.SelectionFont = new Font(cell[29].Cfont, cell[29].Cdim, cell[29].Cstil);
            richTextBox30.SelectionFont = new Font(cell[30].Cfont, cell[30].Cdim, cell[30].Cstil);
            richTextBox31.SelectionFont = new Font(cell[31].Cfont, cell[31].Cdim, cell[31].Cstil);
            richTextBox32.SelectionFont = new Font(cell[32].Cfont, cell[32].Cdim, cell[32].Cstil);
            richTextBox33.SelectionFont = new Font(cell[33].Cfont, cell[33].Cdim, cell[33].Cstil);
            richTextBox34.SelectionFont = new Font(cell[34].Cfont, cell[34].Cdim, cell[34].Cstil);
            richTextBox35.SelectionFont = new Font(cell[35].Cfont, cell[35].Cdim, cell[35].Cstil);
            richTextBox36.SelectionFont = new Font(cell[36].Cfont, cell[36].Cdim, cell[36].Cstil);
            richTextBox37.SelectionFont = new Font(cell[37].Cfont, cell[37].Cdim, cell[37].Cstil);
            richTextBox38.SelectionFont = new Font(cell[38].Cfont, cell[38].Cdim, cell[38].Cstil);
            richTextBox39.SelectionFont = new Font(cell[39].Cfont, cell[39].Cdim, cell[39].Cstil);
            richTextBox40.SelectionFont = new Font(cell[40].Cfont, cell[40].Cdim, cell[40].Cstil);
            richTextBox41.SelectionFont = new Font(cell[41].Cfont, cell[41].Cdim, cell[41].Cstil);
            richTextBox42.SelectionFont = new Font(cell[42].Cfont, cell[42].Cdim, cell[42].Cstil);
            richTextBox43.SelectionFont = new Font(cell[43].Cfont, cell[43].Cdim, cell[43].Cstil);
            richTextBox44.SelectionFont = new Font(cell[44].Cfont, cell[44].Cdim, cell[44].Cstil);
            richTextBox45.SelectionFont = new Font(cell[45].Cfont, cell[45].Cdim, cell[45].Cstil);
            richTextBox46.SelectionFont = new Font(cell[46].Cfont, cell[46].Cdim, cell[46].Cstil);
            richTextBox47.SelectionFont = new Font(cell[47].Cfont, cell[47].Cdim, cell[47].Cstil);
            richTextBox48.SelectionFont = new Font(cell[48].Cfont, cell[48].Cdim, cell[48].Cstil);
            richTextBox49.SelectionFont = new Font(cell[49].Cfont, cell[49].Cdim, cell[49].Cstil);
            richTextBox50.SelectionFont = new Font(cell[50].Cfont, cell[50].Cdim, cell[50].Cstil);
            richTextBox51.SelectionFont = new Font(cell[51].Cfont, cell[51].Cdim, cell[51].Cstil);
            richTextBox52.SelectionFont = new Font(cell[52].Cfont, cell[52].Cdim, cell[52].Cstil);
            richTextBox53.SelectionFont = new Font(cell[53].Cfont, cell[53].Cdim, cell[53].Cstil);
            richTextBox54.SelectionFont = new Font(cell[54].Cfont, cell[54].Cdim, cell[54].Cstil);
            richTextBox55.SelectionFont = new Font(cell[55].Cfont, cell[55].Cdim, cell[55].Cstil);
            richTextBox56.SelectionFont = new Font(cell[56].Cfont, cell[56].Cdim, cell[56].Cstil);
            richTextBox57.SelectionFont = new Font(cell[57].Cfont, cell[57].Cdim, cell[57].Cstil);
            richTextBox58.SelectionFont = new Font(cell[58].Cfont, cell[58].Cdim, cell[58].Cstil);
            richTextBox59.SelectionFont = new Font(cell[59].Cfont, cell[59].Cdim, cell[59].Cstil);
            richTextBox60.SelectionFont = new Font(cell[60].Cfont, cell[60].Cdim, cell[60].Cstil);
            richTextBox61.SelectionFont = new Font(cell[61].Cfont, cell[61].Cdim, cell[61].Cstil);
            richTextBox62.SelectionFont = new Font(cell[62].Cfont, cell[62].Cdim, cell[62].Cstil);
            richTextBox63.SelectionFont = new Font(cell[63].Cfont, cell[63].Cdim, cell[63].Cstil);
            richTextBox64.SelectionFont = new Font(cell[64].Cfont, cell[64].Cdim, cell[64].Cstil);
            richTextBox65.SelectionFont = new Font(cell[65].Cfont, cell[65].Cdim, cell[65].Cstil);
            richTextBox66.SelectionFont = new Font(cell[66].Cfont, cell[66].Cdim, cell[66].Cstil);
            richTextBox67.SelectionFont = new Font(cell[67].Cfont, cell[67].Cdim, cell[67].Cstil);
            richTextBox68.SelectionFont = new Font(cell[68].Cfont, cell[68].Cdim, cell[68].Cstil);
            richTextBox69.SelectionFont = new Font(cell[69].Cfont, cell[69].Cdim, cell[69].Cstil);
            richTextBox70.SelectionFont = new Font(cell[70].Cfont, cell[70].Cdim, cell[70].Cstil);
            richTextBox71.SelectionFont = new Font(cell[71].Cfont, cell[71].Cdim, cell[71].Cstil);
            richTextBox72.SelectionFont = new Font(cell[72].Cfont, cell[72].Cdim, cell[72].Cstil);
            richTextBox73.SelectionFont = new Font(cell[73].Cfont, cell[73].Cdim, cell[73].Cstil);
            richTextBox74.SelectionFont = new Font(cell[74].Cfont, cell[74].Cdim, cell[74].Cstil);
            richTextBox75.SelectionFont = new Font(cell[75].Cfont, cell[75].Cdim, cell[75].Cstil);
            richTextBox76.SelectionFont = new Font(cell[76].Cfont, cell[76].Cdim, cell[76].Cstil);
            richTextBox77.SelectionFont = new Font(cell[77].Cfont, cell[77].Cdim, cell[77].Cstil);
            richTextBox78.SelectionFont = new Font(cell[78].Cfont, cell[78].Cdim, cell[78].Cstil);
            richTextBox79.SelectionFont = new Font(cell[79].Cfont, cell[79].Cdim, cell[79].Cstil);
            richTextBox80.SelectionFont = new Font(cell[80].Cfont, cell[80].Cdim, cell[80].Cstil);
        }

        private void UpdateCell()
        {
            richTextBox1.Text = Cell[1];
            richTextBox2.Text = Cell[2];
            richTextBox3.Text = Cell[3];
            richTextBox4.Text = Cell[4];
            richTextBox5.Text = Cell[5];
            richTextBox6.Text = Cell[6];
            richTextBox7.Text = Cell[7];
            richTextBox8.Text = Cell[8];
            richTextBox9.Text = Cell[9];
            richTextBox10.Text = Cell[10];
            richTextBox11.Text = Cell[11];
            richTextBox12.Text = Cell[12];
            richTextBox13.Text = Cell[13];
            richTextBox14.Text = Cell[14];
            richTextBox15.Text = Cell[15];
            richTextBox16.Text = Cell[16];
            richTextBox17.Text = Cell[17];
            richTextBox18.Text = Cell[18];
            richTextBox19.Text = Cell[19];
            richTextBox20.Text = Cell[20];
            richTextBox21.Text = Cell[21];
            richTextBox22.Text = Cell[22];
            richTextBox23.Text = Cell[23];
            richTextBox24.Text = Cell[24];
            richTextBox25.Text = Cell[25];
            richTextBox26.Text = Cell[26];
            richTextBox27.Text = Cell[27];
            richTextBox28.Text = Cell[28];
            richTextBox29.Text = Cell[29];
            richTextBox30.Text = Cell[30];
            richTextBox31.Text = Cell[31];
            richTextBox32.Text = Cell[32];
            richTextBox33.Text = Cell[33];
            richTextBox34.Text = Cell[34];
            richTextBox35.Text = Cell[35];
            richTextBox36.Text = Cell[36];
            richTextBox37.Text = Cell[37];
            richTextBox38.Text = Cell[38];
            richTextBox39.Text = Cell[39];
            richTextBox40.Text = Cell[40];
            richTextBox41.Text = Cell[41];
            richTextBox42.Text = Cell[42];
            richTextBox43.Text = Cell[43];
            richTextBox44.Text = Cell[44];
            richTextBox45.Text = Cell[45];
            richTextBox46.Text = Cell[46];
            richTextBox47.Text = Cell[47];
            richTextBox48.Text = Cell[48];
            richTextBox49.Text = Cell[49];
            richTextBox50.Text = Cell[50];
            richTextBox51.Text = Cell[51];
            richTextBox52.Text = Cell[52];
            richTextBox53.Text = Cell[53];
            richTextBox54.Text = Cell[54];
            richTextBox55.Text = Cell[55];
            richTextBox56.Text = Cell[56];
            richTextBox57.Text = Cell[57];
            richTextBox58.Text = Cell[58];
            richTextBox59.Text = Cell[59];
            richTextBox60.Text = Cell[60];
            richTextBox61.Text = Cell[61];
            richTextBox62.Text = Cell[62];
            richTextBox63.Text = Cell[63];
            richTextBox64.Text = Cell[64];
            richTextBox65.Text = Cell[65];
            richTextBox66.Text = Cell[66];
            richTextBox67.Text = Cell[67];
            richTextBox68.Text = Cell[68];
            richTextBox69.Text = Cell[69];
            richTextBox70.Text = Cell[70];
            richTextBox71.Text = Cell[71];
            richTextBox72.Text = Cell[72];
            richTextBox73.Text = Cell[73];
            richTextBox74.Text = Cell[74];
            richTextBox75.Text = Cell[75];
            richTextBox76.Text = Cell[76];
            richTextBox77.Text = Cell[77];
            richTextBox78.Text = Cell[78];
            richTextBox79.Text = Cell[79];
            richTextBox80.Text = Cell[80];
        }

        private void Update()
        {
            
            SqlConnection con = new SqlConnection(constr);

            SqlCommand cmd = new SqlCommand("Select Cell,Font,Style,Dim from EXL", con);
            con.Open();

            SqlDataReader rdr = cmd.ExecuteReader();
            int i = 1;
            while (rdr.Read())
            {
                Cell[i] = rdr.GetString(0);

                cell[i].Ctext = rdr.GetString(0);
                cell[i].Cfont = rdr.GetString(1);
                string Cstil = rdr.GetString(2);
                switch (Cstil)
                {
                    case "Bold":
                        cell[i].Cstil = FontStyle.Bold;
                        break;
                    case "Regular":
                        cell[i].Cstil = FontStyle.Regular;
                        break;
                    case "Italic":
                        cell[i].Cstil = FontStyle.Italic;
                        break;

                }
                cell[i].Cdim = rdr.GetInt32(3);
                
                i++;
            }
            //UpdateCell();
            UpdateCellText();
            UpdateCellFont();
            
        }

        private void functie(string data)
        {
            char[] vect = data.ToCharArray();
            char op=' ';
            int indexop=0;
            string op1="";
            string op2="";
            int ok = 0;
            double result=0;
            double o1;
            double o2;
            Number nb = new Number();

            for (int i=1;i<vect.Length;++i)
            {
                if (vect[i] == '+' || vect[i] == '-' || vect[i] == '*' || vect[i] == '/')
                {
                    op = vect[i];
                    indexop = i;
                    op1 = data.Substring(1, indexop - 1);
                    op2 = data.Substring(indexop+1);
                    nb = getExp(op1,op2);
                    op1 = nb.A;
                    op2 = nb.B;
                    ok = 1;
                    break;
                }
            }
            if(ok==1)
            {
                if(validate(op1) && validate(op2))
                {
                    switch(op)
                    {

                        case '+':
                            if (Double.TryParse(op1, out o1) && Double.TryParse(op2, out o2))
                                result = o1 + o2;
                            break;
                        case '-':
                            if (Double.TryParse(op1, out o1) && Double.TryParse(op2, out o2))
                                result = o1 - o2;
                            break;
                        case '*':
                            if (Double.TryParse(op1, out o1) && Double.TryParse(op2, out o2))
                                result = o1 * o2;
                            break;
                        case '/':
                            if (Double.TryParse(op1, out o1) && Double.TryParse(op2, out o2))
                                result = o1 / o2;
                            result = Math.Round(result, 2);
                            break;
                        default:
                            break;
                    }
                }

                richTextBox82.Text = data;
                ((RichTextBox)obiectSelectat).Text = Convert.ToString(result);
            }
            else
            {
                ((RichTextBox)obiectSelectat).Text = "!VALUE";
            }
            
         }
        private bool validate(string data)
        {
            string regex = "^(0|([1-9][0-9]*))(\\.[0-9]+)?$";
            if (Regex.IsMatch(data, regex))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        private Number getExp(string a,string b)
        {
            Number nb = new Number();
            switch(a)
            {
                case "A1":
                    nb.A = richTextBox1.Text;
                    break;
                case "A2":
                    nb.A = richTextBox11.Text;
                    break;
                case "A3":
                    nb.A = richTextBox21.Text;
                    break;
                case "A4":
                    nb.A = richTextBox31.Text;
                    break;
                case "A5":
                    nb.A = richTextBox41.Text;
                    break;
                case "A6":
                    nb.A = richTextBox51.Text;
                    break;
                case "A7":
                    nb.A = richTextBox61.Text;
                    break;
                case "A8":
                    nb.A = richTextBox71.Text;
                    break;
                case "B1":
                    nb.A = richTextBox2.Text;
                    break;
                case "B2":
                    nb.A = richTextBox12.Text;
                    break;
                case "B3":
                    nb.A = richTextBox22.Text;
                    break;
                case "B4":
                    nb.A = richTextBox32.Text;
                    break;
                case "B5":
                    nb.A = richTextBox42.Text;
                    break;
                case "B6":
                    nb.A = richTextBox52.Text;
                    break;
                case "B7":
                    nb.A = richTextBox62.Text;
                    break;
                case "B8":
                    nb.A = richTextBox72.Text;
                    break;
                default:
                    break;
            }

            switch (b)
            {
                case "A1":
                    nb.B = richTextBox1.Text;
                    break;
                case "A2":
                    nb.B = richTextBox11.Text;
                    break;
                case "A3":
                    nb.B = richTextBox21.Text;
                    break;
                case "A4":
                    nb.B = richTextBox31.Text;
                    break;
                case "A5":
                    nb.B = richTextBox41.Text;
                    break;
                case "A6":
                    nb.B = richTextBox51.Text;
                    break;
                case "A7":
                    nb.B = richTextBox61.Text;
                    break;
                case "A8":
                    nb.B = richTextBox71.Text;
                    break;
                case "B1":
                    nb.B = richTextBox2.Text;
                    break;
                case "B2":
                    nb.B = richTextBox12.Text;
                    break;
                case "B3":
                    nb.B = richTextBox22.Text;
                    break;
                case "B4":
                    nb.B = richTextBox32.Text;
                    break;
                case "B5":
                    nb.B = richTextBox42.Text;
                    break;
                case "B6":
                    nb.B = richTextBox52.Text;
                    break;
                case "B7":
                    nb.B = richTextBox62.Text;
                    break;
                case "B8":
                    nb.B = richTextBox72.Text;
                    break;
                default:
                    break;
            }

            return nb;
        }
        //Save
        private void button26_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection(constr);
            con.Open();
            SqlCommand cmd;
            for (int i = 1; i < 81; ++i)
            {
                cmd = new SqlCommand("UPDATE EXL SET Cell = @richTextbox,Font=@font, Style=@stil,  Dim=@dim WHERE Id = "+i+";", con);
                //cmd.Parameters.Add("@richTextbox", Cell[i]);
                cmd.Parameters.Add("@richTextbox", cell[i].Ctext);
                cmd.Parameters.Add("@font", cell[i].Cfont);
                string stilC;
                switch (cell[i].Cstil)
                {
                    case FontStyle.Bold:
                        stilC = "Bold";
                        cmd.Parameters.Add("@stil", "Bold");
                        break;
                    case FontStyle.Italic:
                        stilC = "Italic";
                        cmd.Parameters.Add("@stil", "Italic");
                        break;
                    case FontStyle.Regular:
                        stilC = "Regular";
                        cmd.Parameters.Add("@stil", "Regular");
                        break;
                    default:
                        break;
                }
                
                cmd.Parameters.Add("@dim", cell[i].Cdim);
                cmd.ExecuteNonQuery();
            }
            con.Close();
            MessageBox.Show("Datele au fost adăugate în baza de date");

        }

        private void button23_Click(object sender, EventArgs e)
        {
            DataGrid dg = new DataGrid();
            dg.Show();
        }
    }
}
