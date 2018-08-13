using System;
using System.Runtime.Remoting;
using System.Runtime.Remoting.Channels;
using System.Runtime.Remoting.Channels.Http;
using MathLibrary;
namespace MathClient
{
    class ClientMain
    {
        static void Main(string[] args)
        { // Create and register the channel. The default channel actor
          // does not open a port, so we can't use this to receive messages.
            HttpChannel channel = new HttpChannel();
            ChannelServices.RegisterChannel(channel);
            // Get a proxy to the remote object
            Object remoteObj = Activator.GetObject(typeof(MathLibrary.SimpleMath),
            "http://localhost:10000/MyURI.soap");
            // Cast the returned proxy to the SimpleMath type
            SimpleMath math = (SimpleMath)remoteObj;
            // Use the remote object
            Console.WriteLine("5 + 2 = {0}", math.Add(5, 2));
            Console.WriteLine("5 - 2 = {0}", math.Subtract(5, 2));
            // Ask user to press Enter
            Console.Write("Press enter to end");
            Console.ReadLine();
        }
    }
}