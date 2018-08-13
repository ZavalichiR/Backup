package TipuriFoc;

import java.awt.Frame;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;



@SuppressWarnings("serial")
public class FabricaFoc extends Frame implements Factory2{
	draw a;
	Frame f;
	
	public FabricaFoc(){
		f=new Frame();
		f.setSize(400,400);
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
	}
	public Fire make(String nume){
		a=new draw(nume);
		if(nume.equals("mitraliera")){
			return new Mitraliera(f,a);
		}
		else if(nume.equals("blast")){
			return new Blaster(f,a);
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


interface Factory2{
	Fire make(String nume);
}
interface Fire{
	public void afisare();
}
