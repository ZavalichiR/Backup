package L6;

import java.util.Observable;
public class NavaCub extends Nave{
	NavaCub(String newColor,Munitie tipM){
		super(newColor,tipM);
	}
	public void informatiiNava()
	{
		System.out.println("  Nava: CUB");
		super.informatiiNava();
	}
	public void update(Observable o, Object arg) {
		//System.out.println("Nava1 primeste informatii de la Nava3: " + arg);
		System.out.println("====-UPDATE-=====Nava CUB " + arg+".");
		
	}
}
