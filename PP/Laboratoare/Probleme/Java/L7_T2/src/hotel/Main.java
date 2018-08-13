package hotel;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		StaffHandler staff=new StaffHandler();
		Customer c=new Customer(1);
		Reservation r[]=new Reservation[10];
		
		staff.testInits();
		
		r[0]=staff.makeReservation(c, RoomCategory.C, 22);
		staff.displayRooms();
		staff.makeCheckIn(r[0]);
		staff.makeCheckOut(r[0].getRoom());
		
	}

}
