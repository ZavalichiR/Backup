package hotel;

import java.util.*;

public class StaffHandler {
	private List<Room> rooms = new ArrayList<Room>();
	private List<Reservation> reservations = new ArrayList<Reservation>();
	//static int nrR=12;
	
	public StaffHandler() {
		testInits();
	}

	public List<Room> getRooms() {
		return rooms;
	}

	public List<Reservation> getReservations() {
		return reservations;
	}
	
	private void testInits() {
		for (int i = 0; i <3; i++) {
			rooms.add(new Room(10 + i, RoomCategory.A));
			rooms.add(new Room(20 + i, RoomCategory.B));
			rooms.add(new Room(30 + i, RoomCategory.C));
			rooms.add(new Room(40 + i, RoomCategory.D));
		}
		for( Room rr: getRooms()){
			rr.setAvailability(true);
		}
	}
	public void showAllRooms(){
		for (int i = 0; i < 12; i++) {
			System.out.println("\tCamera: "+rooms.get(i).getNr()+"\tPret: "+ rooms.get(i).getCateg().price()+" ");
			if(rooms.get(i).isAvailable()==true){
				//nimic
			}				
			else{
				System.out.println("Camera "+rooms.get(i).getNr()+" este ocupata de clientul "+rooms.get(i).getCheckBy().getId()+ "!\n");
			}
		}
	}
	
}