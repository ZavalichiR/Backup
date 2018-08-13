using System;

namespace MedicalDB
{
    public partial class MessageBoxsave : MetroFramework.Forms.MetroForm
    {
        public MessageBoxsave()
        {
            InitializeComponent();
        }

        private void metroButton1_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
