using System;
using System.Windows.Forms;
using System.Messaging;
using BibliotecaClient;

namespace ClientEditorNamespace
{
    public partial class ClientEditor : Form
    {

        /* * * * * * * *  MSG related stuff  * * * * * * * * */
        private const string mainInboundQ = @".\private$\tdr_doc_inbound";
        private const string clientSpecificOutboundBaseQ = @".\private$\tdr_doc_client";
        private MessageQueue serverOut = null;
        private MessageQueue serverIn = null;

        public MessageQueue initQueue(string path)
        {
            if (MessageQueue.Exists(path))
            {
                return new MessageQueue(path);
            }
            else
            {
                return MessageQueue.Create(path);
            }
        }

        public ClientEditor()
        {
            InitializeComponent();
        }

        private void tbContent_TextChanged(object sender, EventArgs e)
        {
            

        }

        private bool isConnected = false;

        private void btnConnect_Click(object sender, EventArgs e)
        {
            if (!isConnected)
            {
                string Token = tbToken.Text;
                //Incearca sa te conectezi la server
                try
                {
                    serverIn = initQueue(mainInboundQ);
                    serverIn.Formatter = new BinaryMessageFormatter();
                    serverOut = initQueue(clientSpecificOutboundBaseQ + Token);
                    serverOut.Formatter = new BinaryMessageFormatter();
                    //Send a connect message to the client
                    ConnectToServer(Token);
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message);
                    return;
                }
                isConnected = true;
                tbContent.Enabled = true;
                tbToken.Enabled = false;
                btnConnect.Text = "Deconectare server";
            }
            else
            {
                //Send a disconnected message
                isConnected = false;
                tbContent.Enabled = false;
                tbToken.Enabled = true;
                btnConnect.Text = "Conectare Server";
            }
            

            //Insert
            //tbContent.Text = tbContent.Text.Insert(16, "h");
            
            //Delete
            //tbContent.Text = tbContent.Text.Remove(20, 1);
            
            //Move Cursor
            //tbContent.SelectionChanged -= tbContent_SelectionChanged;
            //tbContent.SelectionStart = 20;
            //tbContent.SelectionChanged += tbContent_SelectionChanged;
            //tbContent.Focus();
        }

        private void ConnectToServer(string token)
        {
            
            BibliotecaClient.StareClient sc = new StareClient(0, token);
            OperatieServer os = new OperatieServer(token, OperatieServer.Operatii.SERV_CON, sc);
            serverIn.Send(os, "Client " + token + " connect request");
            serverOut.BeginReceive(TimeSpan.FromSeconds(30), serverOut, new AsyncCallback(OnServerMessage));
        }

        /* UI functions */
        private void tbToken_TextChanged(object sender, EventArgs e)
        {
            if (tbToken.Text.Length > 0)
            {
                btnConnect.Enabled = true;
            }
            else
            {
                btnConnect.Enabled = false;
            }
        }

        private void tbLog_TextChanged(object sender, EventArgs e)
        {
            //Scroll to bottom
            
            tbLog.ScrollToCaret();
            int MAX_LOG_LINES = 20;
            if (tbLog.Lines.Length > MAX_LOG_LINES)
            {
                tbLog.TextChanged -= tbLog_TextChanged;
                //Keep the last message
                tbLog.Text = "Log limit exceded. Clearing logs!\n" + tbLog.Lines[tbLog.Lines.Length - 1];
                tbLog.TextChanged += tbLog_TextChanged;
            }
        }

        /* Event generating functions */

        private bool ignoreNextKeyUp = false;
        private bool ignoreNextCursorMove = false;

