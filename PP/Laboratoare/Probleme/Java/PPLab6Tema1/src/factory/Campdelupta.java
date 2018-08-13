package factory;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.ComponentEvent;
import java.awt.event.ComponentListener;
import java.util.Random;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import factory.CubeShip;
import factory.PyramidalShip;
import factory.SphericalShip;
import factory.Ship;

public class Campdelupta extends JFrame{
	Ship ships[]=new Ship[20];
	int id=0;
	JPanel p;
	JPanel p_bg;
	JLabel l_bg;
	Image i_Background;
	Image i_cube;
	Image i_pyramidal;
	Image i_spherical;
	boolean flag_cube=false;
	boolean flag_pyramidal=false;
	boolean flag_spherical=false;
	Campdelupta(){
		p=new JPanel(new BorderLayout());
		this.setContentPane(p);
		this.setTitle("Battlefield");
		
		ImageIcon ii_bg = new ImageIcon("C:\\Users\\Raduku\\Desktop\\battlefield.jpg","Campul de lupta!");
		i_Background=ii_bg.getImage();
		
		ImageIcon ii_f = new ImageIcon("C:\\Users\\Raduku\\Desktop\\cube.jpg");
		i_cube=ii_f.getImage();
		
		ImageIcon ii_fr = new ImageIcon("C:\\Users\\Raduku\\Desktop\\pyramidal.png");
		i_pyramidal=ii_fr.getImage();
		
		ImageIcon ii_int = new ImageIcon("C:\\Users\\Raduku\\Desktop\\spherical.png");
		i_spherical=ii_int.getImage();
		
		JPanel p_N=new JPanel(new FlowLayout());
		p_N.setBackground(Color.DARK_GRAY);
		p.add(p_N,BorderLayout.NORTH);
		final JButton b_cube=new JButton("Cube");
		final JButton b_pyramidal=new JButton("Pyramidal");
		final JButton b_spherical=new JButton("Spherical");
		b_cube.setIcon(new ImageIcon("C:\\Users\\Raduku\\Desktop\\cube.jpg"));
		b_pyramidal.setIcon(new ImageIcon("C:\\Users\\Raduku\\Desktop\\pyramidal.png"));
		b_spherical.setIcon(new ImageIcon("C:\\Users\\Raduku\\Desktop\\spherical.png"));
		p_N.add(b_cube);
		p_N.add(b_pyramidal);
		p_N.add(b_spherical);
		final JTextField tfnoe=new JTextField("0",20);
		p_N.add(tfnoe);
		ActionListener al=new ActionListener(){ //clasa anonima
			public void actionPerformed(ActionEvent e){
				if(e.getSource()==b_cube)
				{
					flag_cube=true;
					l_bg.paint(l_bg.getGraphics());
				}
				if(e.getSource()==b_pyramidal)
				{
					flag_pyramidal=true;
					l_bg.paint(l_bg.getGraphics());
				}
				if(e.getSource()==b_spherical)
				{
					flag_spherical=true;
					l_bg.paint(l_bg.getGraphics());
				}
			}
		};
		b_cube.addActionListener(al);
		b_pyramidal.addActionListener(al);
		b_spherical.addActionListener(al);
		
		l_bg=new JLabel(){
			Random rnd=new Random();
			public void paint(Graphics g){
				
				if(id<20)
				{
					int x=rnd.nextInt(500);
					int y=rnd.nextInt(400);
					if(flag_cube)
					{
						flag_cube=false;
						try {
							ships[id++]=new CubeShip("blue",FireTypeFactory.getForm(FireTypeFactory.LINEAR,"mitraliera"));
						} catch (Exception e) {
							e.printStackTrace();
						}
						Color c=new Color(rnd.nextInt(10000000));
						int w=rnd.nextInt(500);
						int h=rnd.nextInt(500);
						g.setColor(c);
						g.fillRect(x,y,w,h);
						Campdelupta.super.setVisible(true);
					}
					if(flag_pyramidal)
					{
						flag_pyramidal=false;try {
							ships[id++]=new CubeShip("yellow",FireTypeFactory.getForm(FireTypeFactory.BLAST,"minge de foc"));
						} catch (Exception e) {
							e.printStackTrace();
						}
						Color c=new Color(rnd.nextInt(10000000));
						int w=rnd.nextInt(500);
						int h=rnd.nextInt(500);
						g.setColor(c);
						g.fillArc(x,y,w,h,30,120);
						Campdelupta.super.setVisible(true);
					}
					if(flag_spherical)
					{
						flag_spherical=false;
						try {
							ships[id++]=new CubeShip("green",FireTypeFactory.getForm(FireTypeFactory.ROCKET,"multi cilindri"));
						} catch (Exception e) {
							e.printStackTrace();
						}
						int r=rnd.nextInt(500);
						Color c=new Color(rnd.nextInt(10000000));
						g.setColor(c);
						g.fillOval(x,y,r,r);
						Campdelupta.super.setVisible(true);
					}
					tfnoe.setText(""+id);
				}
			}
		};
		this.addComponentListener(new ComponentListener() {
		    public void componentResized(ComponentEvent e) {
		    	id=0;
		    }
			public void componentHidden(ComponentEvent arg0) {
				id=0;
			}
			public void componentMoved(ComponentEvent arg0) {
				id=0;
			}
			public void componentShown(ComponentEvent arg0) {
				id=0;
			}
		});
		p.add(l_bg,BorderLayout.CENTER);
		
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setPreferredSize(new Dimension(1500,1000));
		this.pack();
	}
}
