package factory;

import java.util.Observable;
import java.util.Observer;

public class PyramidalShip extends Ship{
	PyramidalShip(String newColor,FireType newft){
		super(newColor,newft);
	}
	public void seeInfo()
	{
		System.out.println("Ship TYPE: PYRAMIDAL");
		super.seeInfo();
	}
	public void update(Observable o, Object arg) {
		System.out.println("S2 - Info about S1: " + arg);
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
