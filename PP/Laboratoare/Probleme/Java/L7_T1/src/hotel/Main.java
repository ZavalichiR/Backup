package hotel;

public class Main {

		public static void main(String[] args) {
			
			//exista 3 camere din fiecare tip
			StaffHandler staff=new StaffHandler();
			staff.showAllRooms();
			Customer c[]=new Customer[10];
			Reservation r[]=new Reservation[10];
			int i;
			for(i=0; i<10; i++){
				c[i]=new Customer(i+1);
			}
			staff.showWaitingList();
		
			r[0]=staff.makeReservation(c[0], RoomCategory.A,2);
		    staff.makeCheckIn(r[0]);
			
		    r[1]=staff.makeReservation(c[1], RoomCategory.B,1);
		    staff.makeCheckIn(r[1]);
		    
		    r[2]=staff.makeReservation(c[2], RoomCategory.C,2);
		    staff.makeCheckIn(r[2]);
			
		    r[3]=staff.makeReservation(c[3], RoomCategory.D,3);
		    staff.makeCheckIn(r[3]);
		    
		    r[4]=staff.makeReservation(c[4], RoomCategory.A,1);
		    staff.makeCheckIn(r[4]);
		    
		    r[5]=staff.makeReservation(c[5], RoomCategory.A,4);
		    staff.makeCheckIn(r[5]);
		    
		    r[6]=staff.makeReservation(c[6], RoomCategory.A,7);
		    staff.makeCheckIn(r[6]);
	
		    r[7]=staff.makeReservation(c[7], RoomCategory.A,3);
		    staff.makeCheckIn(r[7]);
		 
		    staff.showWaitingList();   					
			
			System.out.println("\nDupa checkIn:\n");
			staff.showAllRooms();
			r[3].getPayment();
			r[1].getPayment();
			staff.makeChekcOut(r[0].getRoom());
			staff.makeChekcOut(r[1].getRoom());			
			staff.makeChekcOut(r[2].getRoom());			
			staff.makeChekcOut(r[3].getRoom());
			
			System.out.println("\nDupa un checkOut:\n");
			
			staff.showAllRooms();
	}

}
