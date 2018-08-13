package hotel;

import java.util.ArrayList;
import java.util.List;

public aspect WaitingListAspect {
	private List<Reservation> StaffHandler.waitingReservation = new ArrayList<Reservation>();
	public String Room.getTip(){
		switch( this.getCateg().price()){
		case 10: return "A";
		case 20: return "B";
		case 30: return "C";
		case 40: return "D";
		};
		return null;
	}
	
	public List<Reservation> StaffHandler.getWaitingList(){
		return waitingReservation;
	}
	public void StaffHandler.showWaitingList(){
		if(waitingReservation.isEmpty()==true){
			System.out.println("Nu sunt inregistrati clienti in lista de asteptare.");
		}
		else{
			System.out.println("\nClientii inregistrati in lista de asteptare sunt ");
			for( Reservation rst : getWaitingList()){
				System.out.println("Clientul cu id: "+rst.getCustomer().getId()+" doreste sa rezerve camera "+rst.getRoom().getCateg().toString()+" pentru "+rst.getNrDays()+" zile.");
				
			}
		}
	}

}
