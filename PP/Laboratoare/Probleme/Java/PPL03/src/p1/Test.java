package p1;

public class Test {

	public static void main(String[] args) {
		System.out.println("Hello world!");
		Colectie<Integer> s=new Stiva<Integer>(10);
		for (int i=0;i<5;i++)
			s.adauga(i);
		s.afisare();
		Integer x=s.element();
		System.out.println("Ultimul element: ");
		System.out.println(x);
		System.out.println("Elemente scoase: ");
		for (int i=0;i<5;i++)
			System.out.println(s.scoate());
		s.afisare();
	}

}
