package TipuriFoc;

import java.awt.Frame;

class Racheta implements Fire{
	 draw a;
	 Frame f;
	
	
	 public Racheta(Frame fr,draw ar){
		 f=fr;
		 a=ar;
		
	 }
	
	@SuppressWarnings("deprecation")
	public void afisare() {
		f.add(a);
		f.show();
	}
	
}