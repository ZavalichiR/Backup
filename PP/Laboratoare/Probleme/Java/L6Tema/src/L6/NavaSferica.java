package L6;

import java.util.Observable;


public class NavaSferica extends Nave{
	NavaSferica(String newColor,Munitie tipM){
		super(newColor,tipM);
	}
	public void informatiiNava()
	{
		System.out.println("  Nava: SFERICA");
		super.informatiiNava();
	}
	public void update(Observable o, Object arg) {
		//System.out.println("Nava3 primeste informatii de la Nava1: " + arg);
		System.out.println("====-UPDATE-=====Nava SFERICA " + arg+".");
	}
}
