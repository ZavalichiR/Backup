package L3;


import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.Map;
import java.util.HashMap;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;

import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JProgressBar;

public class TFTPServer2 extends JFrame  {

	public TFTPServer2()  throws UnknownHostException, IOException, InterruptedException{
		super("ProgressBar test");
		final Container pane = this.getContentPane();
		pane.setLayout(new BoxLayout(pane, BoxLayout.Y_AXIS));
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		this.setPreferredSize(new Dimension(400, 500));
		this.pack();
		this.setVisible(true);
		
		DatagramSocket socket = new DatagramSocket(69);
		FileInputStream fis=null;
		System.out.println(socket.getLocalAddress() + "; " + socket.getLocalPort() + "; " + socket.getInetAddress()+ "; " + socket.getPort());
		
		Map<String, String> hm = new HashMap<String, String>();
		Map<String, FileInputStream> hmfis = new HashMap<String, FileInputStream>();
		Map<String, JProgressBar> hmpb = new HashMap<String, JProgressBar>();
		
		try {
			while (true)
			{
				byte[] buf = new byte[516];
				DatagramPacket packet;
				packet = new DatagramPacket(buf, buf.length);
				socket.receive(packet);
				System.out.println(packet.getAddress() + "; " + packet.getPort() + "; " + packet.getLength() + "; "+ packet.getOffset());
				System.out.println(new String(buf));
				int opcode;
				opcode = (buf[0] << 8) | buf[1];
				if (buf[0] == 0 && buf[1] == 1) // p is RRQ
				{
					String filename;
					String mode;
					int start = 2;
					int i = start;
					int end = start;
					while (buf[i] != 0)
					{
						i++;
					}
					end = i;
					filename = new String(buf, start, end - start);
					start = i + 1;
					i = start;
					while (buf[i] != 0)
					{
						i++;
					}
					end = i;
					mode = new String(buf, start, end - start);
					System.out.println("\nServerul a primit o cerere: ");
					System.out.println("\n\tOpcode: " + opcode + "\tFilename: " + filename + "\tMode: " + mode);
					InetAddress address = packet.getAddress();
					int port = packet.getPort();
					hm.put(address + ":" + port, filename);

					File fisier = new File("fisiere", filename);
					fis = new FileInputStream(fisier);
					System.out.println("\n\tDimensiunea fisierului: "+fisier.length());
					int blockNumber = 1;
					int len;
					buf = new byte[516];
					buf[0] = 0;
					buf[1] = 3;
					buf[2] = (byte) ((blockNumber >> 8) & 0xFF);
					buf[3] = (byte) (blockNumber & 0xFF);
					len = fis.read(buf, 4, 512);
					hmfis.put(address + ":" + port,fis);
					System.out.println("\n" + filename + "--->" + address + ":" + port + "\tlen read: " + len);
					if (len == -1)
					{
						len = 0;
					}
					packet = new DatagramPacket(buf, len + 4, address, port);
					socket.send(packet);

					JProgressBar progressBar = new JProgressBar(0, (int) fisier.length());
					progressBar.setString(filename);
					progressBar.setStringPainted(true);
					progressBar.setValue(len);
					this.setVisible(true);
					Thread.sleep(200);
					progressBar.setBackground(Color.BLUE);
					pane.add(progressBar);
					pane.setBackground(Color.GREEN);
					hmpb.put(address + ":" + port, progressBar);
				}
				else if (buf[0] == 0 && buf[1] == 4)
				{
					int blockNumber = (buf[2] << 8) | buf[3];
					System.out.println("\nServerul a primit o cerere ACK: ");
					System.out.println("\n\tBlock number: " + blockNumber);
					InetAddress address = packet.getAddress();
					int port = packet.getPort();
					String filename = hm.get(address + ":" + port);

					//File fisier = new File("fisiere", filename);
					//FileInputStream fis = new FileInputStream(fisier);
					fis=hmfis.get(address + ":" + port);
					int len;
					buf = new byte[516];
					buf[0] = 0;
					buf[1] = 3;
					blockNumber = blockNumber + 1;
					buf[2] = (byte) ((blockNumber >> 8) & 0xFF);
					buf[3] = (byte) (blockNumber & 0xFF);
					len = fis.read(buf,4, 512);
					hmfis.put(address + ":" + port,fis);
					System.out.println("\n" + filename + "--->" + address + ":" + port + "\tlen read: " + len);
					if (len == -1)
					{
						len = 0;
					}
					packet = new DatagramPacket(buf, len + 4, address, port);
					socket.send(packet);
					//fis.close();

					JProgressBar progressBar = hmpb.get(address + ":" + port);
					int value=progressBar.getValue();
					progressBar.setValue(value + len);
					this.setVisible(true);
					Thread.sleep(200);
					hmpb.put(address + ":" + port, progressBar);
				}
				else
				{
					throw new RuntimeException("Eroare: tipul mesajului trebuia sÄ fie de ACK(4) sau RRQ(1), dar s-a primit " + buf[1]);
				}
			}
		} catch (IOException e) {
		} finally {
			fis.close();
			socket.close();
		}
	}

	public static void main(String[] args) throws UnknownHostException, IOException, InterruptedException {
		new TFTPServer().setVisible(true);
	}

}
