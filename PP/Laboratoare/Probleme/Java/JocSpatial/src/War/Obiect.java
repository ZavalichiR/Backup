package War;

public class Obiect implements Meniu{
	private String Nume;
	private int DistantaAtac;
	private int Dmg;
	private int Def;
	private int Viata;
	private int Scut;
	private int x;
	private int y;
	public Obiect()
	{
		this.Nume="";
		this.DistantaAtac=0;
		this.Dmg=0;
		this.Def=0;
		this.Viata=0;
		this.Scut=0;
		this.x=0;
		this.y=0;
	}
	public Obiect(String nume,int range,int damage,int def,int viata,int scut,int x,int y)
	{
		this.Nume=nume;
		this.DistantaAtac=range;
		this.Dmg=damage;
		this.Def=def;
		this.Viata=viata;
		this.Scut=scut;
		this.x=x;
		this.y=y;
	}
	public String getNume()
	{
		return Nume;
	}
	public boolean distrusa()
	{
		if(this.Viata<=0)
		{
			return true;
		}
		else
		{
			
			return false;
		}
	}
	public void urmareste(Obiect nava)
	{
		System.out.println("["+Nume+"] urmareste nava ["+nava.Nume+"]");
		x=nava.x-1;
		y=nava.y-1;
		System.out.println("["+Nume+"] se afla in spatele navei ["+nava.Nume+"]");
		
	}
	public void ataca(Obiect nava)
	{
		if(Math.sqrt(Math.abs((nava.x-this.x)*(nava.x-this.x))+Math.abs((nava.y-this.y)*(nava.y-this.y)))<=this.DistantaAtac)
		{	
			
			System.out.println("["+Nume+"] ataca nava ["+nava.Nume+"]");
			if(nava.Scut>3*Dmg)
			{
				System.out.println("["+nava.Nume+"] are scutul prea puternic ");
			}
			else
			{
			nava.Viata=nava.Viata-(Dmg + nava.Def);
			}
			
			if(nava.distrusa()==true)
			{
				System.out.print("["+nava.Nume+"] a fost distrusa de catre "+this.Nume+"\n");
			}
			else
			{
				System.out.println("["+nava.Nume+"] a ramasa cu "+nava.Viata+" viata");
			}
		}
		else
		{
			urmareste(nava);
			nava.Viata=nava.Viata-(Dmg + nava.Def);
			System.out.println("["+Nume+"] ataca nava ["+nava.Nume+"]");
			System.out.println("["+nava.Nume+"] a ramasa cu "+nava.Viata+" viata");
			if(nava.Viata==0)
				nava.distrusa();
		}
		System.out.println("-------------------------------------------------------------");
	}
	
}