        private void tbContent_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!char.IsControl(e.KeyChar))
            {
                //treat Back(space)
                //msg += "A control key (code)" + ((int)(e.KeyChar)).ToString();
                tbLog.AppendText(e.KeyChar.ToString() + " was pressed.\n");
                //We have treated the key

                // Insert event
                newInsertEvent(new Selectie(tbContent.SelectionStart, tbContent.SelectionLength), e.KeyChar.ToString());

                ignoreNextKeyUp = true;
                ignoreNextCursorMove = true;
            }
        }

        private void tbContent_KeyUp(object sender, KeyEventArgs e)
        {
            //Handle Delete/Backspace/Enter
            if (ignoreNextKeyUp == true)
            {
                ignoreNextKeyUp = false;
                return;
            }
            switch (e.KeyCode)
            {
                case Keys.Back:
                    // Backspace event
                    newInsertEvent(new Selectie(tbContent.SelectionStart, 1), "");
                    break;
                case Keys.Delete:
                    // Delete event
                    newInsertEvent(new Selectie(tbContent.SelectionStart, 1), "");
                    break;
                case Keys.Enter:
                    // Insert event
                    newInsertEvent(new Selectie(tbContent.SelectionStart, tbContent.SelectionLength), "\n");
                    break;
                default:
                    //do nothing
                    return;
            }
            string msg = "";
            msg += e.KeyCode.ToString();
            tbLog.AppendText(msg + " was raised.\n");
        }

        private void tbContent_SelectionChanged(object sender, EventArgs e)
        {
            if (ignoreNextCursorMove == true)
            {
                ignoreNextCursorMove = false;
                return;
            }
            
            // Move event

            tbLog.AppendText("Selection changed: " + tbContent.SelectionStart.ToString() + " -> " + tbContent.SelectionLength + "\n");

        }


        private void newInsertEvent(BibliotecaClient.Selectie origine, string deInserat)
        {
            BibliotecaClient.OperatieInserare oi = new OperatieInserare(tbToken.Text, deInserat, origine);
            serverIn.Send(oi, tbToken.Text + " insert operation");
        }


        private void OnServerMessage(IAsyncResult ar)
        {
            MessageQueue mq = (MessageQueue)ar.AsyncState;
            System.Messaging.Message msg = null;
            try
            {
                msg = mq.EndReceive(ar);

            }
            catch
            {
                SafeUpdateControl(tbLog, tbLog.Text + "Server Timeout\n");
            }
            mq.BeginReceive(TimeSpan.FromSeconds(10), mq, new AsyncCallback(OnServerMessage));

            //Procesare mesaj
            BibliotecaClient.Operatie op = (Operatie)msg.Body;
            ParseServerMessage(op);
        }

        private delegate void ControlStringConsumer(Control control, string text);

        private void SafeUpdateControl(Control control, string text)
        {
            if (control.InvokeRequired)
            {
                control.Invoke(new ControlStringConsumer(SafeUpdateControl), new object[] { control, text });
            } else
            {
                control.Text = text;
            }
        }


        private delegate void SpecialDelegate(OperatieInserare oi);
        private void SafeInsertContent(OperatieInserare oi)
        {
            if (tbContent.InvokeRequired)
            {
                tbContent.Invoke(new SpecialDelegate(SafeInsertContent), new object[] { oi });
            }
            else
            {
                int i = oi.InsertPoint.PozitieStart;
                int j = i + oi.InsertPoint.LungimeSelectie;
                string data = tbContent.Text.Substring(0, i) + oi.InsertedText + tbContent.Text.Substring(j);
                BibliotecaClient.Selectie sel = new Selectie(tbContent.SelectionStart, tbContent.SelectionLength);
                int delta = oi.InsertedText.Length - oi.InsertPoint.LungimeSelectie;
                tbContent.Text = data;
                sel.PozitieStart -= delta;
                if (sel.PozitieStart < 0)
                {
                    sel.PozitieStart = 0;
                }
                if (data.Length > 0)
                {
                    sel.PozitieStart = sel.PozitieStart % data.Length;
                    sel.LungimeSelectie = sel.LungimeSelectie % data.Length;
                }
                else {
                    sel.PozitieStart = 0;
                    sel.LungimeSelectie = 0;
                }
                tbContent.SelectionStart = sel.PozitieStart;
                tbContent.SelectionLength = sel.LungimeSelectie;
            }
        }

        private void ParseServerMessage(Operatie op)
        {
            switch (op.Denumire)
            {
                case Operatie.DenumireOperatie.OP_SERVER:
                    {
                        OperatieServer os = op as OperatieServer;
                        if (os.OperatiuneServer == OperatieServer.Operatii.SERV_SYNC)
                        {
                            string data = os.opData as string;
                            SafeUpdateControl(tbContent, data);
                        }
                    }
                    break;
                case Operatie.DenumireOperatie.OP_INSERARE:
                    {
                        OperatieInserare oi = op as OperatieInserare;
                        int i = oi.InsertPoint.PozitieStart;
                        int j = i + oi.InsertPoint.LungimeSelectie;
                        SafeInsertContent(oi);
                        //string data = tbContent.Text.Substring(0, i) + oi.InsertedText + tbContent.Text.Substring(j);
                        //SafeUpdateControl(tbContent, data);
                        SafeUpdateControl(tbLog, tbLog.Text + "INSERT recived from " + oi.Token + "\n");
                    }
                    break;
                default:
                    break;
            }
        }
    }
}
