package lumeafilmelor.db;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Objects;

import lumeafilmelor.core.Contact;
import lumeafilmelor.core.ContactDAO;
import lumeafilmelor.core.FilmeDAO;
import lumeafilmelor.core.User;


public class ListaContacteDAO implements ContactDAO{
	private static ListaContacteDAO instance = new ListaContacteDAO();

    public static ListaContacteDAO instance() {
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
	 
	private ListaContacteDAO() {
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
	public boolean addContact(Contact user) throws SQLException {
		System.out.println("AddContact in baza de date: "+user.getNume()+", "+user.getMail()+","+user.getMesaj());
		
		String cmd="INSERT INTO Contacte (Nume, Mail,Mesaj) VALUES ('"+user.getNume()+"', '"+user.getMail()+"', '"+user.getMesaj()+"'); ";
		System.out.println("COmanda: "+cmd);
		statmt=conn.createStatement();
		statmt.execute(cmd);
			System.out.println("Inserare SUCCES!"+user.getNume()+user.getMesaj()+user.getMail());
		System.out.println("Return");
		return true;
	}

	@Override
	public List<Contact> getContacts() throws SQLException {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public Contact getContact(String name) throws SQLException {
		// TODO Auto-generated method stub
		return null;
	}

}
