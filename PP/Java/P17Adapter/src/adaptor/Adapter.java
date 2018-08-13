package adaptor;

public class Adapter implements Animal{
	private Animal adaptat;
	private Adaptee adaptee;
	
	public Adapter (Animal a){
		adaptat = a;
		adaptee = new Adaptee();
	}

	@Override
	public void speak() {
		adaptee.vorbesteTradus(adaptat);
	}

	@Override
	public String getTip() {
		return "adapter";
	}
	

}
