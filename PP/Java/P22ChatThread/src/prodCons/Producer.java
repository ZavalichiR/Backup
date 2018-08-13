package prodCons;

public class Producer extends Thread{
	private Buffer buff = new Buffer();
	
	public Producer(Buffer buff){
		this.buff = buff;
	}
	
	public void run(){
		Object aux;
		for(int i = 0;i < 10;++i){
			aux = (int)(Math.random()*100);
			System.out.println(Thread.currentThread().getName()+" produce "+aux.toString());
			buff.add(aux);
			try{
				sleep((long)(Math.random()*500));
			}catch(InterruptedException e){
				e.printStackTrace();
			}
		}
	//	Buffer.ok = true;
	}
}
