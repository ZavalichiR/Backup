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

import lumeafilmelor.core.Filme;
import lumeafilmelor.core.FilmeDAO;
import lumeafilmelor.db.ListaFilmeDAO;

public class ListaFilmeDAO implements FilmeDAO{
	
	 private static FilmeDAO instance = new ListaFilmeDAO();

	    public static FilmeDAO instance() {
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
		
		 
		private ListaFilmeDAO() {
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

		/*
		 * (non-Javadoc)
		 * 
		 * @see lumeafilmelor.core.filmeDAO#getFilme()
		 */
		@Override
		public List<Filme> getFilm() throws SQLException {

			List<Filme> filme  = Collections.synchronizedList(new ArrayList<>());

			statmt=conn.createStatement();
			resSet = statmt.executeQuery("SELECT * FROM Filme");

			while(resSet.next())
			{
				 Integer Id= resSet.getInt("Id");
				 String Titlu= resSet.getString("Titlu");  
			     String OriginalTitlu= resSet.getString("OriginalTitlu");
			     String  Gen= resSet.getString("Gen");
			     String Durata= resSet.getString("Durata");
			     String  Limba= resSet.getString("Limba");
			     String Premiera= resSet.getString("Premiera");
			     String  Regizor= resSet.getString("Regizor");
			     String Actori= resSet.getString("Actori");
			     Integer An= resSet.getInt("An");
			     String  Descriere= resSet.getString("Descriere");
			     String Trailer= resSet.getString("Trailer");
			     String  Imagine= resSet.getString("Imagine");
			     
				
				filme.add(new Filme(Id,  Titlu,  OriginalTitlu,   Gen,  Durata,   Limba,  Premiera,   Regizor,  Actori, An,   Descriere,  Trailer,   Imagine));
			}	
			return filme;
		}

		/*
		 * (non-Javadoc)
		 * 
		 * @see lumeafilmelor.core.FilmeDAO#findFilmById(java.lang.String)
		 */
		@Override
		public Filme getFilmById(Integer filmId) throws SQLException{
			List<Filme> filme  = Collections.synchronizedList(new ArrayList<>());
			statmt=conn.createStatement();
			resSet = statmt.executeQuery("SELECT * FROM Filme" );

			while(resSet.next())
			{
				Integer Id= resSet.getInt("Id");
				 String Titlu= resSet.getString("Titlu");  
			     String OriginalTitlu= resSet.getString("OriginalTitlu");
			     String  Gen= resSet.getString("Gen");
			     String Durata= resSet.getString("Durata");
			     String  Limba= resSet.getString("Limba");
			     String Premiera= resSet.getString("Premiera");
			     String  Regizor= resSet.getString("Regizor");
			     String Actori= resSet.getString("Actori");
			     Integer An= resSet.getInt("An");
			     String  Descriere= resSet.getString("Descriere");
			     String Trailer= resSet.getString("Trailer");
			     String  Imagine= resSet.getString("Imagine");
			     
				
				filme.add(new Filme(Id,  Titlu,  OriginalTitlu,   Gen,  Durata,   Limba,  Premiera,   Regizor,  Actori, An,   Descriere,  Trailer,   Imagine));
			}	
			return filme.stream().filter(o -> Objects.equals(o.getId(), filmId)).findFirst().orElse(null);
		}

	    
}
