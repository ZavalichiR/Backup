package thread;


class SquareThread extends Thread{
	int nr;
	int square;
	public  SquareThread(int n){
		this.nr = n;
	}
	public void run(){
		
			square = nr*nr;
		
	}
	public int getSquare(){
		return square;
	}
}
