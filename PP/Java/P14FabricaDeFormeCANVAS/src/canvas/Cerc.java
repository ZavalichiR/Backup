package canvas;

import java.awt.Frame;

class Cerc implements Nava{
	 Draw a;
	 Frame f;
	
	public Cerc(Frame fr,Draw ar){
		 f=fr;
		 a=ar;
		
	 }
		@SuppressWarnings("deprecation")
	public void afisare() {
		f.add(a);
		f.show();
	}
}
