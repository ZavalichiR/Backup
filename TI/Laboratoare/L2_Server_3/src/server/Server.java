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
        	File dir=new File("E:"+path);  //path- directorul dat la browser "Nu merge Filme\aa\b -incurca /"
        	StringBuilder sb =new StringBuilder();
        	String body = null;
        	String head = null;
        	
        	if(dir.exists() && dir.isDirectory())
        	{
        		for(String f: dir.list()){
        			sb.append(f).append("\r\n");
        		}
        		body = sb.toString();
        		head="Http/1.1 200 OK";
        	}
        	else
        	{
        		head="Http/1.1 401 NOT FOUNT";
            	body="Error";
        	}
        	
        	String out;
        	byte [] file=Zip.compress(body);
        	out="Dimensiune Director: "+body.length()+"\nDimensiune arhiva: "+file.length;
        	System.out.println(out);
        	socketWriter.println(head);
        	socketWriter.println("Content-Length: "+file.length);
        	
        	socketWriter.println("Content-encoding: gzip");
        	socketWriter.println("Content-Type: text/plain");
        	socketWriter.println();
        	//socketWriter.println(out);
        	s.getOutputStream().write(file,0,file.length);
        	
        	s.close();
        	
        }
    }
}

