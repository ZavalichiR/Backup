package factory;

import java.util.Observable;
import java.util.Observer;

public class CubeShip extends Ship{
	CubeShip(String newColor,FireType newft){
		super(newColor,newft);
	}
	public void seeInfo()
	{
		System.out.println("Ship TYPE: CUBE");
		super.seeInfo();
	}
	public void update(Observable o, Object arg) {
		System.out.println("S1 - Info about S3: " + arg);
		
	}
}
