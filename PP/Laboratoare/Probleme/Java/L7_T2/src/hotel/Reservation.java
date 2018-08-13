package hotel;

public class Reservation {
	private Room room; //camera rezervata
	private Customer customer; //clientul care face rezervarea
	
	public Reservation(Room room, Customer customer)
	{
		this.room=room;
		this.customer=customer;
	}
	
	public Room getRoom()
	{
		return room;
	}
	
	public Customer getCustomer()
	{
		return customer;
	}
}
