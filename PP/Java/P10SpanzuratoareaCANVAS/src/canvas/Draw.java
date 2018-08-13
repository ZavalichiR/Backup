package canvas;


import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;

public class Draw extends Canvas{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	int greseli=0;
	public Draw(){
		//Genereaza un dreptunghi din coltul 20,50 in coltul 500,650
		super();	
		setBounds(20,50,500,650);
		setBackground(Color.cyan);
		
		repaint();
	}
	
	public void paint(Graphics g){
		//Deseneaza suportul pentru cel spanzurat
		g.drawLine(50,600,250,600);
		g.drawLine(150,600,150,100);
		g.drawLine(150,100,350,100);
		g.drawLine(350,100,350,150);
		
		
		
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
		repaint();  //deseneaza pe ecran cand introduci gresit
		if(greseli==6)
			return true;
		return false;
	}

}
