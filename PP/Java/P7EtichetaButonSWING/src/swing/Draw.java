package swing;


import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextField;

import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;


public class Draw extends JFrame implements ActionListener{
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	JButton []b;
	JButton exit;
	JTextField text;
	
	Draw(String nume)
	{
		super(nume);
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
	
		this.setLayout(new FlowLayout());
		this.setVisible(true);
		this.setSize(350,100);
		this.setBackground(Color.GREEN);
		
		
		text=new JTextField();
		text.setSize(50, 50);
		this.add(text);
		
		b=new JButton[3];
		b[0]=new JButton("1");
		b[1]=new JButton("2");
		b[2]=new JButton("3");
		
		for(int i=0;i<3;++i)
		{
			this.add(b[i]);
			b[i].addActionListener(this);
		}
		
		exit=new JButton("EXIT");
		this.add(exit);
		exit.addActionListener(this);
		
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		String comanda=e.getActionCommand();
		if(comanda.equals("EXIT"))
			System.exit(0);
		else
		{
			text.setText(comanda);
			text.setBackground(Color.BLUE);
		}
	}
	
}
