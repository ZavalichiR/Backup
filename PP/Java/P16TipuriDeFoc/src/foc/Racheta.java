package foc;

import java.awt.Frame;

class Racheta implements Foc{
	 Draw a;
	 Frame f;
	
	
	 public Racheta(Frame fr,Draw ar){
		 f=fr;
		 a=ar;
		
	 }
	
	@SuppressWarnings("deprecation")
	public void afisare() {
		f.add(a);
		f.show();
	}
	
}
