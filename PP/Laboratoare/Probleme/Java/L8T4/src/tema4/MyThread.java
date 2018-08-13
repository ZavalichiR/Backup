package tema4;

public class MyThread extends Thread{
	private int n0;
	private int n1;
	static int suma;
	static Object o=new Object();
	MyThread(int n0,int n1){
		this.n0=n0;
		this.n1=n1;
	}
	public void calcul(){
		
		for(int i=n0;i<=n1;++i)
		{
			suma+=i;
			System.out.print(suma+" ");
		}
	}
}
