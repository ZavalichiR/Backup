package server;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;


public class Server {
	public static void main(String[] args) throws IOException {

        ServerSocket ss = new ServerSocket(5678);
        
        while(true)
        {
        	Socket s = ss.accept(); 
        	
        	PrintWriter socketWriter = new PrintWriter(s.getOutputStream(), true);
            BufferedReader socketReader = new BufferedReader(new InputStreamReader(s.getInputStream()));
            
            
        	String line=socketReader.readLine(); 
        	String path=line.split(" ")[1];
        	
            path="S-a trimis: "+path;
        	socketWriter.println("Http/1.1 200 OK");
        	socketWriter.println("Content-Length: "+path.length());
        	socketWriter.println("Content-Type: text/plain");

        	socketWriter.println();
        	socketWriter.println(path);
 
        	s.close();
        	
        }
       // ss.close();
    }
}

