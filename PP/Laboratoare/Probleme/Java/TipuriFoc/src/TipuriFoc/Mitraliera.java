package TipuriFoc;

import java.awt.Frame;

class Mitraliera implements Fire{
	 draw a;
	 Frame f;
	
	
	 public Mitraliera(Frame fr,draw ar){
		 f=fr;
		 a=ar;
		
	 }
	
	@SuppressWarnings("deprecation")
	public void afisare() {
		f.add(a);
		f.show();
	}
	
}

