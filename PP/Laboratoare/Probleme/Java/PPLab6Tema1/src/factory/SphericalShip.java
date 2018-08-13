package factory;

import java.util.Observable;
import java.util.Observer;

public class SphericalShip extends Ship{
	SphericalShip(String newColor,FireType newft){
		super(newColor,newft);
	}
	public void seeInfo()
	{
		System.out.println("Ship TYPE: SPHERICAL");
		super.seeInfo();
	}
	public void update(Observable o, Object arg) {
		System.out.println("S3 - Info about S2: " + arg);
	}
}
