using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace L10_Tema
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        string path;
        Stack<TreeNode> stiva;
        DirectoryInfo directorRadacina;
        TreeNode nod;


        private void button1_Click_1(object sender, EventArgs e)
        {
            var fbd = new FolderBrowserDialog();
            DialogResult result = fbd.ShowDialog();
            path = fbd.SelectedPath;
            richTextBox1.Text = "Folder: " + path;
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            if (path != null && path != "")
            {
                treeView1.Nodes.Clear();

                stiva = new Stack<TreeNode>();
                directorRadacina = new DirectoryInfo(path);
                nod = new TreeNode(directorRadacina.Name) { Tag = directorRadacina };
                stiva.Push(nod);

                while (stiva.Count > 0)
                {

                    var nodCurent = stiva.Pop();
                    var informatiiDirector = (DirectoryInfo)nodCurent.Tag;

                    //Procesare Foldere si adaugare in treenod
                    foreach (var director in informatiiDirector.GetDirectories())
                    {
                        var subDirector = new TreeNode(director.Name) { Tag = director };
                        nodCurent.Nodes.Add(subDirector);

                        // adaugare subfoldere in treenod
                        stiva.Push(subDirector);
                    }

                    // Fisierele sunt foldere--->se afiseaza direct
                    foreach (var folder in informatiiDirector.GetFiles())
                        nodCurent.Nodes.Add(new TreeNode(folder.Name));
                }


                treeView1.Nodes.Add(nod);
            }
            else
            {
                MessageBox.Show("Selectati un folder", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            treeView1.Nodes.Clear();
            richTextBox1.Clear();
        }
    }
}
