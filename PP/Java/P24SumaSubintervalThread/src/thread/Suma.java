package thread;

public class Suma implements Runnable{

	private int start,stop;
	private int suma;
	Thread runner;
	
	Suma(String name){
		start=0;
		stop=10;
		suma=0;
		runner=new Thread(this,name);
		System.out.println("Threadul "+name+" a pornit");
		runner.start();
	};
	
	Suma(int x,int y,String name){
		start=x;
		stop=y;
		suma=0;
		runner=new Thread(this,name);
		System.out.println("Threadul "+name+" a pornit");
		runner.start();
	}
	
	public int get_suma(){
		return suma;
	}
	public void run() {
		for(int i=start;i<=stop;i++){
			suma=suma+i;
		}
	}

}
