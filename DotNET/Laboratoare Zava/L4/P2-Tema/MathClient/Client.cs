using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Http;
using MathLibrary;
namespace MathClient
{
    class ClientMain
    {
        static void Main(string[] args)
        {
            // Create and register the channel. The default channel actor
            // does not open a port, so we can't use this to receive messages.
            // HttpChannel channel = new HttpChannel();
            // ChannelServices.RegisterChannel(channel);
            // Get a proxy to the remote object
            // Object remoteObj = Activator.GetObject(typeof(MathLibrary.SimpleMath),"http://localhost:10000/MyURI.soap");
            // Cast the returned proxy to the SimpleMath type
            RemotingConfiguration.RegisterActivatedClientType(typeof(MathLibrary.SimpleMath), "http://localhost:10000");
            SimpleMath math = new SimpleMath("Client-Activated");
            // Use the remote object
            Console.WriteLine("5 + 2 = {0}", math.Add(5, 2));
            Console.WriteLine("5 - 2 = {0}", math.Subtract(5, 2));


            //******************** TEMA ****************
            //***************** Citire vector ******************
            int n;
            do
            {
                Console.Write("Dimensiune:");
                n = Int32.Parse(Console.ReadLine());
            }
            while (n<1);
            string[] answer = new string[n];
            for (int i = 0; i < answer.Length; i++)
            {
                Console.Write("v[{0}]:",i);
                answer[i] = Console.ReadLine();
            }

            //***************** Sortare vector ******************
            string[] sortedVector = math.Sort(answer, n);
            Console.WriteLine("Vectorul sortat:");
            foreach (string v in sortedVector)
            {
                Console.Write(v + " ");
            }
                Console.Write("\n");

            //***************** Cautare element ******************
                Console.Write("Valoarea cautata:");
                string cauta = Console.ReadLine();
            if (math.Search(answer, answer.Length, cauta) != -1)
            {
                Console.WriteLine(" Valoarea {0} se afla in vector", cauta);
            }
            else
            {
                Console.WriteLine(" Valoarea {0}  nu se afla in vector", cauta);
            }


            //*************** Șterge valoare ************
            Console.Write("introduceti valoarea pe care doriti sa o stergeti:");
            string sters = Console.ReadLine();
            if (math.Search(answer,answer.Length, sters) == -1)
            {
                Console.Write("Valoarea {0} nu se gaseste in vector");
            }
            else
            {
               string[] vectorPrelucrat= math.Delete(answer, sters);
                Console.Write("Noul vector:");
                foreach (string s in vectorPrelucrat)
                {
                    Console.Write("{0} ",s);
                }
                Console.Write("Lungime vector: "+vectorPrelucrat.Length);

            }
            Console.Write("\n");
            // Ask user to press Enter
            Console.Write("Press enter to end");
            Console.ReadLine();
        }
    }
}
