package jpanel;



import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

import javax.swing.JFrame;
import javax.swing.JOptionPane;

public class Joc extends JFrame{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Draw desen;
	private ArrayList<String> cuvinte=new ArrayList<String>();
	private String ales,ramas="",litereGres="";
	private Label cuvDeGhicit,litereGresite,cuvDeGhicitLbl,litereGresiteLbl;
	private int contor=0;
	
	public Joc(String titlu){
		super(titlu);
		setLayout(null);
		//setSize(600,600);
		setExtendedState(Frame.MAXIMIZED_BOTH);
		
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
		
		desen=new Draw();
		desen.setBounds(20,50,500,650);
		add(desen);
		initCuvinte();
		
		cuvDeGhicit=new Label(ramas);
		litereGresite=new Label("");
		cuvDeGhicitLbl=new Label("Cuvantul:");
		litereGresiteLbl=new Label("Litere introduse: ");
		
		
		cuvDeGhicitLbl.setBounds(600,280,100,20);
		cuvDeGhicit.setBounds(600,300,300,20);
		
		litereGresiteLbl.setBounds(600,350,100,20);
		litereGresite.setBounds(600,370,150,20);
		
		add(cuvDeGhicit);
		add(litereGresite);
		add(cuvDeGhicitLbl);
		add(litereGresiteLbl);
		addKeyListener(new KeyListener() {
			
			@Override
			public void keyTyped(KeyEvent e) {
				// TODO Auto-generated method stub
				boolean ok=false;
				for(int i=0;i<ales.length();i++)
				{
					if(e.getKeyChar() == ales.charAt(i)){
						ok=true;
						char []rms=ramas.toCharArray();
						
						rms[2*i]=e.getKeyChar();
						ramas=String.valueOf(rms);
						contor++;
						
					}
				}
				if(ok){
					cuvDeGhicit.setText(ramas);
					if(contor==ales.length()){
						castigat();
					}
				}
				else{
					litereGres=litereGres+e.getKeyChar()+",";
					litereGresite.setText(litereGres);
					if( desen.gresit() == true)
					{
						pierdut();
					}
					
				}
				
			}
			
			@Override
			public void keyReleased(KeyEvent e) {
				// TODO Auto-generated method stub
				
				
				
			}
			
			@Override
			public void keyPressed(KeyEvent e) {
				// TODO Auto-generated method stub
				
			}
		});	
				
		
		setVisible(true);
	}
	private void pierdut(){
		JOptionPane.showMessageDialog(this, "Ai pierdut!");
		System.exit(0);
	}
	private void castigat(){
		JOptionPane.showMessageDialog(this, "Ai castigat!");
		System.exit(0);
	}
	private void initCuvinte(){
		cuvinte.add("spanzuratoarea");
		cuvinte.add("programare");
		cuvinte.add("tiberiu");
		cuvinte.add("chimie");
		cuvinte.add("computer");
		cuvinte.add("floare");
		cuvinte.add("anticariat");
		cuvinte.add("urata");
		
		
		ales=cuvinte.get(( (int) (Math.random()*cuvinte.size()) ) );
		
		for(int i=0;i<ales.length();i++){
			ramas=ramas+"_ ";
		}
	}
}
