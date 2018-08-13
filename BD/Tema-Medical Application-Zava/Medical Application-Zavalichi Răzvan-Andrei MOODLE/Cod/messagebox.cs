using System;

namespace MedicalDB
{
    public partial class messagebox : MetroFramework.Forms.MetroForm
    {
        public messagebox()
        {
            InitializeComponent();
        }

        private void messagebox_Load(object sender, EventArgs e)
        {

        }

        private void metroButton1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
