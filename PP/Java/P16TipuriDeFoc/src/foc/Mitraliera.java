package foc;

import java.awt.Frame;

class Mitraliera implements Foc{
	 Draw a;
	 Frame f;
	
	
	 public Mitraliera(Frame fr,Draw ar){
		 f=fr;
		 a=ar;
		
	 }
	
	@SuppressWarnings("deprecation")
	public void afisare() {
		f.add(a);
		f.show();
	}
	
}
