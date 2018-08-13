package Coordonate;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JFrame;
import javax.swing.JTextField;

public class Mouse extends JFrame implements ActionListener {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JTextField text;
	static int x,y;
	
	Mouse(String titlu){
		super(titlu);
		this.setSize(300, 200);
		this.setVisible(true);
		this.setBackground(Color.blue);
		this.setLayout(new FlowLayout());
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
		
		text=new JTextField();
		add(text);
		
		this.addMouseListener(new MouseAdapter(){
			public void mouseClicked(MouseEvent e) {
				x=e.getX();
				y=e.getY();
				text.setSelectionStart(10);
				text.setSize(100, 20);
				text.setText("X= "+x+" "+"     Y= "+y);
				text.setBackground(Color.YELLOW);
				text.setLocation(100,0);
			}
		});
		
	}
	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}

}

