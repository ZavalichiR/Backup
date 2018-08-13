package adaptor;

public class Bunica {
	public Bunica(){
		System.out.println("Bunica vorbetse cu animalele dar nu le intelege");
	}
	
	public static void main(String[] args){
		Bunica buni =  new Bunica();
		Animal pisi = new Pisica();
		Animal cate = new Caine();
		Animal purc = new Purcel();
		
		Animal adapter1 = new Adapter(pisi);
		Animal adapter2 = new Adapter(cate);
		Animal adapter3 = new Adapter(purc);
		
		pisi.speak();
		adapter1.speak();
		
		cate.speak();
		adapter2.speak();
		
		purc.speak();
		adapter3.speak();
		
		System.out.println("Animale intelese!");
	}
}
