package foc;

import java.awt.Button;
import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;



@SuppressWarnings("serial")
public class Fabrica extends Frame implements Factory{
	Draw a;
	Frame f;
	Button b;
	String nm;
	
	public Fabrica(){
		f=new Frame();
		f.setSize(400,400);
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
	}
	public Foc make(String nume){
		nm=nume;
		a=new Draw(nume);
		if(nume.equals("mitraliera")){
			return new Mitraliera(f,a);
		}
		else if(nume.equals("blast")){
			return new Blast(f,a);
		}
		else if(nume.equals("rachete")){
			return new Racheta(f,a);
		}
		else{
			System.out.println("NAVA INEXISTENTA");
			return null;
		}
	}
}
