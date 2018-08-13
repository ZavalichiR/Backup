package L6;

public class FactoryMunitie {
	public static Munitie getForm (int tip,String tipnou) throws Exception{
		switch(tip){
		case LINIE: return new FocLiniar(tipnou);
		case BLAST: return new Blaster(tipnou);
		case RACHETE: return new Rachete(tipnou);
		default: throw new Exception();
		}
	}
	public static final int LINIE=1;
	public static final int BLAST=2;
	public static final int RACHETE=3;
}
