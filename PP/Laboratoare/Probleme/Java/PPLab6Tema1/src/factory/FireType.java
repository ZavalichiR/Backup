package factory;

public abstract class FireType {
	String type;
	FireType(String newtype)
	{
		this.type=newtype;
	}
	public String getType()
	{
		return type;
	}
}
