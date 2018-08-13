package factory;

public class FireTypeFactory {
	public static FireType getForm (int type,String ftype) throws Exception{
		switch(type){
		case LINEAR: return new FireLinear(ftype);
		case BLAST: return new FireBlast(ftype);
		case ROCKET: return new FireRocket(ftype);
		default: throw new Exception();
		}
	}
	public static final int LINEAR=1;
	public static final int BLAST=2;
	public static final int ROCKET=3;
}
