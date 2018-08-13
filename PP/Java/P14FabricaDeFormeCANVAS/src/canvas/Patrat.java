package canvas;

import java.awt.Frame;

class Patrat implements Nava{
	 Draw a;
	 Frame f;
	
	
	 public Patrat(Frame fr,Draw ar){
		 f=fr;
		 a=ar;
		
	 }
		@SuppressWarnings("deprecation")
	public void afisare() {
		f.add(a);
		f.show();
	}
}
