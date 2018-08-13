using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Http;
using MathLibrary;
namespace MathServer
{
    class ServerMain
    {
        static void Main(string[] args)
        {
            // Create a channel specifying the port
            //HttpChannel channel = new HttpChannel(10000);
            // Register the channel with the runtime remoting services
            //ChannelServices.RegisterChannel(channel);
            // Register a type as a well-known type
            //RemotingConfiguration.RegisterWellKnownServiceType(typeof(MathLibrary.SimpleMath), "MyURI.soap", WellKnownObjectMode.Singleton);
            RemotingConfiguration.Configure("MathServer.exe.config");
            // Keep the server alive until Enter is pressed.
            Console.WriteLine("Server started. Press Enter to end");
            Console.ReadLine();
        }
    }
}