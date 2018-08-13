package thread;

public class MyThread extends Thread{

	static int x=0;
	static Object o=new Object(); //pentru sincronizare
	public void run(){
		for(int i=0;i<10000;++i){
			//se sincronizeaza doar accesul la zona comuna
			synchronized(o){
			++x;
			//System.out.println(i);
			}
		}

	}
}
