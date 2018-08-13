using MetroFramework.Forms;
using System;

namespace MedicalDB
{
    public partial class Welcom_from_sys : MetroForm
    {
        public Welcom_from_sys()
        {
            InitializeComponent();
           // this.TransparencyKey = (BackColor);
        }

        private void Welcom_from_sys_Load(object sender, EventArgs e)
        {
            timer1.Start();

        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            metroProgressBar1.Increment(3);

            if (metroProgressBar1.Value == metroProgressBar1.Maximum)
            {
                Loginsys child = new Loginsys();
         
                timer1.Stop();
                this.Hide();
                child.Show();
                child.TopMost = true;
                child.Activate();

            } 
          
        }

    }
}
