package canvas;

import java.awt.*;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

@SuppressWarnings("serial")
public class Fabrica extends Frame implements Factory{
	Draw a;
	Frame f;
	
	public Fabrica(){
		f=new Frame();
		f.setSize(500,500);
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
	}
	public Nava make(String nume){
		a=new Draw(nume);
		if(nume.equals("patrat")){
			return new Patrat(f,a);
		}
		else if(nume.equals("cerc")){
			return new Cerc(f,a);
		}
		else if(nume.equals("triunghi")){
			return new Triunghi(f,a);
		}
		else{
			System.out.println("NAVA INEXISTENTA");
			return null;
		}
	}
	
}
