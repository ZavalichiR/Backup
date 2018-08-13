package eveniment;

public class Counter extends Thread {
	private CounterEvent ce;
	int count;
	
	
	public Counter(CounterEvent b,int count){
		ce=b;
		this.count=count;
	}
	
	public Counter(){
		count=0;
	}
	
	public void run(){
		for(int i=0;i<count;i++){
			try{
				sleep(1500);
			}catch(InterruptedException e){}
			ce.put(i);
			System.out.println("Numaratorul are valoarea:\t"+i);
			
		}
	}
	
}

