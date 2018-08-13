package Fabrica;

import javax.swing.*;
import java.awt.event.*;
//import java.io.*;
import java.awt.*;

public class Blast implements Foc{
public void draw(){
	JFrame f = new JFrame();
	f.setSize(1000,800);
	f.add(new MyCircle());
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
class MyCircle extends Canvas{
	public void paint(Graphics g){
		g.setColor(Color.yellow);
		g.fillOval(30, 30, 120, 120);
	}
}