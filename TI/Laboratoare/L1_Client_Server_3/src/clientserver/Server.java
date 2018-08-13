package clientserver;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;

public class Server {

	private ArrayList<Handler> listaClienti=new ArrayList<Handler>(0);
	public static void main(String[] args) throws Exception {	
        
    	Server sv=new Server();
    	
    }
    
    
    public Server() throws Exception
    {
    	ServerSocket ss = null;
		try {
			ss = new ServerSocket(5678);
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		} 
        try {
            while(true) {
                Socket s = ss.accept();
                Handler client = new Handler(s,this);
                listaClienti.add(client);
                client.run();
              
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
        finally {
            ss.close();
        }
    }
    public void broadcastMessage(String msg)
	{

		for (Handler client : listaClienti) {
			client.sendMessage(msg);
		}
	}
}
