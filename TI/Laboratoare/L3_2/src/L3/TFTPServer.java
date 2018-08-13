package L3;

import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.io.File;
import java.io.FileInputStream;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.ArrayList;
import javax.swing.*;

public class TFTPServer extends JFrame {
    private static final long serialVersionUID = 1L;
    private Container pane;
    private ArrayList<Integer> portList;
    private ArrayList<byte[]> dataList;
    private ArrayList<byte[]> bufList;

    public TFTPServer() {
        super("File transfer protocol");
        pane = this.getContentPane();
        pane.setLayout(new BoxLayout(pane, BoxLayout.Y_AXIS));
        // când se închide fereastra se închide și aplicația
        this.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        // dimensiunea ferestrei
        this.setPreferredSize(new Dimension(600, 300));
        // dimensionarea ferestrei
        this.pack();
        this.setBackground(Color.GREEN);
        portList = new ArrayList<Integer>();
        dataList = new ArrayList<byte[]>();
        bufList = new ArrayList<byte[]>();
    }

    public void startServer() throws UnknownHostException, IOException, FileNotFoundException {
        
    	DatagramSocket socket = new DatagramSocket(69);
        System.out.println(socket.getLocalAddress() + "; " + socket.getLocalPort() + "; " +socket.getInetAddress() + "; " + socket.getPort());

        while (true) {
            
            byte[] buf = new byte[516];
            DatagramPacket packet;
            packet = new DatagramPacket(buf, buf.length);	
            socket.receive(packet);

            // verificam de la cine am primit pachetul
            if (!portList.contains(socket.getPort())) // daca am primit pachetul de la un client nou
            {
                portList.add(packet.getPort()); // adaugam portul clientului in lista
                dataList.add(packet.getData()); // datele primite
                bufList.add(new byte[516]); // buffer
            }
            else // client existent, deci setam datele corespunzatoare lui
            {
            	System.out.println("\n\t\t\tClient existent\n");
                dataList.set(portList.indexOf(packet.getPort()), packet.getData());
            }

            // afișarea informațiilor referitoare la pachetul primit și conținutul acestuia
            System.out.println(packet.getAddress() + "; " + packet.getPort() + "; " + packet.getLength() + "; " + packet.getOffset());
            System.out.println(new String(packet.getData()));

            /*
            * opcode operation ‐ cele cinci tipuri mesaje care pot fi transmise
            * 01 Read request (RRQ)
            * 02 Write request (WRQ)
            * 03 Data (DATA)
            * 04 Acknowledgment (ACK)
            * 05 Error (ERROR)
            */
            // prelucrarea/citirea informațiilor primite de la client
            // 01 Read request (RRQ)
            /*
            * 2 bytes string 1 byte string 1 byte
            * ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
            * | Opcode | Filename | 0 | Mode | 0 |
            * ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
            */

            int opcode; // operația ‐ ar trebui să fie doi octeți și anume 01
            String filename; // numele fișierului care se dorește a fi transmis de către server
            String mode; // modul ‐ poate fi: netascii, octet, mail
            // TODO inițializați variabilele opcode, filename și mode prin prelucrarea vectorului de octeți data
            //

            opcode = (dataList.get(portList.indexOf(packet.getPort()))[0] << 8) | dataList.get(portList.indexOf(packet.getPort()))[1];

            // aflam intervalul de octeti in care se afla numele fisierului ( [start, end] )
            int start, end;
            start = end = 2;
            for (int i = start; i < dataList.get(portList.indexOf(packet.getPort())).length; ++i) {
                if (dataList.get(portList.indexOf(packet.getPort()))[i] == 0) {
                    end = i;
                    break;
                }
            }

            // construim sirul de caractere filename din sirul de octeti aflati
            filename = new String(dataList.get(portList.indexOf(packet.getPort())), start, end - start);

            // aflam intervalul de octeti in care se afla modul ( [start, end] )
            start = end = end + 1; // pornim de la end + 1 ca sa sarim peste octetul de valoare 0 de dupa ce s-a terminat
            // string-ul filename
            for (int i = start; i < dataList.get(portList.indexOf(packet.getPort())).length; ++i) {
                if (dataList.get(portList.indexOf(packet.getPort()))[i] == 0) {
                    end = i;
                    break;
                }
            }

            // construim sirul de caractere mode din sirul de octeti aflati
            mode = new String(dataList.get(portList.indexOf(packet.getPort())), start, end - start);

            // 03 Data (DATA)
            /*
            * 2 bytes 2 bytes n bytes
            * ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
            * | Opcode | Block # | Data |
            * ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
            */

            // deschiderea fișierului filename din directorul cu numele fisiere (aflat în același director cu proiectul)
            // conținutul fișierului este trimis în blocuri de 512 octeți
            File f = new File("fisiere", filename);
            if (f.exists()) {
                try {
                    FileInputStream fis = new FileInputStream(new File("fisiere", filename));

                    // se inițializează un progressBar
                    JProgressBar progressBar = new JProgressBar(0, (int) f.length());
                    // textul de pe progressBar
                    progressBar.setString(filename);
                    progressBar.setStringPainted(true);
                    progressBar.setVisible(true);
                    progressBar.setBackground(Color.BLUE);
                    // se adaugă progressBar‐ul în interfața grafică
                    
                    pane.add(progressBar);
                    pane.setBackground(Color.GREEN);
                    pack();
                    pane.repaint();

                    // progresul curent in transmiterea fisierului
                    int progress = 0;

                    // numărul blocului
                    int blockNumber = 0;
                    int len;
                    // adresa și portul unde se transmit pachetele
                    InetAddress address = packet.getAddress();
                    int port = packet.getPort();
                    do {
                        bufList.set(portList.indexOf(port), new byte[516]);
                        // codul operației efectuate
                        bufList.get(portList.indexOf(port))[0] = 0;
                        bufList.get(portList.indexOf(port))[0] = 0;
                        bufList.get(portList.indexOf(port))[1] = 3;
                        // numărul pachetului
                        ++blockNumber; // primul număr al pachetului este 1
                        bufList.get(portList.indexOf(port))[2] = (byte) ((blockNumber >> 8) & 0xFF);
                        bufList.get(portList.indexOf(port))[3] = (byte) (blockNumber & 0xFF);
                        // citirea a maxim 512 octeți din fișier care sunt puși începând cu poziția 4 în buffer
                        len = fis.read(bufList.get(portList.indexOf(port)), 4, 512);
                        System.out.println("len read: " + len);
                        if (len == -1) {
                            len = 0;
                        }
                        // crearea și trimiterea pachetului
                        packet = new DatagramPacket(bufList.get(portList.indexOf(port)), len + 4, address, port);
                        socket.send(packet);

                        // actualizarea progress bar-ului
                        progress += len;
                        progressBar.setValue(progress);
                        progressBar.repaint();

                        if (len == 512) {
                            // primirea mesajului de confirmare a primirii de către client a pachetului transmis

                            // 04 Acknowledgment (ACK)
                            /*
                            * 2 bytes 2 bytes
                            * ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
                            * | Opcode | Block # |
                            * ‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
                            */

                            bufList.set(portList.indexOf(port), new byte[516]);
                            DatagramPacket packet2 = new DatagramPacket(bufList.get(portList.indexOf(port)), bufList.get(portList.indexOf(port)).length);
                            socket.receive(packet2);

                            if (portList.contains(socket.getPort())) // daca pachetul primit este de la un client existent
                            {
                                System.out.println(packet2.getAddress() + "; " + packet2.getPort() + "; " + packet2.getLength() +
                                        "; " + packet2.getOffset());
                                // verificarea dacă mesajul primit este de Acknowledgment
                                if (bufList.get(portList.indexOf(port))[1] == 4) {
                                    // verificarea ultimului block primit de către client
                                    int blockNumber2 = (bufList.get(portList.indexOf(port))[2] << 8) | (bufList.get(portList.indexOf(port))[3] & 0xFF);
                                    if (blockNumber2 != blockNumber) {
                                        // dacă clientul nu a primit pachetul
                                        throw new RuntimeException("Eroare: nr. de bloc trebuia sa fie #" + blockNumber +
                                                ", dar s‐a primit #" + blockNumber);
                                    }
                                } else {
                                    // dacă clientul nu a primit pachetul
                                    throw new RuntimeException("Eroare: tipul mesajului trebuia să fie de ACK(4), dar s‐a primit " +
                                            bufList.get(portList.indexOf(port))[1]);
                                }
                            }
                            else // altfel il adaugam in lista de clienti
                            {
                                portList.add(packet.getPort()); // adaugam portul clientului in lista
                                dataList.add(packet.getData()); // datele primite
                                bufList.add(new byte[516]); // buffer
                            }
                        }
                        else
                        {
                            dataList.remove(portList.indexOf(port));
                            portList.remove(portList.indexOf(port));
                        }
                    } while (len == 512);
                    // închiderea fișierului
                    fis.close();
                } catch (FileNotFoundException e) {
                }
            } else {
                // tratarea erorii in care fisierul nu a fost gasit
                String errorMessage = "File not found on server!";
                buf = new byte[5 + errorMessage.length()];
                int len = buf.length;
                // codul operației efectuate
                buf[0] = 0;
                buf[1] = 5;
                // codul de eroare
                buf[2] = 0;
                buf[3] = 1;
                // mesajul de eroare propriu zis
                byte[] byteArrayError = errorMessage.getBytes();
                for (int i = 0; i < byteArrayError.length; ++i) // copiem vectorul de octeti din String in byte array
                {
                    buf[i + 4] = byteArrayError[i];
                }
                // 0
                buf[len - 1] = 0;

                // adresa și portul unde se transmit pachetele
                InetAddress address = packet.getAddress();
                int port = packet.getPort();

                // crearea și trimiterea pachetului de eroare
                packet = new DatagramPacket(buf, len, address, port);
                socket.send(packet);
            }
        }

        // închiderea socket‐ului
        // socket.close();
    }

    public static void main(String[] args) throws IOException {
        TFTPServer server = new TFTPServer();
        server.setVisible(true);
        server.startServer();
    }
}
