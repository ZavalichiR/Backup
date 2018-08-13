package adaptor;

public class Purcel implements Animal{
	private String tip = "purcel";
	@Override
	public void speak() {
		System.out.println("Oinc, oinc!");
	}

	@Override
	public String getTip() {
		return tip;
	}

}
