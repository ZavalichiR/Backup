package factory;

import java.util.Observable;
import java.util.Observer;

public class GeneralObserver implements Observer{

	public void update(Observable o, Object arg) {
		System.out.println("Ship info changed: " + arg);
		
	}
	
}
