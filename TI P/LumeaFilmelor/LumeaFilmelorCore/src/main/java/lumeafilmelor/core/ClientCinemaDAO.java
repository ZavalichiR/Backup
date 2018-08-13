package lumeafilmelor.core;

import java.sql.SQLException;
import java.util.List;

public interface ClientCinemaDAO {
	List<String[]> getBilete() throws SQLException;
	boolean addClientCinema(ClientCinema client) throws SQLException;
	List<String[]> getBileteById(String IdFilm) throws SQLException;
}
