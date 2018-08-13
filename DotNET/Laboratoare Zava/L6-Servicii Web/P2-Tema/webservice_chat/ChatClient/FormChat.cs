using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using ChatClient.ChatWS;
using System.Text.RegularExpressions;
namespace ChatClient
{
    public partial class FormChat : Form
    {
        public ChatManagerWS chatWS;
        public Timer timer;
        private bool server_offline;
        public FormChat()
        {
            InitializeComponent();
            chatWS = new ChatWS.ChatManagerWS();
            chatWS.CookieContainer = new System.Net.CookieContainer();
            server_offline = false;
            Enable_Interface(true);
            timer = new Timer();
            timer.Tick += timer_Tick;
            timer.Interval = 100;
            timer.Start();
        }
        private void Enable_Interface(bool enable)
        {
            textBoxMessageToSend.Enabled = enable;
            textBoxMessages.Enabled = enable;
            buttonLogin.Enabled = enable;
            buttonSend.Enabled = enable;
        }
        private void timer_Tick(object sender, EventArgs e)
        {
            string response;
            ChatWS.Message[] messages;
            try
            {
                bool r = chatWS.GetMessages(out response, out messages);
                if (server_offline == true)
                {
                    Enable_Interface(true);
                    server_offline = false;
                    timer.Interval = 100;
                }
                if (r)
                {
                    for (int i = 0; i < messages.Length; i++)
                    {
                        string line;
                        if (messages[i].receiver != null)
                        {
                            line = messages[i].sender + " (Private): " + messages[i].text;
                        }
                        else
                        {
                            line = messages[i].sender + ": " + messages[i].text;
                        }
                        AppendText(line + System.Environment.NewLine);
                    }
                }
                else
                {
                    AppendText(Environment.NewLine + "\t" + response + Environment.NewLine + Environment.NewLine);
                }

            }
            catch (Exception ex)
            {
                if (server_offline == false)
                {
                    timer.Interval = 3000;
                    Enable_Interface(false);
                    server_offline = true;
                    MessageBox.Show("Service offline");
                }
            }
        }
        delegate void ReturningVoidStringParameter(string text);
        private void AppendText(string text)
        {
            if(text.Contains("clear"))
            {
                textBoxMessages.Clear();
                text = "Windows was cleaned";
            }
            if (textBoxMessages.InvokeRequired)
            {
                ReturningVoidStringParameter d = new ReturningVoidStringParameter(AppendText);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                textBoxMessages.AppendText(text);
            }
        }
        private void buttonLogin_Click(object sender, EventArgs e)
        {
            if (server_offline == true)
                return;
            string user_name=textBox1.Text;
            //LoginForm loginForm = new LoginForm();
            //DialogResult r = loginForm.ShowDialog();
           // if (r == DialogResult.OK)
            {
                //user_name = loginForm.GetInput();
                string response;
                if (chatWS.Connect(user_name, out response))
                {
                    AppendText(Environment.NewLine + "\t " + user_name+ " Conected " + Environment.NewLine + Environment.NewLine);
                    buttonLogin.Enabled = false;
                    textBoxMessageToSend.ReadOnly = false;
                }
                else
                {
                    AppendText(Environment.NewLine + "\t" + response + Environment.NewLine + Environment.NewLine);
                }
            }
        }

        private void buttonSend_Click(object sender, EventArgs e)
        {
            SendMessageBoxText();
        }
        private void SendMessageBoxText()
        {
            string response;
            string text = textBoxMessageToSend.Text.TrimEnd();
            textBoxMessageToSend.Clear();
            if (text.Length > 0 && !chatWS.SendMessage(text, out response))
            {
                AppendText(Environment.NewLine + "\t" + response + Environment.NewLine + Environment.NewLine);
            }
        }

        private void textBoxMessageToSend_KeyUp(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter)
            {
                SendMessageBoxText();
                //e.Handled = true;
            }
            
        }

        private void FormChat_FormClosing(object sender, FormClosingEventArgs e)
        {
            string response;
            chatWS.Disconnect(out response);
        }

        private void FormChat_Load(object sender, EventArgs e)
        {
            textBoxMessages.Clear();
        }

        private void textBoxMessages_TextChanged(object sender, EventArgs e)
        {
        }
        //whiper
    }
}
