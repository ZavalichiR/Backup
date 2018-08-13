package L6;

import java.util.Observable;
import java.util.Observer;

public abstract class Nave extends Observable implements Observer{
	private String color;
	private Munitie tip;
	String message;
	Nave(String newColor,Munitie tipnou){
		this.color=newColor;
		this.tip=tipnou;
	}
	public String getColor(){
		return color;
	}
	public String getMunitie()
	{
		return tip.getTip();
	}
	
	public void Mesaj()
	{
		message="        Coloare "+this.getColor()+", munitie: "+this.getMunitie();
		setChanged();
		notifyObservers(message);
	}
	
	public void informatiiNava()
	{
		System.out.println("     CULOARE: "+color);
		try{
			System.out.println("     MUNITIE: "+tip.getTip());
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
}
