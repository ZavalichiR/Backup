package hotel;

public aspect ReserveRoomAspect {
	
	private boolean Room.available;
	private int Reservation.nrDays;

	public int Reservation.getNrDays(){
		return nrDays;
	}
	public void Room.setAvailability(boolean value) {
		available = value;
	}

	public boolean Room.isAvailable() {
		return available;
	}

	private Room StaffHandler.getAvailableRoom(RoomCategory categ) {
		for (Room room : getRooms()) {
			if (room.isAvailable() && room.getCateg() == categ) {
				return room;
			}
		}
		return null;
	}
	public Room StaffHandler.findRoom(RoomCategory cat){
		for (Room room : getRooms()) {
			if (room.getCateg() == cat) {
				return room;
			}
		}
		return null;
	}
	public void Reservation.getPayment(){
		
		System.out.println("Clientul "+this.getCustomer().getId()+" are de platit "+ this.getRoom().getCateg().price()* this.getNrDays()+" RON pentru "+this.getNrDays()+" zile.");
		
	}

	public Reservation StaffHandler.makeReservation(Customer customer,	RoomCategory categ, int nrDays) {
		Room foundRoom = getAvailableRoom(categ);
	
		
		
		if (foundRoom != null) {
			Reservation res = new Reservation(foundRoom, customer);
			res.nrDays=nrDays;
			getReservations().add(res);
			foundRoom.setAvailability(false);
			return res;
		}
//		else{
//			Reservation waitRes=new Reservation(findRoom(categ),customer);
//			waitRes.nrDays=nrDays;
//			getWaitingList().add(waitRes);
//			System.out.println("Camera nu este disponibila momentan. Clientul a fost introdus in lista de asteptare");
//		}
		return null;
	}
}