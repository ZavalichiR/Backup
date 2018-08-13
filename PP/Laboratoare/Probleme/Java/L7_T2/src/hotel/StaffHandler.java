package hotel;

import java.util.ArrayList;
import java.util.List;

public class StaffHandler {
	private List<Room> rooms=new ArrayList<Room>(); //evidenta camerelor
	private List<Reservation> reservations=new ArrayList<Reservation>(); //rezervari in asteptare
	
	public StaffHandler()
	{
		testInits();
	}
	
	public List<Room> getRooms()
	{
		return rooms;
	}
	
	public List<Reservation> getReservations()
	{
		return reservations;
	}
	
	public void testInits()
	{
		for(int i=0;i<1;i++)
		{
			rooms.add(new Room(10+i, RoomCategory.A));
			rooms.add(new Room(20+i, RoomCategory.B));
			rooms.add(new Room(30+i, RoomCategory.C));
			rooms.add(new Room(40+i, RoomCategory.D));
		}
		for( Room rr: getRooms()){
			rr.setAvailability(true);
		}
	}
	
	public void displayRooms()
	{
		for(int i=0;i<rooms.size();i++)
		{
			System.out.println("\tCamera "+rooms.get(i).getNr()+" exista si costa " + rooms.get(i).getCateg().getPrice()+" RON.");
		}
	}
}
