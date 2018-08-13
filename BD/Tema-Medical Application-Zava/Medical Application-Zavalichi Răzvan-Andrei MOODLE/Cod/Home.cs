using System;
using System.Collections.Generic;
using System.Data.SqlClient;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace MedicalDB
{

    public struct patient
    {
        public int ID;
        public string FirstName;
        public string LastName;
        public string Gender;
        public double Weight;
        public double Height;
        public int Age;
        public string Email;
        public string Phone;

        public string N_obs;
        public string Result;
        public string NConclusion;

        public string M_obs;
        public List<string> MConclusion;
        public List<string> Disease;
    }
    
    
    public partial class Home : MetroFramework.Forms.MetroForm
    {
        ErrorProvider err = new ErrorProvider();
        private SqlConnection con;
        private SqlCommand cmd;
        private patient p;
        private Int32[] arr= new Int32[100];
        List<string> list = new List<string>();
        patient person;
        private int ok=0;

        public Home()
        {
            InitializeComponent();
            listBox1.MouseDoubleClick += new MouseEventHandler(listBox1_DoubleClick);
        }

        private void Home_Load(object sender, EventArgs e)
        {
            UpdatePacientList(); // Afisare Pacienti in  listBox1
            list.Clear();

            foreach (String str in listBox1.Items)
            {
                list.Add(str); // Adaga in lista toti pacientii
            }
        }

        // Citeste toti pacientii din tabela Patients si Afisare Pacienti in  listBox1
        private void UpdatePacientList() 
        {
            con = new SqlConnection(Globals.connString);
            cmd = new SqlCommand("Select FirstName,LastName,Id from Patients order by FirstName ASC, LastName ASC", con);
            con.Open();

            SqlDataReader rdr = cmd.ExecuteReader();
            listBox1.Items.Clear();
            int i=0;
            while (rdr.Read())
            {
                i++;
                arr[i] = rdr.GetInt32(2);
                string fullname = i + ". " + rdr.GetString(0) + " " + rdr.GetString(1);
                listBox1.Items.Add(fullname);
                
            }
            con.Close();

        }

        
        // Adauga o noua persoana
        private void button1_Click(object sender, EventArgs e)
        {
            AddNewPerson child = new AddNewPerson();
            child.ShowDialog(this);
            //this.Close();
            //child.Show();
        }

       
        // Delogare
        private void button3_Click(object sender, EventArgs e)
        {
            Loginsys logoutWindow = new Loginsys();
            this.Close();
            logoutWindow.Show();
            logoutWindow.TopMost = true;
            logoutWindow.Activate();
        }

        // Inchide aplicatie
        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        // Deschide o fereastra cu detaliile despre pacientul selectat
        private void listBox1_DoubleClick(object sender, MouseEventArgs e)
        {
            int index = this.listBox1.IndexFromPoint(e.Location);
            if (index != System.Windows.Forms.ListBox.NoMatches)
            {
                bool Ok = true;
                string data = listBox1.SelectedItem.ToString();

                string first = Convert.ToString(data[0]); //id-ul din lista a pacientului
                for (int i = 1; i < data.Length; ++i)
                {
                    if (data[i] != '.')
                    {
                        first = first + Convert.ToString(data[i]);
                    }
                    else
                    {
                        break;
                    }
                }

                Int32 poz = Int32.Parse(first.ToString());
                Int32 Id = arr[poz];

                // --- Citeste datele din tabela Patients dupa ID --//
                con = new SqlConnection(Globals.connString);
                con.Open();
                cmd = new SqlCommand("Select * from Patients where id=' "+Id+" ' " , con);  
                SqlDataReader rdr = cmd.ExecuteReader();
                if (rdr.Read())
                {
                    Ok = true;
                    person.ID=rdr.GetInt32(0);
                    person.FirstName = rdr.GetString(1);
                    person.LastName = rdr.GetString(2);
                    person.Gender = rdr.GetString(3);
                    person.Phone = rdr.GetString(4);
                    person.Weight = rdr.GetDouble(5);
                    person.Height = rdr.GetDouble(6);
                    person.Age = rdr.GetInt32(7);
                    person.Email = rdr.GetString(8);
                    rdr.Close();

                    cmd = new SqlCommand("Select * from Observations where PId_fk=' "+Id+" ' ", con);
                    rdr = cmd.ExecuteReader();
                    if (rdr.Read())
                    {
                        Ok = true;
                        person.N_obs = rdr.GetString(2);
                        person.M_obs = rdr.GetString(3);
                    }
                    else
                    {
                        Ok = false;
                        MessageBox.Show(Convert.ToString("The element from DataBase OBSERVATIONS doesn't exist! "));
                    }

                    rdr.Close();
                    cmd = new SqlCommand("Select * from Nutritional where id=(select NId_fk from Patients where id=' "+Id+" ' )", con);
                    rdr = cmd.ExecuteReader();
                    if (rdr.Read())
                    {
                        Ok = true;
                        person.Result = rdr.GetString(3);
                        person.NConclusion = rdr.GetString(4);
                    }
                    else
                    {
                        Ok = false;
                        MessageBox.Show(Convert.ToString("The element from DataBase NUTRITIONAL doesn't exist! "));
                    }

                    rdr.Close();
                    cmd = new SqlCommand(" SELECT d.Id, d.Disease, d.Conclusion FROM Diseases d JOIN Patients_Diseases pd ON d.Id = pd.DId_fk WHERE pd.PId_fk = '" + Id +" ' ", con);   
                    rdr = cmd.ExecuteReader();

                    person.Disease=new List<string>();
                    person.MConclusion = new List<string>();
                    bool flag = false;
                    while (rdr.Read())
                    {
                       flag = true;
                       person.Disease.Add(rdr.GetString(1));
                       string Obs = rdr.GetString(1) + ":" + rdr.GetString(2) + "\n";
                       person.MConclusion.Add(Obs);              
                    }
                    if(!flag)
                    {
                        Ok = false;
                        MessageBox.Show(Convert.ToString("The element from DataBase Patients_Diseases doesn't exist! "));
                    }


                }
                else
                {
                    Ok = false;
                    MessageBox.Show(Convert.ToString("The element from DataBase PATIENTS doesn't exist! "));
                }

                if (true)
                {
                    con.Close();
                    Patient child = new Patient(person);
                    child.Show();

                }
            }
        }


        // Butonul de REFRESH //
        private void button4_Click(object sender, EventArgs e)
        {
            UpdatePacientList();
            list.Clear();

            foreach (String str in listBox1.Items)
            {
                list.Add(str);
            }
        }

        // Pentru SEARCH //
        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            if (textBox1.TextLength == 0 )
            {
                UpdatePacientList();
            }
            else
            {
              foreach (string str in list)
                {
                    if (Regex.IsMatch(str.ToLower(), textBox1.Text.ToLower()))
                    {
                        listBox1.Items.Add(str);
                     }
                 }   
            }     
        }

        //Calculator IMC
        private void button5_Click(object sender, EventArgs e)
        {
            if(ok==1)
            {
                string W = metroTextBox4.Text;
                string H = metroTextBox5.Text;

                double IMC = Convert.ToDouble(W) * 10000 / (Convert.ToDouble(H) * Convert.ToDouble(H));
                IMC = Math.Round(IMC, 2);
                metroTextBox1.Text = "IMC :" + Convert.ToString(IMC);

                string result = Util_Func.Result_IMC((float)IMC);
                metroTextBox2.Text = result;
            }
            else
            {
                string errorMessage = "INVALID input data";
                err.SetError(button5, errorMessage);
            }
            

        }

        private void metroTextBox4_TextChanged(object sender, EventArgs e)
        {
            // Validate Weight number
            string weight = metroTextBox4.Text;
            string regex = "^(0|([1-9][0-9]*))(\\.[0-9]+)?$";
            if (Regex.IsMatch(weight, regex))
            {
                err.Clear();
                ok = 1;
            }
            else
            {
                string errorMessage = "The weight must be a number format.\n" +
               "For example '80.2' ";
                err.SetError(metroTextBox4, errorMessage);
                ok = 0;
                return;
            }


            
        }

        private void metroTextBox5_TextChanged(object sender, EventArgs e)
        {
            // Validate Height number
            string height = metroTextBox5.Text;
            string regex = "^(0|([1-9][0-9]*))(\\.[0-9]+)?$";
            if (Regex.IsMatch(height, regex))
            {
                err.Clear();
                ok = 1;
            }
            else
            {
                string errorMessage = "The height must be a number format.\n" +
               "For example '1.82' ";
                err.SetError(metroTextBox5, errorMessage);
                ok = 0;
                return;
            }
        }
    }
}
