package hotel;

public class Room {
	private int nr;
	private RoomCategory categ;

	public int getNr() {
		return nr;
	}

	public RoomCategory getCateg() {
		return categ;
	}

	public Room(int nr, RoomCategory categ) {
		this.nr = nr;
		this.categ = categ;
	}
}