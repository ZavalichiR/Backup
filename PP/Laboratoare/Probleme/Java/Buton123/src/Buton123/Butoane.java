package Buton123;

import java.awt.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class Butoane extends Frame implements ActionListener{
	Button []b;
	Button exit;
	TextField text;
	
	Butoane(String titlu){
		
		super(titlu); //constructor
		this.setBackground(Color.green);
		this.setLayout(new FlowLayout());
		this.setSize(300, 200);
		//pentru BUTONUL X
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
		
		text=new TextField();
		add(text);
	
		b=new Button[3];
		b[0]=new Button("1");
		b[1]=new Button("2");
		b[2]=new Button("3");
		
		exit=new Button("EXIT");
		exit.setSize(20, 20);
		exit.setBackground(Color.red);


		for(int i=0;i<3;i++){
			add(b[i]);
			b[i].addActionListener(this);
		}
		add(exit);
		exit.addActionListener(this);
		
		
	}
	public void actionPerformed(ActionEvent e) {
		String command=e.getActionCommand();
		if(command.equals("EXIT")){
			System.exit(0);
		}
		else{
			text.setText(command);
			
			text.setBackground(Color.yellow);
		}
		
	}


}
