package thread;

import java.util.*;
public class Main {
	public static void main(String []args){
		LinkedList<Integer> n=new LinkedList<Integer>();
		n.add(4);
		n.add(6);
		n.add(10);
		n.add(9);
		
		
		
		Suma a,b,c,d;
		a=new Suma(n.getFirst());
		n.remove();
		b=new Suma(n.getFirst());
		n.remove();
		c=new Suma(n.getFirst());
		n.remove();
		d=new Suma(n.getFirst());
		
		a.start();
		b.start();
		c.start();
		d.start();
		
		
		try{
			Thread.sleep(2000);
		}catch(InterruptedException e){
			e.printStackTrace();
		}
		
		System.out.println("a="+a.getS());
		System.out.println("b="+b.getS());
		System.out.println("c="+c.getS());
		System.out.println("d="+d.getS());
	}
}
