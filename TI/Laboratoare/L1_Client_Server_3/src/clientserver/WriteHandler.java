package clientserver;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.Socket;
import java.util.LinkedList;
import java.util.Queue;

public class WriteHandler extends Thread{
	
	private Boolean ok=true;
	private Queue <String> mesaje=new LinkedList<String>();
	private PrintWriter socketWriter;
	private Socket s;
	
	 public WriteHandler(PrintWriter writer, Socket socket)
	 {
		 this.s=socket;
		 this.socketWriter=writer;	 
	 }
	 public void run() {

         try {
             while (ok)
             {
                 if(!mesaje.isEmpty())
                 {
                	 
                	 socketWriter.println(mesaje.remove());
                 }
             }
             s.close();
            
         } catch (IOException e) {
             e.printStackTrace();
         }
     }
	 
	public void closeWriter()
	{
		ok=false;
	}
	public void addMessage(String msg) {
		mesaje.add(msg);
	}
}
