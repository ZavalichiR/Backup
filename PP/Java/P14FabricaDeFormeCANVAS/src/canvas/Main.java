package canvas;

public class Main {

	public static void main(String[] args) {
		Fabrica a=new Fabrica();
		
		Nava []b=new Nava[3];
		b[0]=a.make("patrat");
		b[1]=a.make("triunghi");
		b[2]=a.make("cerc");
		
		b[0].afisare();


	}

}
