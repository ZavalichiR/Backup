package Gof;

public class FormFactory {
	//Form este interfasta
	public static Form getForm(int type, int... params) throws Exception{
		switch(type){
		case CIRCLE: return new Circle(params);
		case SQUARE: return new Square(params);
		default: throw new Exception();
		}
	}
	public static final int CIRCLE=1;//constantele se scriu cu litere mari
	public static final int SQUARE=2;
}
