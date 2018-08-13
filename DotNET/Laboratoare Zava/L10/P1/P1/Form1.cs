using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml;

namespace P1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            OpenFileDialog dlg = new OpenFileDialog();
            dlg.Title = "Open XML Document";
            dlg.Filter = "XML Files (*.xml)|*.xml";
            if (dlg.ShowDialog() == DialogResult.OK) // daca s-a incarcat cu succes un fisier (nu am dat Cancel)
            {
                try
                {
                    // schimbam tipul de cursor la unul de asteptare pana cand nodurile sunt populate
                    this.Cursor = Cursors.WaitCursor;

                    // incarcam documentul XML
                    XmlDocument xDoc = new XmlDocument();
                    xDoc.Load(dlg.FileName);
                    fileName = dlg.FileName;

                    // stergem TreeView-ul si adaugam nodul radacina
                    treeView1.Nodes.Clear();
                    treeView1.Nodes.Add(new TreeNode(xDoc.DocumentElement.Name));
                    TreeNode tNode = new TreeNode();
                    tNode = (TreeNode)treeView1.Nodes[0];

                    // acum apelam functia addTreeNode, recursiva, pentru a adauga toate nodurile in arbore
                    // XML-ul este parcurs recursiv
                    addTreeNode(xDoc.DocumentElement, tNode);

                    // expandam toate elementele ca sa se poata vedea
                    treeView1.ExpandAll();
                }
                catch (XmlException xExc)
                // se arunca o exceptie cand XML-ul contine erori
                {
                    MessageBox.Show(xExc.Message);
                }
                catch (Exception ex) // alte exceptii posibile
                {
                    MessageBox.Show(ex.Message);
                }
                finally
                {
                    // schimbam inapoi cursorul dupa incarcarea nodurilor
                    this.Cursor = Cursors.Default;
                }
            }
        }


    }

    // folosim un FileDialog doar cu fisiere XML ca intrare
    // aceasta functie este apelata recursiv pana cand am populat tot arborele
    private void addTreeNode(XmlNode xmlNode, TreeNode treeNode)
    {
        XmlNode xNode;
        TreeNode tNode;
        XmlNodeList xNodeList;
        if (xmlNode.HasChildNodes) // daca nodul curent inca mai are fii
        {
            xNodeList = xmlNode.ChildNodes; // ii preluam lista de fii
                                            // iteram prin lista fiilor
            for (int i = 0; i <= xNodeList.Count - 1; i++)
            {
                // adaugam fiul curent in arbore
                xNode = xmlNode.ChildNodes[i];
                treeNode.Nodes.Add(new TreeNode(xNode.Name));

                // continuam parcurgerea recursiva cu urmatorul
                tNode = treeNode.Nodes[i];
                addTreeNode(xNode, tNode);
            }
        }
        else // nu mai exista copii
            treeNode.Text = xmlNode.OuterXml.Trim();
    }

private void button2_Click(object sender, EventArgs e)
        {

        }
    }
}
