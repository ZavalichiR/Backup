import java.util.Collections;
import java.util.Vector;

public class Sortare extends Thread{
	public static boolean ok=false;
	Vector<Integer> v=new Vector<Integer>();
	
	Sortare(Vector<Integer> vect)
	{
		v=vect;
	}
	
	public void run(){
		while(Inmultire.ok==false)
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
			Collections.sort(v);
		}
		ok=true;
	}

}
