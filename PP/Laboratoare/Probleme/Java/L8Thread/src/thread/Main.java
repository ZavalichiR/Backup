package thread;

public class Main {

	public static void main(String[] args) {
		MyThread t=new MyThread();
		MyThread t2=new MyThread();
		t.start();
		t2.start();
		//for(int i=1000;i<2000;++i){
			//Thread.sleep(10) // opreste firul curent de executie pentru o perioada de 10 Micosec
			//System.out.println(i);
		//}
		//t.join lasa pe threadul t sa se execute prima data
		
		try {
			t.join();
			t2.join();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//System.out.println("Gata");
		System.out.println("x="+MyThread.x);
	}

}
