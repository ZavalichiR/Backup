package clientserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;

public class MyServer {

    public static void main(String[] args) throws IOException {
    	
        ServerSocket ss = new ServerSocket(5678); 

        try {
            while(true) {
                final Socket s = ss.accept();
                new Thread() {
                    public void run() {
                        try {
                            //scrie clientului
                            PrintWriter socketWriter = new PrintWriter(s.getOutputStream(), true);          
                            //scrie serverului
                            BufferedReader socketReader = new BufferedReader(new InputStreamReader(s.getInputStream()));
                            socketWriter.println("\t\t\tWelcome to MyServer! ");
                            socketWriter.println("Write your text: "); 
                            String line;
                            while(!(line = socketReader.readLine()).equals("bye")) {
                                System.out.println("[CLIENT] :" + line);
                                socketWriter.println("[SERVER] : " + line);
                                socketWriter.println("-----------------");
                                socketWriter.println("Write your text: ");
                            }
                            socketWriter.println("[SERVER]: Good bye my friend");
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                        finally {
                            try {
                                s.close();
                            } catch (IOException e) {
                                e.printStackTrace();
                            }
                        }
                    }
                }.start();
            }
        }
        catch(Exception e) {
            e.printStackTrace();
        }
        finally {
            ss.close();
        }
    }
}