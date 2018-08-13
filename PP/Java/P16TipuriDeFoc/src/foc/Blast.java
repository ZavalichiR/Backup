package foc;

import java.awt.Frame;

class Blast implements Foc{
	 Draw a;
	 Frame f;
	
	
	 public Blast(Frame fr,Draw ar){
		 f=fr;
		 a=ar;
		
	 }
	
	@SuppressWarnings("deprecation")
	public void afisare() {
		f.add(a);
		f.show();
	}
	
}

