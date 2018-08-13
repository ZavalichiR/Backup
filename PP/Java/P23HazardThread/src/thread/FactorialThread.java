package thread;


class FactorialThread extends Thread{
	int nr;
	int mul = 1;
	public  FactorialThread(int n){
		this.nr = n;
	}
	public void run(){
		for(int i=1 ; i<=nr ; i++){
			mul *= i;
		}
	}
	public int getFact(){
		return mul;
	}
}
