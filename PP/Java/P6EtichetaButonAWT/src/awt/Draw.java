package awt;

import java.awt.Button;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Frame;
import java.awt.TextField;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

public class Draw extends Frame implements ActionListener{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Button []b;
	private Button exit;
	private TextField text;
	
	Draw(String nume){
		super(nume); //need extends Frame
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose(); //inchide doar o fereastra
				System.exit(0);  //inchide toate ferestrele
			}
		});
		
		this.setLayout(new FlowLayout());
		this.setBackground(Color.green);
		this.setSize(50,100);
		
		this.setVisible(true);
		
		text=new TextField();
		this.add(text);
		
		b=new Button[3];
		b[0]=new Button("1");
		b[1]=new Button("2");
		b[2]=new Button("3");
		
		for(int i=0;i<3;++i)
		{
			this.add(b[i]);
			b[i].addActionListener(this);
		}
		
		exit=new Button("EXIT");
		this.add(exit);
		exit.addActionListener(this);
		
	}
	
	public void actionPerformed(ActionEvent e){
		String comanda=e.getActionCommand();
		if(comanda.equals("EXIT"))
		{
			System.exit(0);
		}
		else
		{
			text.setText(comanda);
			text.setBackground(Color.BLUE);
		}
	}
}
