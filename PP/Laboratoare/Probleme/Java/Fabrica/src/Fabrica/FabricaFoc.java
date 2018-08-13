package Fabrica;

public class FabricaFoc implements FabricaForme{
	public Foc make(String nume){
		if(nume.equals("liniar"))
		{
			return new Liniar();
		}
		else{
			if(nume.equals("blast")){
				return new Blast();
			}
			else{
				if(nume.equals("rachete")){
					return new Rachete();
				}
				else
					return null;
			}
		}
	}

}
