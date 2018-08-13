package awt;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.TextField;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class Coordonate extends Frame{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	TextField text;
	static int x,y;
	
	Coordonate(String nume)
	{
		super(nume);
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
		
		
		this.setSize(300, 300);
		this.setVisible(true);
		this.setLayout(new FlowLayout());
		
		text=new TextField();
		this.add(text);
		
		this.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent e){
				x=e.getX();
				y=e.getY();
				text.setSize(100,20);
				text.setSelectionStart(10);
				text.setText("X="+x+"  Y="+y);
				text.setBackground(Color.YELLOW);
				text.setLocation(6,30);
				
			}
		});
		
	}

	
}
