package L6;

public class Main {

	public static void main(String[] args) {
		try{
			//GeneralObserver board = new GeneralObserver();
			Nave n1=FactoryNave.getForm(FactoryNave.CUB,"blue",FactoryMunitie.getForm(FactoryMunitie.LINIE,"Mitraliera"));
			Nave n2=FactoryNave.getForm(FactoryNave.PIRAMIDA,"yellow",FactoryMunitie.getForm(FactoryMunitie.BLAST,"Foc"));
			Nave n3=FactoryNave.getForm(FactoryNave.SFERICA,"green",FactoryMunitie.getForm(FactoryMunitie.RACHETE,"Racheta"));
			n1.informatiiNava();
			n2.informatiiNava();
			n3.informatiiNava();
			
			n1.addObserver(n2);
			n2.addObserver(n3);
			n3.addObserver(n1);
			
			n1.Mesaj();
			n2.Mesaj();
			n3.Mesaj();
			
			}catch (Exception e){
				e.printStackTrace();
			}finally{
			}
		
	}

}
