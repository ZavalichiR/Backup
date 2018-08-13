package hotel;

public class Reservation {
	private Room room;
	private Customer customer;
//private int nrDays;

	public Room getRoom() {
		return room;
	}

	public Customer getCustomer() {
		return customer;
	}
/*
	public int getNrDays() {
		return nrDays;
	}
*/

	public Reservation(Room room, Customer customer) {
		this.room = room;
		this.customer = customer;
		//this.nrDays=nrDays;
	}
}