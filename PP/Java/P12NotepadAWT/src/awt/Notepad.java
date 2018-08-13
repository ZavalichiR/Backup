package awt;


import java.awt.*;
import java.awt.event.*;


@SuppressWarnings("serial")
public class Notepad extends Frame implements ActionListener{
	int ok=1;
	MenuItem f1,f2,f3,f4,f5,f6,f7,for1,for2,e1,e2,e3,e4,e5,h1,h2,m1;
	MenuBar bara_meniu;
	Menu edit,fisier,help,format,view;
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
			f2=new MenuItem("Open");
			f3=new MenuItem("Save");
			f4=new MenuItem("Save as");
			f5=new MenuItem("Page Setup");
			f6=new MenuItem("Print");
			f7=new MenuItem("Exit");	
				fisier.add(f1);
				fisier.add(f2);
				fisier.add(f3);
				fisier.add(f4);
				fisier.addSeparator(); //linie
				fisier.add(f5);
				fisier.add(f6);
				fisier.addSeparator(); //linie
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
			e2=new MenuItem("Cut");
			e3=new MenuItem("Copy");
			e4=new MenuItem("Paste");
			e5=new MenuItem("Delete");	
				edit.add(e1);
				edit.addSeparator();
				edit.add(e2);
				edit.add(e3);
				edit.add(e4);
				edit.add(e5);
		
		format=new Menu("Format");
			for1=new MenuItem("Word Wrap");
			for2=new MenuItem("Font");	
				format.add(for1);
				format.add(for2);
		
		view=new Menu("View");
			m1=new MenuItem("Status Bar");
				view.add(m1);
		
		help=new Menu("Help");
			h1=new MenuItem("View Help");
			h2=new MenuItem("About Help");
				help.add(h1);
				help.addSeparator();
				help.add(h2);
	
		bara_meniu.add(fisier);
		bara_meniu.add(help);
		bara_meniu.add(view);
		bara_meniu.add(format);
		bara_meniu.add(edit);
		setMenuBar(bara_meniu); //face bara vizibila
		
		
		text=new TextArea();//textul
		add(text);
		
		
		setSize(400,400);
		
	}

	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}
	
	
}
