package tema4;

import tema4.MyThread;

public class Main {

	public static void main(String[] args) {
		MyThread t1=new MyThread(1,30); 
		MyThread t2=new MyThread(31,60);
		MyThread t3=new MyThread(60,1000);
		MyThread t4=new MyThread(1001,2000);
		MyThread.suma=0;
		t1.calcul();
		t2.calcul();
		t3.calcul();
		t4.calcul();
	}
}
