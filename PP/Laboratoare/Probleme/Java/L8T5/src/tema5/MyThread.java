package tema5;

public class MyThread extends Thread{
	private int n;
	private int suma;
	static Object o=new Object();
	MyThread(int n){
		this.n=n;
	}
	public void calcul(){
		for(int i=0;i<=n;++i)
		{	
			this.suma+=i;
		}
		System.out.println("Rez: "+suma);
	}
	public int GetSuma(){
		return this.suma;
	}
}
