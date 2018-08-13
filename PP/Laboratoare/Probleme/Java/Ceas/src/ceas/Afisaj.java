package ceas;

public class Afisaj {

	public int o;
	public int min;
	public int sec;
	Afisaj(int o,int min,int sec)
	{
		this.o=o;
		this.min=min;
		this.sec=sec;
	}
	
	Timp timp=new Timp(o,min,sec);
	
	void afisareO()
	{
		System.out.print(" Ora: "+timp.getOra());
	}
	void afisareMin()
	{
		System.out.print(" Min: "+timp.getMin());
	}
	void afisareSec()
	{
		System.out.print(" Sec: "+timp.getSec());
	}
	void afisare()
	{
		System.out.print(" Ora: "+timp.getOra()+":"+timp.getMin()+":"+timp.getSec()+"\n");
	}
	
}
