package eveniment;

import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		int nr;
		
		Scanner scan=new Scanner(System.in);
		System.out.print("Valoarea maxima: ");
		nr=scan.nextInt();
		scan.close();
		
		CounterEvent b=new CounterEvent();
		Counter c=new Counter(b,nr);
		Receptor r=new Receptor(b,nr);
		c.start();
		r.start();
	}

}
