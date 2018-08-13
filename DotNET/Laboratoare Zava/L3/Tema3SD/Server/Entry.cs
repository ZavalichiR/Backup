using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Server
{
    class Entry
    {
        public static void Main(string [] args)
        {
            QueueServer qs = new QueueServer();
            qs.InitQueueServer();
            Console.ReadKey();
        }

    }
}
