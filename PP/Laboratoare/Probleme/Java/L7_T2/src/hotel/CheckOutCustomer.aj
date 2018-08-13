package hotel;

public aspect CheckOutCustomer {
	
	public void StaffHandler.makeCheckOut(Room room)
	{
		room.uncheck();
		room.setAvailability(true);
		System.out.println("Am facut un checkout.");
	}
}
