import java.util.Vector;

public class Inmultire extends Thread{
	public Vector<Integer> v=new Vector<Integer>();
	int alpha;
	public static boolean ok=false;
	Inmultire(int a,Vector<Integer> vect)
	{
		alpha=a;
		v=vect;
	}
	
	public void run()
	{
		synchronized(this){
		int rez=0;
		for(int i=0;i<v.size();++i)
		{
			rez=rez+alpha+v.get(i);
		}
		ok=true;
		}
		try {
			sleep(1000);
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
}
