package eveniment;

class Receptor extends Thread{
	private CounterEvent ce;
	int count;
	
	public Receptor(CounterEvent b,int count){
		ce=b;
		this.count=count;
	}
	
	public void run(){
		int value=0;
		for(int i=0;i<count;i++){
			value=ce.getCount();
			System.out.println("Receptorul a primt valoarea:\t"+value);
			
		}
	}
}
