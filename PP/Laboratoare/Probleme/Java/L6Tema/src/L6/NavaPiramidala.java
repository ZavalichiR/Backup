package L6;

import java.util.Observable;
public class NavaPiramidala extends Nave{
	NavaPiramidala(String newColor,Munitie tipM){
		super(newColor,tipM);
	}
	public void informatiiNava()
	{
		System.out.println("  Nava: PIRAMIDA");
		super.informatiiNava();
	}
	public void update(Observable o, Object arg) {
		//System.out.println("Nava2 primeste informatii de la Nava1: " + arg);
		System.out.println("====-UPDATE-=====Nava PIRAMIDA " + arg+".");
	}
	/*
	public void ChangeMessage()
	{
		message=this.getColor()+" "+this.getFireType();
		setChanged();
		notifyObservers(message);
	}
	*/
}