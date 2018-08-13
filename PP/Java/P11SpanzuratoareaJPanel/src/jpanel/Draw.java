package jpanel;





import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JPanel;



public class Draw extends JPanel{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int greseli=0;
	public Draw(){
		super();
		
		//setLayout(null);
		setBounds(20,50,500,650);
		setBackground(Color.cyan);
		 
	}
	
	
	public void paintComponent(Graphics g){
		if(greseli==0){
		g.drawLine(50,600,250,600);
		g.drawLine(150,600,150,100);
		g.drawLine(150,100,350,100);
		g.drawLine(350,100,350,150);
		
		}
		switch (greseli) {
		case 1:
			g.drawOval(300, 150, 100, 100);
			break;
		case 2:
			g.drawOval(300, 150, 100, 100);
			g.drawLine(350, 250, 350, 450);
			break;
		case 3:
			g.drawOval(300, 150, 100, 100);
			g.drawLine(350, 250, 350, 450);
			g.drawLine(350,250,250,350);
			break;
		case 4:
			g.drawOval(300, 150, 100, 100);
			g.drawLine(350, 250, 350, 450);
			g.drawLine(350,250,250,350);
			g.drawLine(350,250,450,350);
			break;
		case 5:
			g.drawOval(300, 150, 100, 100);
			g.drawLine(350, 250, 350, 450);
			g.drawLine(350,250,250,350);
			g.drawLine(350,250,450,350);
			g.drawLine(350,450,250,550);
			break;
		case 6:
			g.drawOval(300, 150, 100, 100);
			g.drawLine(350, 250, 350, 450);
			g.drawLine(350,250,250,350);
			g.drawLine(350,250,450,350);
			g.drawLine(350,450,250,550);
			g.drawLine(350, 450, 450, 550);
			break;
		default:
			break;
		}
		
	}
	public boolean gresit(){
		greseli++;
		this.repaint();
		if(greseli==6)
			return true;
		return false;
	}

}

