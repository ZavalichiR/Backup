package ceas;

public class CeasSimplu {
	Baterie bat[]=new Baterie[2];
	Buton but=new Buton();
	Afisaj afis=new Afisaj();
	Timp timp=new Timp();
	private int contor=-1;
	
	public CeasSimplu(){
		afis.afisareOra();
	}
	
	void apasButon1()
	{
		but.apasB1();
		contor++;
		switch(contor%3){
		case 0:
			afis.Ora();
			break;
		case 1:
			afis.Minute();
			break;
		case 2:
			afis.Secunde();
			break;
		}
	}
	void apasButon2()
	{
		but.apasB2();
		if(contor>-1)
		{
			switch(contor%3){
			case 0:
				timp.incrementareOra();
				break;
			case 1:
				timp.incrementareMinute();
				break;
			case 2:
				timp.incrementareSecunde();
				break;
			}
		}
		
	}
	void apasButon1si2()
	{
		but.apasB1siB2();
		contor=-1;
		timp.salvare();
		afis.Setare();
		afis.afisareOra();
	}
}
