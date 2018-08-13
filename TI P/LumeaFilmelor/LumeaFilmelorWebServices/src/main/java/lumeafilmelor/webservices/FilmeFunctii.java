package lumeafilmelor.webservices;
import java.sql.SQLException;
import java.util.List;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import lumeafilmelor.core.Filme;
import lumeafilmelor.db.ListaClientiCinemaDAO;
import lumeafilmelor.db.ListaFilmeDAO;


//e.g., @ApplicationPath("api") + @Path("/filme") =>
//http://localhost:8080/LumeaFilmelorrWebServices/api/filme
@Path("/filme")
public class FilmeFunctii {

    private static Logger log = LoggerFactory.getLogger(FilmeFunctii.class);

    // based on: http://www.vogella.com/tutorials/REST/article.html#jerseyprojectsetup

    /**
     * Requests transfer of a current selected representation for the target resource (i.e., the
     * book collection)
     * @throws SQLException 
     */
    @GET
    @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public List<Filme> getFilm() throws SQLException {
        log.info("getFilme");
        return ListaFilmeDAO.instance().getFilm();
    }

    /**
     * Requests transfer of a current selected representation for the target resource (i.e., a book
     * by ISBN).
     * @throws SQLException 
     */
    @GET
    @Path("{filmId}")
    @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public Filme getFilmById(@PathParam("filmId") Integer filmId) throws SQLException {
        return ListaFilmeDAO.instance().getFilmById(filmId);
    }
    

}    
