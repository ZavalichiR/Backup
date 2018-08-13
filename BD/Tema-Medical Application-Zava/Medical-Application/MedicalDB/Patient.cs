using System;
using System.Data.SqlClient;

namespace MedicalDB
{
    public partial class Patient : MetroFramework.Forms.MetroForm
    {
        private patient person;
        private SqlConnection con;
        private SqlCommand cmd;
        public Patient(patient data)
        {
            person = data;
            InitializeComponent();
        }

        private void Home_Load(object sender, EventArgs e)
        {
            
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {
            string title = person.FirstName + " " + person.LastName;
            groupBox1.Text = title;

            textBox1.Text = title;
            textBox2.Text = person.Age.ToString();
            textBox3.Text = person.Gender.ToString();
            textBox4.Text = person.Weight.ToString()+" "+"kg";
            textBox5.Text = person.Height.ToString()+" "+"cm";
            textBox6.Text = person.Email.ToString();
            textBox7.Text = person.Phone.ToString();

            
            double IMC = person.Weight * 10000 / (person.Height * person.Height);
            IMC = Math.Round(IMC, 2);
            textBox8.Text = Convert.ToString(IMC);
            textBox9.Text = person.Result.ToString();
            label14.Text = " \"" + textBox9.Text + "\" :";
            richTextBox1.Text = person.NConclusion.ToString();      
            richTextBox2.Text = person.N_obs.ToString();

            string diseaseList = "";
            foreach ( var d in person.Disease)
            {
                listBox1.Items.Add(d);
                diseaseList += d+" ";
            }
            if(person.Disease.Count>=1)
                label20.Text = "diseases";
            else
                label20.Text = " \""+diseaseList+"\" :";
            richTextBox3.Clear();
            foreach (var MC in person.MConclusion)
            {
                richTextBox3.Text= richTextBox3.Text+MC;
            }
            
            richTextBox4.Text = person.M_obs.ToString();





        }

        private void button1_Click(object sender, EventArgs e)
        {
            con = new SqlConnection(Globals.connString);
            con.Open();
            cmd = new SqlCommand("DELETE FROM Patients_Diseases WHERE PId_fk=' " + person.ID + " ' ", con);
            cmd.ExecuteNonQuery();

            cmd = new SqlCommand("DELETE FROM Observations WHERE PId_fk=' " + person.ID + " ' ", con);
            cmd.ExecuteNonQuery();
            
            cmd = new SqlCommand("DELETE FROM Patients WHERE Id=' " + person.ID + " ' ", con);
            cmd.ExecuteNonQuery();
            con.Close();
            MessageBoxsave save = new MessageBoxsave();
            this.Close();
            save.Show();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            EditPerson child = new EditPerson(person);
            this.Close();
            child.Show();
        }

        private void lineShape5_Click(object sender, EventArgs e)
        {

        }

    }
}
