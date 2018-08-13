package L6;

public class FactoryNave {
	public static Nave getForm (int tip,String color,Munitie tipM) throws Exception{
		switch(tip){
		case CUB: return new NavaCub(color,tipM);
		case PIRAMIDA: return new NavaPiramidala(color,tipM);
		case SFERICA: return new NavaSferica(color,tipM);
		default: throw new Exception();
		}
	}
	public static final int CUB=1;
	public static final int PIRAMIDA=2;
	public static final int SFERICA=3;
	
}
