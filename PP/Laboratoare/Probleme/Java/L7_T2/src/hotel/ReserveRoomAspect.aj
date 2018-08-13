package hotel;

public aspect ReserveRoomAspect {
	private boolean Room.available;
	private int Reservation.nrOfDays;
	
	
	public int Reservation.getNrOfDays()
	{
		return nrOfDays;
	}
	
	
	public void Room.setAvailability(boolean value)
	{
		available=value;
	}
	
	public boolean Room.isAvailable()
	{
		return available;
	}
	
	//returneaza camera din categ daca este libera
	public Room StaffHandler.getAvailableRoom(RoomCategory categ)
	{
		for(Room room: getRooms())
		{
			if(room.isAvailable()&&room.getCateg()==categ)
			{
				return room;
			}
		}
		return null;
	}
	
	//adauga o rezervare daca gaseste o camera libera din categoria categ
	public Reservation StaffHandler.makeReservation(Customer customer,RoomCategory categ, int nrOfDays)
	{
		Room foundRoom=getAvailableRoom(categ);
		if(foundRoom!=null)
		{
			
			Reservation res=new Reservation(foundRoom,customer);
			getReservations().add(res);
			foundRoom.setAvailability(false);
			res.nrOfDays=nrOfDays;
			System.out.println("Am facut o rezervare pentru "+res.nrOfDays+" zile, care va costa " +categ.getPrice()*res.nrOfDays+" RON.");
			return res;
			
		}
		System.out.println("Nu exista nicio camera libera!");
		return null;
	}
}
