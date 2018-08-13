package swing;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;

import javax.swing.JDialog;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JTextArea;


@SuppressWarnings("serial")
public class Notepad extends JFrame implements ActionListener{
	int ok=1;
	JMenuItem f1,f2,f3,f4,f5,f6,f7,for1,for2,e1,e2,e3,e4,e5,h1,h2,m1;
	JMenuBar bara_meniu;
	JMenu edit,fisier,help,format,view;
	JDialog load,save;
	JTextArea text;
	
	Notepad(String titlu){
		super(titlu);
		
		this.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent e){
				dispose();
				System.exit(0);
			}
		});
		
		
	
		bara_meniu=new JMenuBar();
		
		fisier=new JMenu("File");
			f1=new JMenuItem("New");
			f2=new JMenuItem("Open");
			f3=new JMenuItem("Save");
			f4=new JMenuItem("Save as");
			f5=new JMenuItem("Page Setup");
			f6=new JMenuItem("Print");
			f7=new JMenuItem("Exit");	
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
		
		edit=new JMenu("Edit");		
			e1=new JMenuItem("Undo");
			e2=new JMenuItem("Cut");
			e3=new JMenuItem("Copy");
			e4=new JMenuItem("Paste");
			e5=new JMenuItem("Delete");	
				edit.add(e1);
				edit.addSeparator();
				edit.add(e2);
				edit.add(e3);
				edit.add(e4);
				edit.add(e5);
		
		format=new JMenu("Format");
			for1=new JMenuItem("Word Wrap");
			for2=new JMenuItem("Font");	
				format.add(for1);
				format.add(for2);
		
		view=new JMenu("View");
			m1=new JMenuItem("Status Bar");
				view.add(m1);
		
		help=new JMenu("Help");
			h1=new JMenuItem("View Help");
			h2=new JMenuItem("About Help");
				help.add(h1);
				help.addSeparator();
				help.add(h2);
	
		bara_meniu.add(fisier);
		bara_meniu.add(help);
		bara_meniu.add(view);
		bara_meniu.add(format);
		bara_meniu.add(edit);
		setJMenuBar(bara_meniu); //face bara vizibila
		
		
		text=new JTextArea();//textul
		add(text);
		
		
		setSize(400,400);
		
	}


	@Override
	public void actionPerformed(ActionEvent arg0) {
		// TODO Auto-generated method stub
		
	}
	
	
}
