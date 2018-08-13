package adaptor;

public class Adaptee {
	public void vorbesteTradus(Animal a){
		if(a.getTip().equals("pisica")){
			System.out.println("Traducere pisica: Pisica miauna!");
		}else if(a.getTip().equals("caine")){
			System.out.println("Traducere catel: Cainele latra!");
		}else if(a.getTip().equals("purcel")){
			System.out.println("Traducere purcel: Purcelul guita!");
		}
	}

}
