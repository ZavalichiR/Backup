package hotel;

public enum RoomCategory {
	A(10), B(20), C(30), D(40);
	private int price;

	public int price() {
		return price;
	}

	private RoomCategory(int price) {
		this.price = price;
	}
}