package hotel;

public aspect CheckInCustomer {
	private Customer Room.checkBy=null;
	
	public Customer Room.getCheckBy()
	{
		return checkBy;
	}
	
	public void Room.setCheckBy(Customer value)
	{
		checkBy=value;
	}
	
	public void Room.uncheck()
	{
		setCheckBy(null);
	}
	
	public void StaffHandler.makeCheckIn(Reservation res)
	{
		res.getRoom().setCheckBy(res.getCustomer());
		getReservations().remove(res);
	}
}
