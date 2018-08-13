package thread;

public class Main {
	public static void main(String []args){
		SumThread a=new SumThread(100);
		FactorialThread b=new FactorialThread(8);
		SquareThread c=new SquareThread(8);
		
		a.start();
		b.start();
		c.start();
		
			System.out.print("Suma= "+a.getSum());
			System.out.print("   Factorial= "+b.getFact());
			System.out.println("   Patrat= "+c.getSquare());
		
		
		System.out.println("Se observa ca la rulari repetate ale programului\n apar rezultate diferite,de aici rezultand hazardul Thread`urilor");

	}
}
