package jpanel;

import java.awt.Frame;


class Triunghi implements Nava{
	 Draw a;
	 Frame f;
	
	public Triunghi(Frame fr,Draw ar){
		 f=fr;
		 a=ar;
		 }
	
	@SuppressWarnings("deprecation")
	public void afisare() {
		f.add(a);
		f.show();
	}	
}
