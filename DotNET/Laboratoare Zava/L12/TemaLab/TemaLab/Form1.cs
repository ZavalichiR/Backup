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

namespace TemaLab
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private string fileName = null; // numele fisierului XML incarcat curent

        private void insertButton_Click(object sender, EventArgs e)
        {
            // inseram ca fiu al nodului selectat valoarea gasita in campul text
            if (!String.IsNullOrEmpty(insertedNode.Text))
            {
                if (treeView1.Nodes.Count == 0) // daca nu exista niciun nod in arbore
                {
                    // adaugam ca radacina
                    treeView1.Nodes.Add(insertedNode.Text);
                }
                else
                {
                    treeView1.SelectedNode.Nodes.Add(insertedNode.Text);
                }
            }
            else
            {
                MessageBox.Show("Introduceti un nume de nod nevid!");
            }
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            // stergem doar daca exista ceva selectat
            if (treeView1.SelectedNode != null)
            {
                treeView1.Nodes.Remove(treeView1.SelectedNode);
            }
        }

        private void loadButton_Click(object sender, EventArgs e)
        {
            // la click pe "Load" se incarca XML-ul dorit in TreeView
            populateTreeview();
        }

        private void populateTreeview()
        {
            // folosim un FileDialog doar cu fisiere XML ca intrare
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

        private void Save_Click(object sender, EventArgs e)
        {
            // la click pe Save, se exporta tot arborele intr-un fisier XML cu acelasi nume (se suprascrie)
            if (fileName != null)
            {
                exportToXml(treeView1, fileName);
                MessageBox.Show("Datele au fost salvate cu succes in fisierul XML \"" + fileName + "\"!");
            }
        }

        private XmlTextWriter xr;
        public void exportToXml(TreeView tv, string filename)
        {
            xr = new XmlTextWriter(filename, System.Text.Encoding.UTF8);
            xr.WriteStartDocument();
            // incepem sa scriem nodul radacina
            xr.WriteStartElement(treeView1.Nodes[0].Text);
            // scriem fiecare nod fiu in parte
            foreach (TreeNode node in tv.Nodes)
            {
                if (node.Checked == true)
                {
                    saveNode(node.Nodes);
                }
                
            }
            // inchidem nodul radacina
            xr.WriteEndElement();
            xr.Close();
        }

        private void saveNode(TreeNodeCollection tnc)
        {
            foreach (TreeNode node in tnc)
            {
                // daca avem noduri fii, vom crea un nod parinte, apoi iteram prin toti fiii
                if (node.Nodes.Count > 0 && node.Checked == true)
                {
                    xr.WriteStartElement(node.Text);
                    saveNode(node.Nodes);
                    xr.WriteEndElement();
                }
                else if (node.Checked == true) // fara noduri fii, deci scriem doar textul
                {
                    xr.WriteString(node.Text);
                }
            }
        }

        private void treeView1_AfterCheck(object sender, TreeViewEventArgs e)
        {
            // codul se executa doar daca utilizatorul a determinat starea "checked" a elementului sa se schimbe
            if (e.Action != TreeViewAction.Unknown)
            {
                if (e.Node.Nodes.Count > 0)
                {
                    // apeleaza functia de bifare / debifare a tuturor nodurilor fii celui a carui stare s-a schimbat
                    this.CheckAllChildNodes(e.Node, e.Node.Checked);
                }

                // daca bifam acel nod, atunci trebuie sa bifam si toti parintii lui
                if (e.Node.Checked == true)
                {
                    TreeNode node = e.Node;
                    while (node.Parent != null)
                    {
                        node = node.Parent;
                        node.Checked = true;
                    }
                }
            } 
        }

        // actualizarea (bifarea / debifarea) tuturor nodurilor fii in mod recursiv
        private void CheckAllChildNodes(TreeNode treeNode, bool nodeChecked)
        {
            foreach (TreeNode node in treeNode.Nodes)
            {
                node.Checked = nodeChecked;
                if (node.Nodes.Count > 0)
                {
                    // daca nodul curent inca mai are fii, apelam functia de bifare / debifare recursiv
                    this.CheckAllChildNodes(node, nodeChecked);
                }
            }
        }

    }
}
