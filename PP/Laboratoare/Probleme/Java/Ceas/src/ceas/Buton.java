package ceas;

public class Buton {

	private int o;
	private int sec;
	private int min;
	
	public int contor=0;
	Buton()
	{
		this.o=0;
		this.min=0;
		this.sec=0;
	}
	Buton(int o,int m,int s)
	{
		this.o=o;
		this.min=m;
		this.sec=s;
	}
	
	Afisaj ecran=new Afisaj(o,min,sec);
	
	void apasButon1()
	{
		contor=(contor+1)%3;
		if(contor==0)
		{	
			System.out.print("Setarile ceasului sunt inchise\n");
			ecran.afisare();
		}
		if(contor==2)
		{
			//System.out.print("Clipesc minutele\n");
			ecran.afisareMin();
		}
		if(contor==1)
		{
			//System.out.print("Clipesc orele\n");
			ecran.afisareO();
		}
		if(contor==3)
		{
			//System.out.print("Clipesc secundele\n");
			ecran.afisareSec();
		}
		
		
	}
	void apasButon2()
	{
		if(contor==0)
		{
			
			System.out.print("Setarile ceasului sunt inchise\n");
			ecran.afisare();
		}
		if(contor==2)
		{
			ecran.timp.incMin();
			ecran.afisareMin();
		}
		if(contor==1)
		{
			ecran.timp.incOre();
			ecran.afisareO();
		}
		if(contor==3)
		{
			ecran.timp.incSec();
			ecran.afisareSec();
		}
	}
	void apasButon1si2()
	{
		contor=0;
		ecran.afisare();
	}
}
