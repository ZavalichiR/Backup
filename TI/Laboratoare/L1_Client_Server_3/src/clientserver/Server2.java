package clientserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.SocketException;
import java.util.Vector;

public class Server2 {

    public static void main(String[] args) throws IOException {
		
        ServerSocket ss = new ServerSocket(5678); 
        try {
            while(true) {
                Socket s = ss.accept();
                PrintWriter socketWriter = new PrintWriter(s.getOutputStream(), true);
                BufferedReader socketReader = new BufferedReader(new InputStreamReader(s.getInputStream()));
                BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));

                socketWriter.println("\t\tWelcome to MyServer!");
				socketWriter.println("Write your text: ");

                new Thread() { 
                    public void run() {
                        try {
                            String line = null;
                            while(true) {
                                try {
                                    line = socketReader.readLine();
                                } catch (SocketException e) {
                                    System.exit(0);
                                }
                                if (line.equals("bye"))
                                {
                                    s.close();
                                    System.exit(0);
                                }
                                System.out.println("[CLIENT] : " + line);

                            }
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                }.start();

                new Thread() {
                    public void run() {
                        String line;

                        try {
                            while (true)
                            {
                                line = consoleReader.readLine();
                                socketWriter.println("[SERVER] : " + line);
                                if (line.equals("bye"))
                                {
                                    s.close();
                                    System.exit(0);
                                }
                            }
                        } catch (IOException e) {
                            e.printStackTrace();
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