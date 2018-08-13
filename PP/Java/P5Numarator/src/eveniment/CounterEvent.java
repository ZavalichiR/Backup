package eveniment;

public class CounterEvent {
	private int count;
	boolean available=false;
	
	public CounterEvent ( int count ){
		
		this.count=count;
	}
	
	public CounterEvent(){
		count=-1;
	}
	
	public synchronized int getCount(){
		try {
			wait();  //need only wait()
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		available=false;
		notifyAll();
		return count;
	}
	
	
	public synchronized void put(int number){
		while(available){
			try{
				wait();
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
		this.count=number;
		available=true;
		notifyAll();
	}
}
