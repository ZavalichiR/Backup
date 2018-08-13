package tema5;

import tema5.MyThread;

public class Main {

	public static void main(String[] args) {
		int queue[]={10,40,20,30};
		
		MyThread t1=new MyThread(queue[3]); 
		MyThread t2=new MyThread(queue[2]);
		MyThread t3=new MyThread(queue[1]);
		MyThread t4=new MyThread(queue[0]);
		t1.calcul();
		t2.calcul();
		t3.calcul();
		t4.calcul();
	}

}
