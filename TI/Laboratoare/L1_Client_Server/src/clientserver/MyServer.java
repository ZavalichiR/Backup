package clientserver;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.net.ServerSocket;
import java.net.Socket;


public class MyServer {
	public static void main(String[] args) throws IOException {
        // pornește un server pe portul 5678 
        ServerSocket ss = new ServerSocket(5678);
        
        // așteaptă conectarea unui client la server
        // metoda accept este blocantă
        // s - socket-ul clientului conectat
        Socket s = ss.accept();
        
        // socketWriter - wrapper peste fluxul de ieșire folosit pentru a transmite date clientului
        PrintWriter socketWriterToServer = new PrintWriter(s.getOutputStream(), true);
        
        // socketReader - wrapper peste fluxul de intrare folosit pentru a primi date de la client
        BufferedReader socketReaderFromClient = new BufferedReader(new InputStreamReader(s.getInputStream()));
        
        // consoleReader - wrapper peste intrarea de la consolă; folosit pentru a citi o linie de text de la consolă 
        BufferedReader consoleReader = new BufferedReader(new InputStreamReader(System.in));

        // trimiterea mesajului ”hello” la client
        socketWriterToServer.println("Welcome to MyServer!");
        
        // are loc un dialog între server și client care se termină în momentul în care clientul trimite textul ”bye” 
        String line;
        while(!(line = socketReaderFromClient.readLine()).equals("bye")) {
        	
            // mesajul primit de la client este afișat la consola serverului
            System.out.println(line);
            
            // este citit un mesaj introdus la consola serverului
            line = consoleReader.readLine();
            
            // mesajul citit este transmis la client
            socketWriterToServer.println(line);
        }
        socketWriterToServer.println("bye");
        
        // închide conexiunea cu clientul
        // la apelul metodei close() se închid automat fluxurile de intrare și ieșire (socketReader și socketWriter)
        s.close();
        
        // închide serverul
        ss.close();
    }
}
