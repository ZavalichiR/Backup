package factory;

import java.util.Observable;
import java.util.Observer;

public abstract class Ship extends Observable implements Observer{
	private String color;
	private FireType ft;
	String message;
	Ship(String newColor,FireType newft){
		this.color=newColor;
		this.ft=newft;
	}
	public String getColor(){
		return color;
	}
	public String getFireType()
	{
		return ft.getType();
	}
	
	public void ChangeStats(String newColor,FireType newft)
	{
		this.color=newColor;
		this.ft=newft;
		message=this.getColor()+" "+this.getFireType();
		setChanged();
		notifyObservers(message);
	}
	
	public void seeInfo()
	{
		System.out.println("Ship COLOR: "+color);
		try{
			System.out.println("Fire TYPE: "+ft.getType());
		}catch(Exception e){
			e.printStackTrace();
		}
	}
	
}
