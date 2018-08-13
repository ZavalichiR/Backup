using System;
using System.Data.SqlClient;

namespace MedicalDB
{
    public partial class About : MetroFramework.Forms.MetroForm
    {
        public string disease;
        public About(string data)
        {
            InitializeComponent();
            disease = data;
            label2.Text = disease;
        }

        private void About_Load(object sender, EventArgs e)
        {

        }

        private void metroButton1_Click(object sender, EventArgs e)
        {
            SqlConnection con = new SqlConnection(Globals.connString);
            con.Open();
            SqlCommand cmd = new SqlCommand("insert into Diseases (Disease,Conclusion) values (@Dis, @Concl)", con);
            cmd.Parameters.Add("@Dis", disease);
            cmd.Parameters.Add("@Concl", richTextBox1.Text); 
            cmd.ExecuteNonQuery();
            messagebox save = new messagebox();   
            save.ShowDialog(this);
            this.Close();
        }
    }
}
