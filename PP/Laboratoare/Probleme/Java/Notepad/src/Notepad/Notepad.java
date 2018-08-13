package Notepad;


import java.awt.*;
import java.awt.event.*;


@SuppressWarnings("serial")
public class Notepad extends Frame implements ActionListener{
	int ok=1;
	MenuItem f1,f2,f3,f4,f5,f6,f7,for1,for2,e1,e2,e3,e4,e5,h1,h2,m1;
	MenuBar bara_meniu;
	Menu edit,fisier,help,format,view;
	FileDialog load,save;
	TextArea text;
	
	Notepad(String titlu){
		super(titlu);
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
		
		
	
		bara_meniu=new MenuBar();
		
		fisier=new Menu("File");
		f1=new MenuItem("New");
		fisier.add(f1);
		f2=new MenuItem("Open");
		fisier.add(f2);
		f3=new MenuItem("Save");
		fisier.add(f3);
		f4=new MenuItem("Save as");
		fisier.add(f4);
		fisier.addSeparator(); //linie
		f5=new MenuItem("Page Setup");
		fisier.add(f5);
		f6=new MenuItem("Print");
		fisier.add(f6);
		fisier.addSeparator(); //linie
		f7=new MenuItem("Exit");
		fisier.add(f7);
		
		f1.addActionListener(this);
		f2.addActionListener(this);
		f3.addActionListener(this);
		f4.addActionListener(this);
		f5.addActionListener(this);
		f6.addActionListener(this);
		f7.addActionListener(this);
		
		edit=new Menu("Edit");
		e1=new MenuItem("Undo");
		edit.add(e1);
		edit.addSeparator();
		e2=new MenuItem("Cut");
		edit.add(e2);
		e3=new MenuItem("Copy");
		edit.add(e3);
		e4=new MenuItem("Paste");
		edit.add(e4);
		e5=new MenuItem("Delete");
		edit.add(e5);
		
		format=new Menu("Format");
		for1=new MenuItem("Word Wrap");
		format.add(for1);
		for2=new MenuItem("Font");
		format.add(for2);
		
		view=new Menu("View");
		m1=new MenuItem("Status Bar");
		view.add(m1);
		
		help=new Menu("Help");
		 h1=new MenuItem("View Help");
		help.add(h1);
		help.addSeparator();
		 h2=new MenuItem("About Help");
		help.add(h2);
	
		bara_meniu.add(fisier);
		bara_meniu.add(help);
		bara_meniu.add(view);
		bara_meniu.add(format);
		bara_meniu.add(edit);
		setMenuBar(bara_meniu);
		
		
		text=new TextArea();//textul
		add(text);
		
		
		setSize(400,400);
		
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}
	
	
}
