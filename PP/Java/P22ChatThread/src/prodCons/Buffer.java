package prodCons;

import java.util.LinkedList;

public class Buffer {
	private LinkedList<Object> objects = new LinkedList<Object>();
	//public static boolean ok = false;
	
	public synchronized void add(Object x){
		objects.add(x);
		this.notifyAll();
	}
	
	public synchronized Object remove(){
		while(objects.isEmpty()){
			try{
				wait();
			}catch(InterruptedException e){}
		}
		return objects.removeFirst();
	}
	
	public boolean isEmpty(){
		return objects.isEmpty();
	}
}
