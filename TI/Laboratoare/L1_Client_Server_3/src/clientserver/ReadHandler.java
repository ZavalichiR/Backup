package clientserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.net.SocketException;

public class ReadHandler extends Thread{
	private Handler parent=null;
	private Boolean ok=true;
	private BufferedReader socketReader;
	public ReadHandler(BufferedReader reader, Handler handler)
	{
		this.parent=handler;
		this.socketReader=reader;
	}
	
	public void run() {
        try {
            String line = null;
            while(ok) {
                try {
                    line = socketReader.readLine();
                } catch (SocketException e) {
                    System.exit(0);
                }
                if (line.equals("bye"))
                {
                    System.exit(0);
                }
                System.out.println("[CLIENT  "+parent.s.getPort()+" ] :" + line);
                parent.reciveMessage(line);

            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
	
	public void closeReader()
	{
		ok=false;
	}
	
}
