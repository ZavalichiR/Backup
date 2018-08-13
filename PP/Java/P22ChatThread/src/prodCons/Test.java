package prodCons;

public class Test {
	public static void main(String[] args){
		Buffer b = new Buffer();
		Thread p1 = new Producer(b);
		p1.start();
		Thread c1 = new Consumer(b);
		b.add(c1);
		Thread c2 = new Consumer(b);
		Thread c3 = new Consumer(b);
		c1.start();
		c2.start();
		c3.start();
	}
}
