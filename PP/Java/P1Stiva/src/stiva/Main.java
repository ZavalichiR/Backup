package stiva;

public class Main {

	public static void main(String[] args) {
		
		Stiva S=new Stiva();
		S.pop();
		S.push(1);
		S.push(2);
		S.push(3);
		S.push(4);
		System.out.println("POP: "+S.pop());
		System.out.println("POP: "+S.pop());
		System.out.println("POP: "+S.pop());
		System.out.println("TOP: "+S.top());
		System.out.println("POP: "+S.pop());
	}

}
    