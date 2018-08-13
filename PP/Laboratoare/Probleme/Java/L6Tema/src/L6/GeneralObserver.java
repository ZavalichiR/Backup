package L6;

import java.util.Observable;
import java.util.Observer;

public class GeneralObserver implements Observer{

	public void update(Observable o, Object arg) {
		System.out.println("=========Update nave: " + arg+"=========");
		
	}
	
}