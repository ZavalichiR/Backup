package factory;

public class ShipFactory {
	public static Ship getForm (int type,String color,FireType ft) throws Exception{
		switch(type){
		case CUBE: return new CubeShip(color,ft);
		case PYRAMIDAL: return new PyramidalShip(color,ft);
		case SPHERICAL: return new SphericalShip(color,ft);
		default: throw new Exception();
		}
	}
	public static final int CUBE=1;
	public static final int PYRAMIDAL=2;
	public static final int SPHERICAL=3;
	
}
