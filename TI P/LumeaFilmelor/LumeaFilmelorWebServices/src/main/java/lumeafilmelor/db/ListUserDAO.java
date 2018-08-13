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

import lumeafilmelor.core.User;
import lumeafilmelor.core.UserDAO;

public class ListUserDAO implements UserDAO {

	private static UserDAO instance = new ListUserDAO();

	public static UserDAO instance() {
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
	 
	private ListUserDAO() {
		conn = null;
		try {
			Class.forName("org.sqlite.JDBC");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block

			System.out.println("Nu s-a conecatat la baza de date Err1!!!");
			e.printStackTrace();
		}
		try {
			conn = DriverManager.getConnection("jdbc:sqlite:C:\\sqlite\\testdb.db");
		} catch (SQLException e) {
			// TODO Auto-generated catch block

			System.out.println("Nu s-a conecatat la baza de date Err2!!");
			e.printStackTrace();
		}
		System.out.println("Conectarea la baza de date a avut succes!");
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see ro.h23.bookmanager.core.UserDAO#getUsers()
	 */
	@Override
	public List<User> getUsers() throws SQLException {

		List<User> users  = Collections.synchronizedList(new ArrayList<>());

		statmt=conn.createStatement();
		resSet = statmt.executeQuery("SELECT * FROM USERS");

		while(resSet.next())
		{
			String  uname = resSet.getString("username");
			String  upassword = resSet.getString("password");
			users.add(new User(uname,upassword));
		}	
		return users;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see ro.h23.bookmanager.core.UserDAO#findUserById(java.lang.String)
	 */
	@Override
	public User getUser(String username) throws SQLException{
		List<User> users  = Collections.synchronizedList(new ArrayList<>());
		resSet = statmt.executeQuery("SELECT * FROM users");

		while(resSet.next())
		{
			String  uname = resSet.getString("username");
			String  upassword = resSet.getString("password");
			users.add(new User(uname,upassword));
		}	
		return users.stream().filter(o -> Objects.equals(o.getUsername(), username)).findFirst().orElse(null);
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see ro.h23.bookmanager.core.UserDAO#findUserByISBN(java.lang.String)
	 *//*
    @Override
    public User findUserByISBN(String isbn) {
        return books.stream().filter(o -> o.getISBN().equals(isbn)).findFirst().orElse(null);
    }*/

	/*
	 * (non-Javadoc)
	 * 
	 * @see ro.h23.bookmanager.core.UserDAO#addUser(ro.h23.bookmanager.core.User)
	 */
	@Override
	public boolean addUser(User user) throws SQLException {
		if (getUser(user.getUsername()) != null) {
			return false;
		}
		try {
			statmt.execute("INSERT INTO 'users' ('username', 'password') VALUES ('"+user.getUsername()+"', '"+user.getPassword()+"'); ");
		} catch (SQLException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//if (user.getUsername() != User.MISSING_ID) {
		// if the book is already in the db
		/* if (findUserById(book.getId()) != null) {
                return false;
            } else {
                // next line avoids having books with the same id in the db
                nextId = Math.max(book.getId() + 1, nextId);
            }*/
		/* } else {
            book.setId(nextId++);
        }*/
		//books.add(book);
		return true;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see ro.h23.bookmanager.core.UserDAO#updateUser(ro.h23.bookmanager.core.User)
	 */
	@Override
	public boolean updateUser(String username, User user) throws SQLException {
		boolean found = false;

		resSet = statmt.executeQuery("SELECT * FROM USERS");

		while(resSet.next())
		{
			String  uname = resSet.getString("username");
			String  upass = resSet.getString("password");
			if(Objects.equals(uname,username))
			{
				statmt.executeUpdate("UPDATE users SET username=\'"+user.getUsername()+"\' WHERE username=\'"+username+"\'");
				if(!Objects.equals(upass, user.getPassword()))
						statmt.executeUpdate("UPDATE users SET password=\'"+user.getPassword()+"\' WHERE username=\'"+user.getUsername()+"\'");
				
				found=true;
				break;
			}
		}	
		return found;
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see ro.h23.bookmanager.core.UserDAO#deleteUser(ro.h23.bookmanager.core.User)
	 */
	@Override
	public boolean deleteUser(String username) throws SQLException {
		boolean found = false;
		resSet = statmt.executeQuery("SELECT * FROM users");

		while(resSet.next())
		{
			String  uname = resSet.getString("username");
			if(Objects.equals(uname,username))
			{
				statmt.executeQuery("DELETE FROM users WHERE username="+username);
				found=true;
				break;
			}
		}	
		return found;
	}

	


}
