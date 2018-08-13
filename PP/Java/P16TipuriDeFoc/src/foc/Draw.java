package foc;

import java.awt.*;

@SuppressWarnings("serial")
public class Draw extends Canvas{
	String name;
	Draw(String nume){
		name=nume;
	}
	
	public void paint(Graphics g){
		g.setColor(Color.black);
		g.fillRect(20, 60, 150, 50);
		g.fillRect(30, 100, 30, 30);
		if(name.equals("mitraliera")){
			g.setColor(Color.black);
			g.fillRect(240, 80, 10, 10);
			g.fillRect(260, 80, 10, 10);
			g.fillRect(280, 80, 10, 10);
			g.fillRect(300, 80, 10, 10);
			g.fillRect(320, 80, 10, 10);
		}
		if(name.equals("blast")){
			g.setColor(Color.red);
			g.fillOval(210, 40, 80, 80);
			g.setColor(Color.yellow);
			g.drawOval(210, 40, 81, 81);
			g.drawOval(210, 40, 82, 82);
			g.drawOval(210, 40, 83, 83);
			g.drawOval(210, 40, 84, 84);
			g.drawOval(210, 40, 85, 85);
			g.drawOval(210, 40, 86, 86);
			g.drawOval(210, 40, 87, 87);
		}
		if(name.equals("rachete")){
			g.setColor(Color.GRAY);
			g.fillRect(240, 65, 100, 10);
			g.fillRect(240, 80, 100, 10);
			g.fillRect(240, 95, 100, 10);
		}
		
	}
}
