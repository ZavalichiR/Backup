package thread;

public class Suma extends Thread {
	int numar;
	int suma=0;
	public Suma(int val){
		numar=val;
	}
	public void run(){
		for(int i=0;i<=numar;i++){
			suma=suma+i;
		}
	}
	public int getS(){
		return suma;
	}
}
