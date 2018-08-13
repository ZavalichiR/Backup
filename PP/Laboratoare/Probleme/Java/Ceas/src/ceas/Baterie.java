package ceas;

public class Baterie {
	boolean ok;
	Baterie()
	{
		ok=false;
	}
	Baterie(boolean k)
	{
		this.ok=k;
	}
	public void schimba()
	{
		System.out.print("Bateria a fost schimbata\n");
		this.ok=true;
	}
}
