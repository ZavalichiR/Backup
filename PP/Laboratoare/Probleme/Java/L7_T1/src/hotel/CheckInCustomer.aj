package hotel;

public aspect CheckInCustomer {
	private Customer Room.checkBy = null;

	public Customer Room.getCheckBy() {
		return checkBy;
	}

	public void Room.setCheckBy(Customer value) {
		checkBy = value;
	}

	public void Room.uncheck() {
		setCheckBy(null);
	}

	public void StaffHandler.makeCheckIn(Reservation res) {
		if(res!=null){
		res.getRoom().setCheckBy(res.getCustomer());
		//res.getRoom().isAvailable(false);
		// consume reservation 
		getReservations().remove(res);
		}
	}
}