using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace ChatClient
{
    public partial class LoginForm : Form
    {
        public LoginForm()
        {
            InitializeComponent();
        }
        public string GetInput()
        {
            return textBoxUserName.Text;
        }

        private void buttonLogin_Click(object sender, EventArgs e)
        {
            string text = textBoxUserName.Text;
            string user_format = "The user name is an alphanumeric string at least 4 characters long.";

            Regex reg = new Regex("^[a-zA-Z0-9]{4,}$");
            if (!reg.IsMatch(text))
            {
                toolTipUserName.Active = true;
                toolTipUserName.Show(user_format, textBoxUserName);
                this.DialogResult = DialogResult.None;
                return;
            }
        }

        private void textBoxUserName_TextChanged(object sender, EventArgs e)
        {
            toolTipUserName.Active = false;
        }
        /*
        private void textBoxUserName_TextChanged(object sender, EventArgs e)
        {
            string text = textBoxUserName.Text;
            string user_format = "The user name is an alphanumeric string at least 4 characters long.";

            Regex reg = new Regex("^[a-zA-Z0-9]{4,}$");
            if (reg.IsMatch(text))
            {
                buttonLogin.Enabled = true;
                toolTipUserName.Active = false;
            }
            else
            {
                toolTipUserName.Active = true;
                toolTipUserName.Show(user_format, textBoxUserName);
                buttonLogin.Enabled = false;
            }
        }
        */
    }
}
