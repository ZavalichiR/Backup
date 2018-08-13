package lumeafilmelor.db;

import java.lang.reflect.Array;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Objects;

import lumeafilmelor.core.ClientCinema;
import lumeafilmelor.core.ClientCinemaDAO;
import lumeafilmelor.core.Filme;

public class ListaClientiCinemaDAO implements ClientCinemaDAO{
	private static ListaClientiCinemaDAO instance = new ListaClientiCinemaDAO();

    public static ListaClientiCinemaDAO instance() {
        return instance;
    }

    public static Connection conn;
	public static Statement statmt;
	public static ResultSet resSet;

	public void disconnectDB() throws SQLException {
		conn.close();
		statmt.close();
		resSet.close();
		
		System.out.println("Totul e inchis");
	}
	
	/*Pentru creare tabel, trebuie ceva de genul:
	 * statmt = conn.createStatement();
	 * statmt.execute("CREATE TABLE if not exists 'users' ('id' INTEGER PRIMARY KEY AUTOINCREMENT, 'name' text, 'phone' INT);");
	 */
	 
	private ListaClientiCinemaDAO() {
		conn = null;
		try {
			Class.forName("org.sqlite.JDBC");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block

			System.out.println("Eroare: Conectare la Baza de date");
			e.printStackTrace();
		}
		try {
			conn = DriverManager.getConnection("jdbc:sqlite:C:\\sqlite\\LumeaFilmelorDB.db");
		} catch (SQLException e) {
			// TODO Auto-generated catch block

			System.out.println("Eroare: Conectare la Baza de date");
			e.printStackTrace();
		}
		System.out.println("Baza Conectata!");
	}
	

	@Override
	public boolean addClientCinema(ClientCinema client) throws SQLException {
		System.out.println("AddClientCinema in baza de date: "+client.getNume()+", "+client.getPrenume()+","+client.getTelefon()+","+client.getLocuri()+","+client.getScaune());
		String cmd="INSERT INTO ClientCinema (Nume, Prenume, Telefon, Locuri, Scaune, IdFilm) VALUES ('"+client.getNume()+"', '"+client.getPrenume()+"', '"+client.getTelefon()+"', '"+client.getLocuri()+"', '"+client.getScaune()+"', '"+client.getId()+"');" ;
		System.out.println("COmanda: "+cmd);
		statmt=conn.createStatement();
		statmt.execute(cmd);
			System.out.println("Inserare SUCCES!\n"+client.getNume()+"\n"+client.getPrenume()+"\n"+client.getTelefon()+"\n"+client.getLocuri()+"\n"+client.getScaune()+"\n"+client.getId());
		System.out.println("Return");
		return true;
	}

	@Override
	public List<String[]> getBilete() throws SQLException {
		List<String[]> bilete  = Collections.synchronizedList(new ArrayList<>());

		statmt=conn.createStatement();
		resSet = statmt.executeQuery("SELECT * FROM ClientCinema");

		while(resSet.next())
		{
			String bilete1=resSet.getString("Locuri");
			String[] locuri=bilete1.split(",");
			bilete.add(locuri);
		}
		System.out.print("[ListaClientiCinemaDAO] Selectare cu succes");
		return bilete;
	}
	
	@Override
	public List<String[]> getBileteById(String IdFilm) throws SQLException {
		List<String[]> bilete  = Collections.synchronizedList(new ArrayList<>());

		statmt=conn.createStatement();
		resSet = statmt.executeQuery("SELECT * FROM ClientCinema WHERE IdFilm="+IdFilm);

		while(resSet.next())
		{
				String bilete1=resSet.getString("Locuri");
				String[] locuri=bilete1.split(",");
				bilete.add(locuri);
					
		}
		System.out.print("[ListaClientiCinemaDAO] Selectare cu succes");
		return bilete;
	}
	
}
