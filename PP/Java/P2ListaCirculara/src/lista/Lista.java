package lista;

public class Lista implements InterfaceLista{

	private Nod Head;
	
	public Lista(){
		Head=null;
	}
	public void insereaza(int val) {
		if(Head==null)
		{
		Nod p=new Nod(val);
		p.succ=p;
		Head=p;
		}
		else
		{
			Nod p=new Nod(val);
			p.succ=Head.succ;
			Head.succ=p;
			Head=p;
		}
	}

	public void afiseaza() {
		Nod p=Head;
		while(p.succ!=Head)
		{
			System.out.print(p.data+" ");
			p=p.succ;
		}
		System.out.print(p.data+".\n");
		
	}

}