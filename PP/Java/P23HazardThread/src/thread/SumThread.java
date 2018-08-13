package thread;
public class SumThread extends Thread{
	int nr;
	public int sum = 0;
	public  SumThread(int n){
		this.nr = n;
	}
	public void run(){
		for(int i=0 ; i<=nr ; i++){
			
			sum += i;
		}
	}
	
	public int getSum(){
		return sum;
	}
}
