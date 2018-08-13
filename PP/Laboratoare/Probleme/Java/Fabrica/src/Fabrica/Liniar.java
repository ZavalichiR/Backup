package Fabrica;

import javax.swing.*;
import java.awt.event.*;
//import java.io.*;
import java.awt.*;

public class Liniar implements Foc{
public void draw(){
	JFrame f = new JFrame();
	f.setSize(1000,800);
	f.add(new MyRectangle());
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
class MyRectangle extends Canvas{
	public void paint(Graphics g){
		g.setColor(Color.red);
		g.fillRect(50, 50, 20, 100);
		g.fillRect(50,50,50,20);
	}
}