package swing;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JTextField;

public class Coordonate extends JFrame{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JTextField text;
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
		//getContentPane -pentru swing
		getContentPane().setLayout(new FlowLayout()); 
		getContentPane().setBackground(Color.BLUE);
		
		text=new JTextField();
		this.add(text);
		
		this.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent e){
				x=e.getX();
				y=e.getY();
				text.setSize(100,20);
				text.setSelectionStart(10);
				text.setText("X="+x+"  Y="+y);
				text.setBackground(Color.YELLOW);
				text.setLocation(100,0);
				
			}
		});
		
	}

	
}
