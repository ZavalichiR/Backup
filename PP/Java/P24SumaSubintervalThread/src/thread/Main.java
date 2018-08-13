package thread;

import java.util.Scanner;

public class Main {
	@SuppressWarnings("static-access")
	public static void main(String []args){
		int n,rezultat=0;
		System.out.print("Numar: ");
		Scanner citire=new Scanner(System.in);
		n=citire.nextInt();
		
		Suma n1=new Suma(1,n/4,"Th_1");
		Suma n2=new Suma(n/4+1,n/2,"Th_2");
		Suma n3=new Suma(n/2+1,3*n/4,"Th_3");
		Suma n4=new Suma(3*n/4+1,n,"Th_4");
		
		citire.close();
		
		try {
			//delay for one second
			Thread.currentThread().sleep(4000);
		} catch (InterruptedException e) {
		}
		
		rezultat=rezultat+n1.get_suma()+n2.get_suma()+n3.get_suma()+n4.get_suma();
		System.out.println("Suma este "+rezultat);
		
	}
}
