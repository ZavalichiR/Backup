package lumeafilmelor.core;

import java.sql.SQLException;
import java.util.List;


public interface UserDAO {

    List<User> getUsers() throws SQLException;

    User getUser(String username) throws SQLException;

    /**
     * 
     * @param book
     *            is updated with the id inside this method
     * @return <code>true</code> if the book was added successfully, <code>false</code> if the book
     *         already exists
     * @throws SQLException 
     */
    

    //int getID(User user) throws SQLException;
    boolean addUser(User user) throws SQLException;

    boolean updateUser(String username, User user) throws SQLException;
    
    boolean deleteUser(String username) throws SQLException;
}
