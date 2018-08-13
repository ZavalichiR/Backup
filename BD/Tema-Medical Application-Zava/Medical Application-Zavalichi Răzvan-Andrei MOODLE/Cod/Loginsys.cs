using System;
using System.Data;
using System.Windows.Forms;
using System.Data.SqlClient;


namespace MedicalDB
{
    public partial class Loginsys : MetroFramework.Forms.MetroForm
    {
        SqlConnection con;
        SqlDataAdapter ADAPTER;
        DataTable DT = new DataTable();
        
        

        public Loginsys()
        {            
            InitializeComponent();
        }


        private void metroButton1_Click_1(object sender, EventArgs e)
        {
            con = new SqlConnection(Globals.connString);
            con.Open();
            //-- Ia din tabela Login liniile unde: Name= numele introdus in textBox1 si Password= parola introdusa
            //-- @user si @pass reprezinta alias 
            ADAPTER = new SqlDataAdapter("SELECT * FROM Login WHERE Name=@user AND Password=@pass ", con);
            ADAPTER.SelectCommand.Parameters.Add("@user", SqlDbType.VarChar, 50).Value = metroTextBox1.Text;
            ADAPTER.SelectCommand.Parameters.Add("@pass", SqlDbType.VarChar, 50).Value = metroTextBox2.Text;

            ADAPTER.Fill(DT);

            if( DT.Rows.Count>0 )
            {
                Home child = new Home();
                this.Close();
                child.Show();
               // child.TopMost = true;
                //child.Activate();
                
            }

            else
                MessageBox.Show("The User or Password is incorrect ..! .", "ERROR", MessageBoxButtons.OK, MessageBoxIcon.Hand);
            con.Close();


        }


        private void adminsBindingNavigatorSaveItem_Click(object sender, EventArgs e)
        {
            this.Validate();
            this.adminsBindingSource.EndEdit();


        }

        private void adminsBindingNavigatorSaveItem_Click_1(object sender, EventArgs e)
        {
            this.Validate();
            this.adminsBindingSource.EndEdit();


        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            Application.Exit();
        }



    }
}
