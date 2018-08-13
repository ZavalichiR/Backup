package p1;

public class Stiva<T> implements Colectie<T> {
	private T[] v;
	private int n;
	private int dim;
	@SuppressWarnings("unchecked")
	public Stiva(int dim){
		this.dim=dim;
		n=0;
		v=(T[])(new Object[dim]);
	}
	public boolean adauga(T x){
		int i;
		if (n<dim){
			for (i=0;i<n;i++){
				if (v[i]==x) break;
			}
			if (i<n) return false;
			else{
				v[n]=x;
				n++;
				return true;
			}
		}
		else{
			System.out.println("Stiva plina!");
			return false;
		}
	}
	public T scoate(){
		if (n>0){
			T rez=v[n-1];
			n--;
			return rez;
		}
		return null;
	}
	public T element(){
		return (n>0) ? v[n-1]:null;
	}
	public void afisare(){
		for (int i=0;i<n;i++){
			System.out.println(v[i]);
		}
	}
}
