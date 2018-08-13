package canvas;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.ArrayList;

import javax.swing.JOptionPane;

public class Joc extends Frame{
	
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private Draw desen;
	private ArrayList<String> cuvinte=new ArrayList<String>();
	private String ales,ramasAfis="",litereGres="",ramas="";
	private Label cuvDeGhicit,litereGresite,cuvDeGhicitLbl,litereGresiteLbl;
		
	public Joc(String titlu){
		super(titlu);
		setLayout(null);
		setExtendedState(Frame.MAXIMIZED_BOTH); //mareste fereastra din prima
		
		addWindowListener(new WindowAdapter() {
			public void windowClosing(WindowEvent e){
				System.exit(0);
			}
		});
		
		desen=new Draw();
		add(desen);
		initCuvinte();
		
		cuvDeGhicit=new Label(ramasAfis);
		litereGresite=new Label("");
		cuvDeGhicitLbl=new Label("Cuvantul:");
		litereGresiteLbl=new Label("Litere introduse: ");
		
		
		cuvDeGhicitLbl.setBounds(600,280,100,20); //pozitionare
		cuvDeGhicit.setBounds(600,300,300,20);  //pozitionare
		
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
						char []rms=ramasAfis.toCharArray();
						
						rms[2*i]=e.getKeyChar();
						ramasAfis=String.valueOf(rms);
						
						rms=ramas.toCharArray();
						rms[i]=e.getKeyChar();
						ramas=String.valueOf(rms);
						
						
					}
				}
						
				
				if(ok){
					cuvDeGhicit.setText(ramasAfis);
					if(ales.compareTo(ramas)==0){
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
		//arata mesaj de tip pop-up
		JOptionPane.showMessageDialog(this, "Ai pierdut!");
		System.exit(0);
	}
	private void castigat(){
		//arata mesaj de tip pop-up
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
			ramas=ramas+"_";
			ramasAfis=ramasAfis+"_ ";
		}
	}
}
