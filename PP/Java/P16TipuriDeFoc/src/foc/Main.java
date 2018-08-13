package foc;

public class Main {

	public static void main(String[] args) {
		Fabrica a=new Fabrica();
		
		Foc []b=new Foc[3];
		b[0]=a.make("mitraliera");
		b[1]=a.make("rachete");
		b[2]=a.make("blast");
		
		//b[0].afisare();
		//b[1].afisare();
		b[2].afisare();
		


	}

}
