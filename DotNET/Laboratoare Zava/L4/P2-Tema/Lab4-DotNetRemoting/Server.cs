using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Http;
using MathLibrary;

namespace Lab4_DotNetRemoting
{
    class ServerMain
    {
        static void Main(string[] args)
        {
            // Create a channel specifying the port
            HttpChannel channel = new HttpChannel(10000);
            // Register the channel with the runtime remoting services
            ChannelServices.RegisterChannel(channel);
            // Register a type as a well-known type -sao(singleton,singlecall),cao

            //RemotingConfiguration.RegisterWellKnownServiceType(typeof(MathLibrary.SimpleMath), "MyURI.soap", WellKnownObjectMode.Singleton); //v1
           // RemotingConfiguration.RegisterWellKnownServiceType(typeof(MathLibrary.SimpleMath), "MyURI.soap", WellKnownObjectMode.SingleCall);//v2
            RemotingConfiguration.RegisterActivatedServiceType(typeof(MathLibrary.SimpleMath));//v3
            // Keep the server alive until Enter is pressed.
            Console.WriteLine("Server started. Press Enter to end");
            Console.ReadLine();
        }
    }
}
