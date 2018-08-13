using System;
using System.Collections;
using System.Text;
using System.Messaging;
using BibliotecaClient;

namespace Server
{

    class Server
    {
        static void Main(string[] args)
        {
            try
            {
                Server serverNou = new Server();
                serverNou.start();
            }
            catch (Exception e)
            {
                Console.WriteLine("Something horrible happened. Here's what:");
                Console.WriteLine(e.Message);
                return;
            }
        }

        private const string mainInboundQ = @".\private$\tdr_doc_inbound";
        private const string clientSpecificOutboundBaseQ = @".\private$\tdr_doc_client";
        private const double clientTimeoutInSeconds = 20.0;
        private string DocumentContent = "";

        //Metodă de autentificare. Un client fără un Token valid este ignorat
        private static string[] clientTokens = { "1234", "qwer", "asdf" };
        private System.Collections.Generic.Dictionary<string, BibliotecaClient.StareClient> clienti;

        public Server()
        {
            clienti = new System.Collections.Generic.Dictionary<string, BibliotecaClient.StareClient>();
            mainQ = initQueue(mainInboundQ);
            mainQ.Formatter = new BinaryMessageFormatter();

        }

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

        MessageQueue mainQ;

        public void start()
        {
            //Entry point
            //Ascultam pe coada globala (mainInbound)
            mainQ.BeginReceive(
                TimeSpan.FromSeconds(10),
                mainQ,
                new AsyncCallback(MessageFromClient)
            );
            while (true)
            {
                //Keep the server running
                System.Threading.Thread.Sleep(500);
            }
        }

        public void MessageFromClient(IAsyncResult ar)
        {
            //Am primit un mesaj pe coada principala
            Message msg = null;
            try
            {
                msg = ((MessageQueue)ar.AsyncState).EndReceive(ar);
            }
            catch (MessageQueueException ex)
            {
                if (ex.MessageQueueErrorCode == MessageQueueErrorCode.IOTimeout)
                {
                    Console.WriteLine("Timeout! Nothing new happened.");
                    mainQ.BeginReceive(
                        TimeSpan.FromSeconds(10),
                        mainQ,
                        new AsyncCallback(MessageFromClient)
                    );
                    return;
                }
            }
            mainQ.BeginReceive(
                TimeSpan.FromSeconds(1),
                mainQ,
                new AsyncCallback(MessageFromClient)
            );

            BibliotecaClient.Operatie op = (BibliotecaClient.Operatie)msg.Body;
            if (op == null)
            {
                System.Console.WriteLine("Mesaj invalid receptionat - Nu e o operatie");
                return;
            }
            //Procesare
            ProcessGenericOperation(op);

        }// end MessageFromClient

        private void ProcessGenericOperation(BibliotecaClient.Operatie op)
        {
            switch (op.Denumire)
            {
                case BibliotecaClient.Operatie.DenumireOperatie.OP_SERVER:
                    //Operatii client - conectare deconectare
                    BibliotecaClient.OperatieServer os = op as BibliotecaClient.OperatieServer;
                    ProcessServerOperation(os);
                    break;
                case BibliotecaClient.Operatie.DenumireOperatie.OP_INSERARE:
                    OperatieInserare oi = op as OperatieInserare;
                    ProcessInsertOperation(oi);
                    System.Console.WriteLine("Operatie primită: " + op.Denumire.ToString());
                    break;
                case BibliotecaClient.Operatie.DenumireOperatie.OP_DEPLASARE:
                    System.Console.WriteLine("Operatie primită: " + op.Denumire.ToString());
                    break;
                default:
                    System.Console.WriteLine("Mesaj invalid receptionat - Operatie necunoscuta");
                    break;
            } // end switch
        }

        private void ProcessServerOperation(BibliotecaClient.OperatieServer os)
        {
            switch (os.OperatiuneServer)
            {
                case BibliotecaClient.OperatieServer.Operatii.SERV_CON:
                    {
                        //Conectare client nou
                        //Datele atasate sunt o noua stare client
                        BibliotecaClient.StareClient sc = os.opData as BibliotecaClient.StareClient;
                        //Creaza o coada pentru client si adauga-l la lista
                        MessageQueue coadaDedicataClient = initQueue(clientSpecificOutboundBaseQ + sc.Token);
                        coadaDedicataClient.Formatter = new BinaryMessageFormatter();
                        //sc.QueuePath = coadaDedicataClient + sc.Token;
                        //TODO - Autentificare
                        clienti[sc.Token] = sc;
                        System.Console.WriteLine("Client [" + sc.Token + "] has connected.");

                        //Send a SYN message

                        BibliotecaClient.OperatieServer reply = new BibliotecaClient.OperatieServer(os.Token, BibliotecaClient.OperatieServer.Operatii.SERV_SYNC, DocumentContent);
                        //Message msg = new Message(reply);
                        //msg.Label = "SYNC message to " + os.Token;
                        System.Console.WriteLine("SYNC transmitted to " + os.Token);
                        unicastMessage(os.Token, reply);
                    }

                    break;
                case BibliotecaClient.OperatieServer.Operatii.SERV_RELEASE:
                    {
                        //Elimina clientul.
                        clienti.Remove(os.Token);
                        System.Console.WriteLine("Bye [" + os.Token + "]!");
                    }
                    break;

                case BibliotecaClient.OperatieServer.Operatii.SERV_SYNC:
                    {
                        BibliotecaClient.OperatieServer reply = new BibliotecaClient.OperatieServer(os.Token, BibliotecaClient.OperatieServer.Operatii.SERV_SYNC, DocumentContent);
                        Message msg = new Message(reply);
                        msg.Label = "SYNC message to " + os.Token;
                        System.Console.WriteLine("SYNC transmitted to " + os.Token);
                        unicastMessage(os.Token, msg);
                    }
                    break;
                default:
                    System.Console.WriteLine("Mesaj invalid receptionat - Operatie server necunoscuta");
                    break;
            }
        }

       

        private void ProcessInsertOperation(BibliotecaClient.OperatieInserare oi)
        {
            int i = oi.InsertPoint.PozitieStart;
            int j = i + oi.InsertPoint.LungimeSelectie;
            try
            {
                DocumentContent = DocumentContent.Substring(0, i) + oi.InsertedText + DocumentContent.Substring(j);
            }
            catch (ArgumentOutOfRangeException)
            {
                DocumentContent += oi.InsertedText;
                oi.InsertPoint.PozitieStart--;
                oi.InsertPoint.LungimeSelectie = 0;
            }
            //broadcastMessage(new Message(oi), oi.Token);
            broadcastMessage(oi, oi.Token);
        }

        private void ProcessMoveOperation(BibliotecaClient.OperatieDeplasare od)
        {

        }

        private MessageQueue getClientConnection(string token)
        {
            return initQueue(clientSpecificOutboundBaseQ + token);
        }

        private void unicastMessage(string token, Object msg)
        {
            MessageQueue mq = initQueue(clientSpecificOutboundBaseQ + token);
            mq.Formatter = new BinaryMessageFormatter();
            mq.Send(msg);
            System.Console.WriteLine("Sending Unicast message to " + token);
        }

        private void broadcastMessage(Object msg, string exceptTo = "")
        {
            foreach(string token in clienti.Keys)
            {
                if (token != exceptTo)
                {
                    unicastMessage(token, msg);
                }
            }
        }
    }
}
