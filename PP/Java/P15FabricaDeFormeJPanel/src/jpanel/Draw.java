package jpanel;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;

@SuppressWarnings("serial")
public class Draw extends JPanel{
			
	String name;
	Draw(String a){
		name=a;
	}
	public void paint(Graphics g){
		g.setColor(Color.blue);
	
		if(name.equals("patrat")){
			
			g.fillRect(20, 20, 100, 100);
		}
		if(name.equals("cerc")){
			g.setColor(Color.red);
			
			g.fillOval(300, 20, 120,120);
		}
		if(name.equals("triunghi")){
			g.setColor(Color.green);
			int []x=new int[3];
			int []y=new int[3];
			x[0]=70;x[1]=20;x[2]=120;
			y[0]=300;y[1]=420;y[2]=420;
			
			g.fillPolygon(x,y, 3);
		}
	}

}
