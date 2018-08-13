package hotel;

public aspect CheckOutCustomer {
	public void StaffHandler.makeChekcOut(Room room) {
		
		for(Room rr : getRooms()){
			if(rr == room){
				
				rr.uncheck();
				rr.setAvailability(true);
				break;
			}
	    }
		
    }
}
