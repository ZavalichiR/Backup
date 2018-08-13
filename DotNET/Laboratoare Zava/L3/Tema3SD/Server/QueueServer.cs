using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Messaging;

namespace Server
{
    public class QueueServer
    {
        private MessageQueue serverQueue;
        private Dictionary<string, MessageQueue> clients;
      
        public QueueServer()
        {
            clients = new Dictionary<string, MessageQueue>();
        }
        public void InitQueueServer()
        {
            try
            {
                if (MessageQueue.Exists(@".\private$\serverQueue"))
                {
                    serverQueue = new MessageQueue(@".\private$\serverQueue");
                }
                else
                {
                    serverQueue = MessageQueue.Create(@".\private$\serverQueue");
                }
                serverQueue.Formatter = new BinaryMessageFormatter();
                serverQueue.ReceiveCompleted += new System.Messaging.ReceiveCompletedEventHandler(OnMessageRecived);
                serverQueue.BeginReceive();
            }
            catch(Exception ex)
            {
                Console.WriteLine("Timeout!");
            }
        }

        private void OnMessageRecived(Object source, ReceiveCompletedEventArgs e)
        {
            MessageQueue mq = null;
            System.Messaging.Message m = null;
            try
            {
                mq = (MessageQueue)source;
                m = mq.EndReceive(e.AsyncResult);
            }
            catch(Exception ex)
            {
               Console.WriteLine(ex.ToString());
            }

            EditorMessages msg = (EditorMessages)m.Body;
            switch (msg.Type)
            {
                case MSG_TYPE.NEW_TEXT:
                    Change(msg.Text, msg.MessageSource);
                    break;
                case MSG_TYPE.CLIENT_DISCONNECTED:
                    RemoveClient(msg.MessageSource);
                    break;
                case MSG_TYPE.NEW_CLIENT:
                    AddClient(msg.MessageSource);
                    break;
            }

            try
            {
                mq.BeginReceive();
            }
            catch(Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
        }

        private void AddClient(string name)
        {
            MessageQueue newQ = new MessageQueue(@".\private$\" + name);
            clients.Add(name, newQ);
            Console.WriteLine("Client nou:" + name);
        }
        private void Change(string change, string source)
        {
            EditorMessages newM = new EditorMessages(MSG_TYPE.NEW_TEXT, null, change);
            System.Messaging.Message msg = new Message(newM);
            msg.Formatter = new BinaryMessageFormatter();
            foreach (var pair in clients)
            {
                if (pair.Key != source)
                    pair.Value.Send(msg);
            }
            Console.WriteLine("Modificare: "+change);
        }
        private void RemoveClient(string client)
        {
            try
            {
                MessageQueue mq = clients[client];
                mq.Close();
                clients.Remove(client);
                MessageQueue.Delete(@".\private$\" + client);
            }catch(Exception ex)
            {
                Console.WriteLine(ex.ToString());
            }
            Console.WriteLine("Client "+client+" s-a deconectat");
        }


    }
}
