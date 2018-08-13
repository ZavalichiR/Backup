package factory;

import javax.swing.JFrame;

import factory.Campdelupta;

public class Main {

	public static void main(String[] args) {
		try{
			//GeneralObserver board = new GeneralObserver();
			Ship s1=ShipFactory.getForm(ShipFactory.CUBE,"blue",FireTypeFactory.getForm(FireTypeFactory.LINEAR,"mitraliera"));
			Ship s2=ShipFactory.getForm(ShipFactory.PYRAMIDAL,"yellow",FireTypeFactory.getForm(FireTypeFactory.BLAST,"minge de foc"));
			Ship s3=ShipFactory.getForm(ShipFactory.SPHERICAL,"green",FireTypeFactory.getForm(FireTypeFactory.ROCKET,"multi cilindri"));
			s1.seeInfo();
			s2.seeInfo();
			s3.seeInfo();
			s1.addObserver(s2);
			s2.addObserver(s3);
			s3.addObserver(s1);
			s1.ChangeStats("orange",FireTypeFactory.getForm(FireTypeFactory.LINEAR,"mitraliera2"));
			s2.ChangeStats("black",FireTypeFactory.getForm(FireTypeFactory.LINEAR,"mingi de gheata"));
			s3.ChangeStats("white",FireTypeFactory.getForm(FireTypeFactory.LINEAR,"multi cilindri"));
			}catch (Exception e){
				e.printStackTrace();
			}finally{
			}
		//JFrame frame=new JFrame();
		new Campdelupta().setVisible(true);
	}

}
