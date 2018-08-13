package Gof;

public class Main {

	public static void main(String[] args) {
		// Singleton m=Singleton.getInstance();
		
		try {//trateaza exceptia	
			Form f1 = FormFactory.getForm(FormFactory.CIRCLE, 20, 20, 15);
			Form f2 = FormFactory.getForm(3, 10, 10);
		} catch (Exception e) {//se executa doar daca avem exceptie
			e.printStackTrace();
		}finally{//se executa mereu
			// se executa indiferent daca a aparut exceptii sau nu
		}
	}

}