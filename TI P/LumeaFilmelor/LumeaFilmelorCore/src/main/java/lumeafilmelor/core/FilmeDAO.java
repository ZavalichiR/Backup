package lumeafilmelor.core;
import java.sql.SQLException;
import java.util.List;

import lumeafilmelor.core.Filme;


public interface FilmeDAO {

	List<Filme> getFilm() throws SQLException;

    Filme getFilmById(Integer filmId) throws SQLException;

    /**
     * 
     * @param book
     *            is updated with the id inside this method
     * @return <code>true</code> if the book was added successfully, <code>false</code> if the book
     *         already exists
     * @throws SQLException 
     */
    
	    
}
