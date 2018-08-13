package graf;

import java.util.Scanner;

public class Automat {
	String []Stare={"00","01","10","11"};
	boolean reset=true;
	int i;
	int intrare;
	
	Automat(){
		System.out.print("Valoarea de intrare poate fi: \n");
		System.out.print("\t\t0/1 Urmatoare stare\n");
		System.out.print("\t\t!= 0||1 Reset\n");
		i=0;
	}
	
	public String getStare(){
		return Stare[i];
	}
	
	public void functionare(){
		Scanner citire=new Scanner(System.in);
		while(reset){
			System.out.print("Valoare: ");
			intrare=citire.nextInt();
			
			if(intrare>1 || intrare <0){
				i=0;
				System.out.println("A fost dat reset ");
			}
			else{
				setareStare(intrare);
			}
			if(getStare().equals("11")){
				System.out.print("  Output: 1\n");
			}
		}
		citire.close();
		System.out.println("Automatul si-a dat reset");
	}
	
	public void setareStare(int x){
		switch(i){
		case 0:{
			if(x==0)
				i=2;
			else if(x==1)
				i=1;
			System.out.print("Stare curenta: "+Stare[i]+" ");
			}break;
		case 1:{
			if(x==0)
				i=2;
			else if(x==1)
				i=3;
			System.out.print("Stare curenta: "+Stare[i]+" ");
			}break;
		case 2:{
			if(x==0)
				i=3;
			else if(x==1)
				i=1;
			System.out.print("Stare curenta: "+Stare[i]+" ");
			}break;
		case 3:{
			if(x==0)
				i=2;
			else if(x==1)
				i=1;
			System.out.print("Stare curenta: "+Stare[i]+" ");
			}break;
		default:
			break;
		}
	}

}
