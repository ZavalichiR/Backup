package adaptor;

public class Pisica implements Animal{
	private String tip = "pisica";
	@Override
	public void speak() {
		System.out.println("Miauuuuuuuu!");
	}

	@Override
	public String getTip() {
		return tip;
	}

}
