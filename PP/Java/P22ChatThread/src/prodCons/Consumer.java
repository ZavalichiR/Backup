package prodCons;

public class Consumer extends Thread{
	Buffer buff = new Buffer();
	
	public Consumer(Buffer buff){
		this.buff = buff;
	}
	
	public void run(){
		Object aux;
		while(!(/*Buffer.ok &&*/ buff.isEmpty())){
			aux = buff.remove();
			System.out.println("\t"+Thread.currentThread().getName()+" consuma "+aux.toString());
			try{
				sleep((long)(Math.random()*3000));
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	}

}
