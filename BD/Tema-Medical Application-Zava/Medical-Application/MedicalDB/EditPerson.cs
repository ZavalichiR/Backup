using System;
using System.Windows.Forms;
using System.Data.SqlClient;
using System.Text.RegularExpressions;
using System.Collections.Generic;


namespace MedicalDB
{
    public partial class EditPerson : MetroFramework.Forms.MetroForm
    {
        ErrorProvider err = new ErrorProvider();
        private patient person;
        List<string> list = new List<string>();
        List<string> diseasesNew = new List<string>();
        List<string> diseasesRem = new List<string>();
        private Int32[] arr = new Int32[100];
        private int remove = 0;
        private int dontDelete=0;

        public EditPerson(patient data)
        {       
            InitializeComponent();
            listBox1.MouseDoubleClick += new MouseEventHandler(listBox1_DoubleClick);
            listBox2.MouseDoubleClick += new MouseEventHandler(listBox2_DoubleClick);
        
            person = data;
        }

        private void EditPerson_Load(object sender, EventArgs e)
        {
            UpdateDiseasesList();
            list.Clear();
            diseasesRem.Clear();
            diseasesNew.Clear();

            foreach (String str in listBox1.Items)
            {
                list.Add(str);
            }
            autoCompleteFirstName();
            autoCompleteLastName();
        }

        private void autoCompleteFirstName()
        {
            SqlConnection con = new SqlConnection(Globals.connString);
            SqlCommand com = new SqlCommand("Select FirstName from Patients", con);
            con.Open();
            SqlDataReader rdr = com.ExecuteReader();
            AutoCompleteStringCollection autoCompleteCollection = new AutoCompleteStringCollection();
            while (rdr.Read())
            {
                autoCompleteCollection.Add(rdr.GetString(0));
            }
            metroTextBox1.AutoCompleteSource = AutoCompleteSource.CustomSource;
            metroTextBox1.AutoCompleteMode = AutoCompleteMode.SuggestAppend;
            metroTextBox1.AutoCompleteCustomSource = autoCompleteCollection;
            con.Close();
        }
        private void autoCompleteLastName()
        {
            SqlConnection con = new SqlConnection(Globals.connString);
            SqlCommand com = new SqlCommand("Select LastName from Patients", con);
            con.Open();
            SqlDataReader rdr = com.ExecuteReader();
            AutoCompleteStringCollection autoCompleteCollection = new AutoCompleteStringCollection();
            while (rdr.Read())
            {
                autoCompleteCollection.Add(rdr.GetString(0));
            }
            metroTextBox2.AutoCompleteSource = AutoCompleteSource.CustomSource;
            metroTextBox2.AutoCompleteMode = AutoCompleteMode.SuggestAppend;
            metroTextBox2.AutoCompleteCustomSource = autoCompleteCollection;
            con.Close();
        }

