package War;

public class Hangar {

	public static void main(String[] args) 
	{
		Obiect n1=new Obiect("Adaris",2,100,30,1000,70,0,0);
		Obiect n2=new Obiect("Jumper",3,150,50,720,85,50,50);
		Obiect n3=new Obiect("Killer",3,130,45,800,85,25,30);
		Obiect n4=new Obiect("Sniper",5,300,20,805,85,30,40);
		int n=100;
		while(n!=0)
		{
			if(n1.distrusa()!=true)
			{
				if(n2.distrusa()!=true)
				n1.ataca(n2);
				if(n3.distrusa()!=true)
				n1.ataca(n3);
				if(n4.distrusa()!=true)
				n1.ataca(n4);
			}
			if(n2.distrusa()!=true)
			{
				if(n1.distrusa()!=true)
				n2.ataca(n1);
				if(n3.distrusa()!=true)
				n2.ataca(n3);
				if(n4.distrusa()!=true)
				n2.ataca(n4);
			}
			if(n3.distrusa()!=true)
				{
				if(n2.distrusa()!=true)
				n3.ataca(n2);
				if(n1.distrusa()!=true)
				n3.ataca(n1);
				if(n4.distrusa()!=true)
				n3.ataca(n4);
				}
			if(n4.distrusa()!=true)		
			{
				if(n1.distrusa()!=true)
				n4.ataca(n1);
				if(n2.distrusa()!=true)
				n4.ataca(n2);
				if(n3.distrusa()!=true)
				n4.ataca(n3);	
			}
			n--;
		}

		System.out.println("\n\n                 WINNER");
		System.out.println("    -----------------------------------");
		if(n1.distrusa()!=true)
			System.out.println("    |||||||||||||["+n1.getNume()+"]||||||||||||| ");
		if(n2.distrusa()!=true)
			System.out.println("    |||||||||||||["+n2.getNume()+"]||||||||||||| ");
		if(n3.distrusa()!=true)		
			System.out.println("    |||||||||||||["+n3.getNume()+"]||||||||||||| ");
		if(n4.distrusa()!=true)	
			System.out.println("    |||||||||||||["+n4.getNume()+"]|||||||||||||| ");
		System.out.println("    -----------------------------------");
		
	}
}
