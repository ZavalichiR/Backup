package clientserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.Socket;

final class Client {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		
		Socket s=new Socket("localhost", 5678);
		
		PrintWriter socketWriter = new PrintWriter(s.getOutputStream(), true);
        BufferedReader socketReader = new BufferedReader(new InputStreamReader(s.getInputStream()));
        BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));
        
        new Thread(){
        	public void run()
        	{
        		String line;
        		//citeste de la server
        		try {
					while(!(line=consoleReader.readLine()).equals("bye"))
					{
						//scrie la client
						socketWriter.println(line);
					}
					s.close();
					System.exit(0);
				} catch (IOException e) {
					// TODO Auto-generated catch block
					e.printStackTrace();
				}
        	}
        }.start();
        
        new Thread(){
        	public void run()
        	{
        		String line;
        		try{
        			while(!s.isClosed())
        			{
        				//citeste de la server si afiseaza la consola Eclipse
        				line=socketReader.readLine();
        				System.out.println(line);
        			}
        		}catch(Exception e){
        			e.printStackTrace();
        		}  
        	}
        }.start();
	  }
		

}
