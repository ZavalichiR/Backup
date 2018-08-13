package l3;

import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.UnknownHostException;

public class TFTPServer {

	public static void main(String[] args) throws UnknownHostException, IOException {
		// socket folosit pentru a primi și transmite datagrame (serverul este pornit pe portul 69 - default pentru TFTP)
        DatagramSocket socket = new DatagramSocket(69);
        // afișarea informațiilor referitoare la socket-ul creat
        System.out.println(socket.getLocalAddress()+"; "+socket.getLocalPort() + "; "+ socket.getInetAddress() + "; "+socket.getPort());
        // buffer in care se primesc datele
        byte[] buf = new byte[516];
        // pachet care conține informațiile necesare primirii/trimiterii unui mesaj
        DatagramPacket packet;
        packet = new DatagramPacket(buf, buf.length);
        // primirea unui pachet
        socket.receive(packet);
        // afișarea informațiilor referitoare la pachetul primit și conținutul acestuia
        System.out.println(packet.getAddress() + "; " + packet.getPort() + "; " + packet.getLength() + "; " + packet.getOffset());
        // datele primite se găsesc în vectorul de octeți buf care a fost transmis ca argument la constructorul DatagramPacket
        System.out.println(new String(buf));
        /*
         * opcode operation - cele cinci tipuri mesaje care pot fi transmise 
         * 01 Read request (RRQ)
         * 02 Write request (WRQ)
         * 03 Data (DATA)
         * 04 Acknowledgment (ACK)
         * 05 Error (ERROR)
         */
        // prelucrarea/citirea informațiilor primite de la client
        // 01 Read request (RRQ)
        /*
         * 2 bytes    string    1 byte  string  1 byte
         * ------------------------------------------------
         * | Opcode | Filename |   0   | Mode |   0   |
         * ------------------------------------------------
         */
        int opcode; // operația - ar trebui să fie doi octeți și anume 01
        String filename; // numele fișierului care se dorește a fi transmis de către server 
        String mode; // modul - poate fi: netascii, octet, mail
        //TODO inițializați variabilele opcode, filename și mode prin prelucrarea vectorului de octeți data        
        //
        opcode=(buf[0]<<8)|buf[1];
        int start=2;
        int i=start;
        int end=start;
        while(buf[i]!=0)
        {
        	i++;
        }
        end=i;
        filename=new String(buf,start,end-start);
        start=i+1;
        i=start;
        while(buf[i]!=0)
        {
        	i++;
        }
        end=i;
        mode=new String(buf,start,end-start);
        
        System.out.println("Opcode: "+opcode+"\tFilename: "+filename+"\tMode: "+mode);
        // 03 Data (DATA)
        /*
         * 2 bytes   2 bytes   n bytes
         * ----------------------------------
         * | Opcode | Block # | Data |
         * ----------------------------------
         */
        // deschiderea fișierului filename din directorul cu numele fisiere (aflat în același director cu proiectul)
        // conținutul fișierului este trimis în blocuri de 512 octeți
        File fisier=new File("fisiere",filename);
        InetAddress address = packet.getAddress();
        int port = packet.getPort();
        if(!fisier.exists())
        {
        	buf=new byte[516];
        	buf[0]=0;
        	buf[1]=5;
        	buf[2]=0;
        	buf[3]=1;
        	String mesajEroare="Eroare!Nu exista fisierul!";
        	byte[] b=mesajEroare.getBytes();
        	int j;
        	for(j=4;j<b.length+4;++j)
        	{
        		buf[j]=b[j-4];
        	}
        	buf[j]=0;
        	System.out.println(new String(buf,4,j-4));
        	packet = new DatagramPacket(buf,j+1, address, port);
            socket.send(packet);
            socket.close();
        }
        else{
        FileInputStream fis = new FileInputStream(fisier);
        // numărul blocului
        int blockNumber = 0;
        int len;
        do {
            buf = new byte[516];
            // codul operației efectuate
            buf[0] = 0;
            buf[1] = 3;
            // numărul pachetului
            ++blockNumber; // primul număr al pachetului este 1
            buf[2] = (byte) ((blockNumber >> 8) & 0xFF);
            buf[3] = (byte) (blockNumber & 0xFF);
            // citirea a maxim 512 octeți din fișier care sunt puși începând cu poziția 4 în buffer
            len = fis.read(buf, 4, 512);
            System.out.println("len read: " + len);
            //TODO de ce este necesară condiția următoare?
            if (len == -1) {
                len = 0;
            }
            // crearea și trimiterea pachetului
            packet = new DatagramPacket(buf, len + 4, address, port);
            socket.send(packet);
            if (len == 512) {
            	// primirea mesajului de confirmare a primirii de către client a pachetului transmis
                // 04 Acknowledgment (ACK)
                /*
                 * 2 bytes    2 bytes
                 * ---------------------
                 * | Opcode | Block # |
                 * ---------------------
                 */
                buf = new byte[516];
                DatagramPacket packet2 = new DatagramPacket(buf, buf.length);
                socket.receive(packet2);
                System.out.println(packet2.getAddress() + "; " + packet2.getPort() + "; " + packet2.getLength() + "; " + packet2.getOffset());
                // verificarea dacă mesajul primit este de Acknowledgment
                if (buf[1] == 4) {
                    // verificarea ultimului block primit de către client
                    int blockNumber2 = (buf[2] << 8) | (buf[3] & 0xFF);
                    if (blockNumber2 != blockNumber) {
                        // dacă clientul nu a primit pachetul
                        throw new RuntimeException("Eroare: nr. de bloc trebuia sa fie #" + blockNumber + ", dar s-a primit #" + blockNumber);
                    }
                } else {
                    // dacă clientul nu a primit pachetul
                    throw new RuntimeException("Eroare: tipul mesajului trebuia să fie de ACK(4), dar s-a primit " + buf[1]);
                }
            }
        } while (len == 512);
        // închiderea fișierului
        fis.close();
        }
        // închiderea socket-ului
        socket.close();
	}

}