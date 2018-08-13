using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Messaging;
using Server;

namespace Editor
{
    public partial class Editor : Form
    {
        private string queueName;
        private MessageQueue serverQueue;
        private MessageQueue clientQueue;
        private delegate void SetTextCallback(string text);


        public Editor()
        {
            InitializeComponent();
            InitComponents();
        }
        private void InitComponents()
        {
            try
            {
                //cream client cu id unic
                queueName = Guid.NewGuid().ToString();
                clientQueue = MessageQueue.Create(@".\private$\" + queueName);
                //luam coada serverului
                if (MessageQueue.Exists(@".\private$\serverQueue"))
                {
                    serverQueue = new MessageQueue(@".\private$\serverQueue");
                }
                else
                {
                    serverQueue = MessageQueue.Create(@".\private$\serverQueue");
                }
                serverQueue.Formatter = new BinaryMessageFormatter();
                clientQueue.Formatter = new BinaryMessageFormatter();
                clientQueue.ReceiveCompleted += new ReceiveCompletedEventHandler(OnMessageRecived);
                clientQueue.BeginReceive();
                //trimiter la server info despre noul client
                System.Messaging.Message logIn = new System.Messaging.Message();
                logIn.Formatter = new BinaryMessageFormatter();
                logIn.Body = new EditorMessages(Server.MSG_TYPE.NEW_CLIENT, queueName);
                serverQueue.Send(logIn);
            }
            catch
            {
                MessageBox.Show("Error");
            }
        }

        private void SetText(string str)
        {
            if (textArea.InvokeRequired)
            {
                textArea.Invoke(new SetTextCallback(SetText), new object[] { str });
            }
            else
            {
                textArea.Text = str;   
            }
        }
        private void OnMessageRecived(Object source, ReceiveCompletedEventArgs e)
        {
            MessageQueue mq = null;
            System.Messaging.Message m = null;
            try
            {
                //incercam sa luam mesajul primit
                mq = (MessageQueue)source;
                m = mq.EndReceive(e.AsyncResult);
            }
            catch
            {
                MessageBox.Show("Error");
            }

            m.Formatter = new BinaryMessageFormatter();
            EditorMessages msg = (EditorMessages)m.Body;
            switch (msg.Type)
            {
                case MSG_TYPE.NEW_TEXT:
                    SetText(msg.Text);
                    break;
            }

            try
            {
                mq.BeginReceive();
            }
            catch
            {
                MessageBox.Show("Error");
            }
        }

        private void OnFormClose(object sender, FormClosingEventArgs e)
        {
            //spunem serverului ca s-a inchis clientul
            System.Messaging.Message closeMsg = new System.Messaging.Message();
            closeMsg.Formatter = new BinaryMessageFormatter();
            closeMsg.Body = new EditorMessages(MSG_TYPE.CLIENT_DISCONNECTED, queueName);
            serverQueue.Send(closeMsg);
        }

        private void OnKeyPress(object sender, KeyEventArgs e)
        {
            System.Messaging.Message msg = new System.Messaging.Message();
            msg.Formatter = new BinaryMessageFormatter();
            msg.Body = new EditorMessages(MSG_TYPE.NEW_TEXT, queueName, textArea.Text);
            serverQueue.Send(msg);
        }

        private void textArea_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
