import java.util.Vector;

public class Afisare extends Thread{
	Vector<Integer> v=new Vector<Integer>();
	
	Afisare(Vector<Integer> vect)
	{
		v=vect;
	}
	
	public void run()
	{
		while(Sortare.ok==false)
		{
			try {
				sleep(1000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		synchronized(this)
		{
			System.out.print("Vectorul: ");
			for(int i=0;i<v.size();++i)
			{
				System.out.print(v.get(i)+" ");
			}
		}
	}
}
