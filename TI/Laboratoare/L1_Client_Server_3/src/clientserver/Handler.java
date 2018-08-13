package clientserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;


public class Handler extends Thread{
	
	public Socket s;
	private WriteHandler wr=null;
	private Server parent;
	
	public Handler(Socket socket,Server server)
	{
		this.parent=server;
		this.s=socket;
	}
	
	public void reciveMessage(String msg)
	{
	    parent.broadcastMessage(msg);	
	}
	public void sendMessage(String msg)
	{
		wr.addMessage(msg);
	}
	
	public void run()
	{
		PrintWriter socketWriter=null;
		try {
			socketWriter = new PrintWriter(s.getOutputStream(), true);
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
        BufferedReader socketReader = null;
		try {
			socketReader = new BufferedReader(new InputStreamReader(s.getInputStream()));
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}


        socketWriter.println("\t\tWelcome to MyServer!");
		socketWriter.println("Write your text: ");

		
        ReadHandler rh=new ReadHandler(socketReader,this);
        rh.start();
        
        wr=new WriteHandler(socketWriter,s);
        wr.start();
	}
	
	
}
