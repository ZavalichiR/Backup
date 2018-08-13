package Fabrica;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

public class Rachete implements Foc{
public void draw(){
	JFrame f = new JFrame();
	f.setSize(1000,800);
	f.add(new MyLine());
	f.setVisible(true);
	f.addWindowListener(new WindowAdapter(){
		@SuppressWarnings("unused")
		public void WindowLClosing(WindowEvent e){
			f.dispose();
			System.exit(0);
		}
	});
	
}
}

@SuppressWarnings("serial")
class MyLine extends Canvas{
	public void paint(Graphics g){
		g.setColor(Color.red);
		g.fillRect(50, 50, 20, 200);
		g.fillRect(80,50,20,200);
		g.fillRect(110,50,20,200);
	}
}