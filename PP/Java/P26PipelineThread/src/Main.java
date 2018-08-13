import java.util.Vector;

public class Main {

	public static void main(String[] args) {
		Vector<Integer> v=new Vector<Integer>();
		v.add(1);
		v.add(2);
		v.add(3);
		v.add(4);
		int a=2;
		Inmultire in=new Inmultire(a,v);
		Sortare so=new Sortare(v);
		Afisare af=new Afisare(v);
		
		try {
			in.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			so.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		try {
			af.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		in.start();
		so.start();
		af.start();

	}

}
