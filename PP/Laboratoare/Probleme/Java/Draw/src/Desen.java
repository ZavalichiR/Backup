
import javax.swing.*;
import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Graphics;
import java.awt.event.*;
import java.util.Random;

public class Desen extends JFrame{

	JPanel p3;
	public Desen()
	{
		super("Desen"); //Constructor din clasa JFrame, Desen-numele ferestrei
		//JPanel p=new JPanel(); //pozitioneaza elementele una dupa alta-buton, text, panel
		JPanel p=new JPanel(new BorderLayout());
		this.setContentPane(p);
		JPanel p2=new JPanel();//new FlowLayout
		p.add(p2,BorderLayout.NORTH); //adauga panoul p2 la panoul p in nord
		final JTextField tf=new JTextField("100",20); //const
		p2.add(tf); //pune ferestra text in p2.
		JButton b=new JButton("Cerc");
		p2.add(b);
		
		
		//ACtionListener interfata, nu poate instantia, folosim o clasa nou anonima
		// se executa doar cand se da click
		ActionListener al=new ActionListener(){
			public void actionPerformed(ActionEvent e){
				//p3.repaint(); //trebuie sa fie local si constat ( se pune ca proprietate)
				p3.paint(p3.getGraphics());
			}
		};
		b.addActionListener(al); // se da click pe butonul b si se apeleaza ActionListener
		p3=new JPanel(){
			Random rnd=new Random();
			public void paint(Graphics g){
				int r=Integer.parseInt(tf.getText());
				int x=rnd.nextInt(500);
				int y=rnd.nextInt(400);
				Color c=new Color(rnd.nextInt(256),rnd.nextInt(256),rnd.nextInt(256));
				g.setColor(c);
				g.fillOval(x,y,r,r);
				//g.fillRect(x, y, r, r);
			}
		};
		p.add(p3);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setPreferredSize(new Dimension(500,400));
		this.pack(); // redimensiuoneaza fereastra
	}
	
	public static void main(String[] args){
		new Desen().setVisible(true); // same d =new desen, d.set ..
	}
}
