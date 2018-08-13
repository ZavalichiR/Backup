package Figuri;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.GridLayout;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;


public class Draw extends JFrame implements ActionListener{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JPanel panel;
	private JPanel controlpanel;
	private JPanel figura;
	private TextField text;
	private JButton []b;
	private JButton exit;
	Draw()
	{
		this.setBackground(Color.yellow);
		this.setLayout(new BorderLayout());
		this.setSize(400, 400);
		this.setVisible(true);
		
			
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
		controlpanel =new JPanel();
		controlpanel.setLayout(new BorderLayout());
		
		panel=new JPanel();
		panel.setLayout(new FlowLayout());
		
		figura=new JPanel();
		figura.setLayout(new GridLayout(10,2));
		
		controlpanel.add(panel,BorderLayout.NORTH);
		controlpanel.add(figura,BorderLayout.CENTER);
		
		add(controlpanel);
		
		
		text=new TextField();
		panel.add(text);
		
		b=new JButton[3];
		b[0]=new JButton("Speeder");
		b[1]=new JButton("Spy");
		b[2]=new JButton("Mother");
		
		
		
		for(int i=0;i<3;++i)
		{
			panel.add(b[i]);
			b[i].addActionListener(this);
		}
		exit=new JButton("EXIT");
		exit.setSize(20, 20);
		exit.setBackground(Color.red);
		panel.add(exit);
		exit.addActionListener(this);
		
		
		
	}
	@Override
	public void actionPerformed(ActionEvent e) {
		String command=e.getActionCommand();
		if(command.equals("EXIT")){
			System.exit(0);
		}
		else
		{
			JLabel thumb = new JLabel();
			figura.add(thumb);
			text.setText(command);
			if(command.equals("Speeder"))
			{
				thumb.setIcon(new ImageIcon("Speeder.jpg"));
				revalidate();
				repaint();
							}
			if(command.equals("Spy"))
			{
				thumb.setIcon(new ImageIcon("Spy.jpg"));
				revalidate();
	            repaint();
				
			}
			if(command.equals("Mother"))
			{
				thumb.setIcon(new ImageIcon("Mother.jpg"));
				revalidate();
	            repaint();
			}	
			           
			text.setBackground(Color.yellow);
			
		}
	}
	
}