        private void UpdateDiseasesList()
        {
            SqlConnection con = new SqlConnection(Globals.connString);
            SqlCommand cmd = new SqlCommand("Select Id, Disease from Diseases order by Disease ASC", con);
            con.Open();

            SqlDataReader rdr = cmd.ExecuteReader();
            listBox1.Items.Clear();
            int i = 0;
            while (rdr.Read())
            {
                i++;
                arr[i] = rdr.GetInt32(0);
                string disease = i + ". " + rdr.GetString(1);
                //string disease =rdr.GetString(1);
                listBox1.Items.Add(disease);

            }
            con.Close();
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {
            string title = person.FirstName + " " + person.LastName;
            label6.Text = title;

            metroTextBox1.Text = person.FirstName;
            metroTextBox2.Text = person.LastName;
            metroTextBox3.Text = person.Phone.ToString();
            metroTextBox4.Text = person.Weight.ToString();
            metroTextBox5.Text = person.Height.ToString();
            metroTextBox6.Text = person.Age.ToString();
            metroTextBox7.Text = person.Email.ToString();
            metroComboBox1.Text = person.Gender.ToString();   
            
            richTextBox1.Text = person.N_obs.ToString();
            richTextBox2.Text = person.M_obs.ToString();

            foreach(var d in person.Disease)
            {
                listBox2.Items.Add(d);
            }

            
        }

        private void metroButton1_Click(object sender, EventArgs e)
        {
            // Validate First Name
            string FirstName = metroTextBox1.Text;
            string regex = "^[a-zA-Z -]+$";
            if (Regex.IsMatch(FirstName, regex) && (FirstName.Length > 3) && (FirstName.Length < 20))
            {
                err.Clear();
            }
            else
            {
                string errorMessage = "Maximum size:10.\nMinimum size:3.\nFirst Name must have a valid format.\n" +
               "For example 'Name' ";
                err.SetError(metroTextBox1, errorMessage);
                return;
            }

            //Validate Last Name
            regex = "^[a-zA-Z]+$";
            string LastName = metroTextBox2.Text;
            if (Regex.IsMatch(LastName, regex) && (LastName.Length > 3) && (LastName.Length < 10 ))
            {
                err.Clear();
            }
            else
            {
                string errorMessage = "Maximum size:10.\nMinimum size:3.\nLast Name must have a valid format.\n" +
               "For example 'Name' ";
                err.SetError(metroTextBox2, errorMessage);
                return;
            }

            //Validate Email
            if (string.IsNullOrEmpty(metroTextBox7.Text) || metroTextBox7.Text!="-")
            {
                string emailAddress = metroTextBox7.Text;

                if (emailAddress.Length == 0)
                {
                    err.SetError(metroTextBox7, "if you don't have an email address complete with - ");
                    metroTextBox7.Text = "-";
                    return;
                }

                else if (metroTextBox7.Text != "-")
                {
                    regex ="^[^@\\s]+@[^@\\s]+(\\.[^@\\s]+)+$";
                     if (Regex.IsMatch(emailAddress, regex))
                        {
                            err.Clear();
                        }
                     else
                        {
                            string errorMessage = "e-mail address must be valid e-mail address format.\n" +
                           "For example 'someone@example.com' ";
                            err.SetError(metroTextBox7, errorMessage);
                            return;
                        }
                 }
            }


            // Validate Phone number
            string phone = metroTextBox3.Text;
            regex = "^\\(?\\d{4}\\)?[\\s.-]\\d{3}[\\s.-]\\d{3}$";
            if (phone.Length == 0)
            {
                err.SetError(metroTextBox7, "if you don't have a phone number complete with - ");
                metroTextBox3.Text = "-";
            }
            else if(metroTextBox3.Text != "-")
            {
                if (Regex.IsMatch(phone, regex))
                {
                    err.Clear();
                }
                else
                {
                    string errorMessage = "Phone number must have a valid format.\n" +
                   "For example 'xxxx xxx xxx' \n            'xxxx.xxx.xxx' \n            'xxxx-xxx-xxx' \n";
                    err.SetError(metroTextBox3, errorMessage);
                    return;
                }
            }
            

            // Validate Weight number
            string weight = metroTextBox4.Text;
            regex = "^(0|([1-9][0-9]*))(\\.[0-9]+)?$";
            if (Regex.IsMatch(weight, regex))
            {
                err.Clear();
            }
            else
            {
                string errorMessage = "The weight must be a number format.\n" +
               "For example '80.2' ";
                err.SetError(metroTextBox4, errorMessage);
                return;
            }


            // Validate Height number
            string height = metroTextBox5.Text;
            regex = "^(0|([1-9][0-9]*))(\\.[0-9]+)?$";
            if (Regex.IsMatch(height, regex))
            {
                err.Clear();
            }
            else
            {
                string errorMessage = "The height must be a number format.\n" +
               "For example '1.82' ";
                err.SetError(metroTextBox5, errorMessage);
                return;
            }

            // Validate age number
            string age = metroTextBox6.Text;
            if (age.Length!=0 && Convert.ToInt32(age) > 0 && Convert.ToInt32(age) < 200) 
            {
                err.Clear();
            }
            else
            {
                string errorMessage = "The age must be a integer format.\n" +
               "For example '22' ";
                err.SetError(metroTextBox6, errorMessage);
                return;
            }

            //Valide gender
            if (string.IsNullOrEmpty(metroComboBox1.Text))
            {
                err.SetError(metroComboBox1, "Please Chose Value from Gender  ");
                return;
            }

            // Calcul IMC si gasire rezultat//
            double w = Convert.ToDouble(metroTextBox4.Text);
            double h = Convert.ToDouble(metroTextBox5.Text);
            string result = Util_Func.Result_IMC(Util_Func.IMC_Calculator((float)w, (float)h));
            SqlConnection con = new SqlConnection(Globals.connString);
            SqlCommand cmd = new SqlCommand("Select * from Nutritional where Result='" + result + "'", con);
            con.Open();
            SqlDataReader rdr = cmd.ExecuteReader();

            Int32 nID = 1;
            if (rdr.Read())
            {
                nID = rdr.GetInt32(0);
            }
            else
            {
                MessageBox.Show(Convert.ToString("The element from DataBase NUTRITIONAL doesn't exist! "));
            }
            rdr.Close();



            cmd = new SqlCommand("UPDATE Patients Set FirstName=@fname,LastName=@lname,Gender=@gender,Phone=@phone,Weight=@weight,Height=@height,Age=@age,Email=@email,NId_fk=@Nutritional_ID where Id='"+person.ID+"' ", con);           

            cmd.Parameters.Add("@Nutritional_ID ", nID);
            cmd.Parameters.Add("@fname", metroTextBox1.Text);
            cmd.Parameters.Add("@lname", metroTextBox2.Text);
            cmd.Parameters.Add("@gender", metroComboBox1.GetItemText(metroComboBox1.SelectedItem));
            cmd.Parameters.Add("@phone", metroTextBox3.Text);
            cmd.Parameters.Add("@weight", Convert.ToDouble(metroTextBox4.Text));
            cmd.Parameters.Add("@height", Convert.ToDouble(metroTextBox5.Text));
            cmd.Parameters.Add("@age", metroTextBox6.Text);
            cmd.Parameters.Add("@email ", metroTextBox7.Text);
            cmd.ExecuteNonQuery();

            cmd = new SqlCommand("UPDATE Observations Set Nutritional_Obs=@n_obs,Medical_obs=@m_obs where PId_fk='" + person.ID + "' ", con);
            person.N_obs = richTextBox1.Text;
            person.M_obs = richTextBox2.Text;

            cmd.Parameters.Add("@n_obs", richTextBox1.Text);
            cmd.Parameters.Add("@m_obs", richTextBox2.Text);
            cmd.ExecuteNonQuery();

            // ID-ul se cunoaste si se face legatura dintre DISEASES si PATIENTS
            if ((remove==1) && (diseasesNew.Count == 0) && (listBox2.Items.Count == 0) ) //asigură că pune - dacă nu este nimic în lista de boli
            {
                cmd = new SqlCommand("insert into Patients_Diseases (PId_fk,DId_fk) values ( '" + person.ID + "', @DiseasesID)", con);
                cmd.Parameters.Add("@DiseasesID", 1);
                cmd.ExecuteNonQuery();
                
            }
            else
            {
                foreach (string str in diseasesNew)
                {

                    cmd = new SqlCommand("insert into Patients_Diseases (PId_fk,DId_fk) values ( '"+person.ID +"',(select Id from Diseases where Disease=@DiseasesID) )", con);
                    cmd.Parameters.Add("@DiseasesID", str);
                    cmd.ExecuteNonQuery();
                }

            }
            if (diseasesRem.Count != 0 )
            {
                foreach (string str in diseasesRem)
                {
                    cmd = new SqlCommand("delete from Patients_Diseases where DId_fk=(select Id from Diseases where Disease=@DiseaseName)", con);
                    cmd.Parameters.Add("@DiseaseName", str);
                    cmd.ExecuteNonQuery();
                }
            }


            con.Close();

            MessageBoxsave save = new MessageBoxsave();    
            save.ShowDialog(this);
            this.Close();
        }


        // Actualizare Lista cu BOLI //
        private void metroTextBox8_TextChanged(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            if (metroTextBox8.Text.Length == 0)
            {
                UpdateDiseasesList();
            }
            else
            {
                foreach (string str in list)
                {
                    if (Regex.IsMatch(str.ToLower(), metroTextBox8.Text.ToLower()))
                    {
                        listBox1.Items.Add(str);
                    }
                }
            }
        }

        // Selectare item din lista //
        private void listBox1_DoubleClick(object sender, MouseEventArgs e)
        {
            int index = this.listBox1.IndexFromPoint(e.Location);
            if (index != System.Windows.Forms.ListBox.NoMatches)
            {
                string data = listBox1.SelectedItem.ToString();
                string first = Convert.ToString(data[0]); //id-ul din lista
                for (int i = 1; i < data.Length;++i)
                {
                    if(data[i]!='.')
                    {
                        first = first + Convert.ToString(data[i]);
                    }
                    else
                    {
                        break;
                    }
                }
                 
                Int32 poz = Int32.Parse(first);
                Int32 Id = arr[poz]; // ID_ul bolii din baza de date

                SqlConnection con = new SqlConnection(Globals.connString);
                con.Open();
                SqlCommand cmd = new SqlCommand("Select Disease from Diseases where id=' " + Id + " ' ", con);
                SqlDataReader rdr = cmd.ExecuteReader();
                bool flg = true;
                if (rdr.Read())
                {
                    foreach(string again in listBox2.Items)
                    {
                        if( again.Equals(rdr.GetString(0)) )
                        {
                            string errorMessage = "The Disease must be unique";
                            err.SetError(listBox2, errorMessage);
                            flg = false;
                            break;
                        }
                    }
                    if(flg)
                    {
                        err.Clear();
                        listBox2.Items.Add(rdr.GetString(0));
                        diseasesNew.Add(rdr.GetString(0)); // Se adauga id-ul bolii in lista de boli
                    }
                    
                }
                con.Close();


            }
        }

        private void listBox2_DoubleClick(object sender, MouseEventArgs e)
        {

            if (listBox2.SelectedItems.Count > 0)
            {
                string data = listBox2.SelectedItem.ToString();
                diseasesRem.Add(data);
                for (int i = listBox2.SelectedIndices.Count - 1; i >= 0; i--)
                {
                    listBox2.Items.RemoveAt(listBox2.SelectedIndices[i]);
                    remove = 1;
                }
            }
        }

        private void metroTextBox8_TextChanged_1(object sender, EventArgs e)
        {
            listBox1.Items.Clear();
            if (metroTextBox8.Text.Length == 0)
            {
                UpdateDiseasesList();
            }
            else
            {
                foreach (string str in list)
                {
                    if (Regex.IsMatch(str.ToLower(), metroTextBox8.Text.ToLower()))
                    {
                        listBox1.Items.Add(str);
                    }
                }
            }
        }
    }


        
}
        
