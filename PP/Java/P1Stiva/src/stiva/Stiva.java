package stiva;

public class Stiva implements InterfaceStiva{
	private Nod Head;
	Stiva(){
		Head=null;
	}
	public void push(int val) {
		Nod p=new Nod(val);
		p.leg=Head;
		Head=p;
		
	}

	public int top() {
		if(Head==null)
		{
			System.err.println("Stiva este goala");
			return 0;
		}
		else
		{
			return Head.data;
		}
	}

	public int pop() {
		if(Head==null)
		{
			System.err.println("Stiva este goala");
			return 0;
		}
		else
		{
			int aux=Head.data;
			//Nod p=Head;
			Head=Head.leg;
			return aux;
		}
	}

	public boolean isEmpty() {
		if(Head==null)
			return true;
		else
			return false;
	}
	
}
