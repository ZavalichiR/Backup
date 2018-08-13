package Fabrica;

public class Main {
	public static void main(String []args){
		FabricaFoc f = new FabricaFoc();
		Foc f1=f.make("liniar");
		Foc f2=f.make("blast");
		Foc f3=f.make("rachete");
		f1.draw();
		f2.draw();
		f3.draw();
		
	}
}
