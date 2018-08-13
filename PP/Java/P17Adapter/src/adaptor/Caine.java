package adaptor;

public class Caine implements Animal{
	private String tip = "caine";
	@Override
	public void speak() {
		System.out.println("Ham ham!");
	}

	@Override
	public String getTip() {
		return tip;
	}

}
