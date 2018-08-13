package hotel;

public class Room {
	private int nr; //nr de ordine
	private RoomCategory categ; //categorie pe baza careia stabilim pretul
	
	public int getNr()
	{
		return nr;
	}
	
	public RoomCategory getCateg()
	{
		return categ;
	}
	
	public Room(int nr, RoomCategory categ)
	{
		this.nr=nr;
		this.categ=categ;
	}
}
