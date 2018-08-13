package lumeafilmelor.webservices;

import java.sql.SQLException;
import java.util.List;

import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.UriBuilderException;
import javax.ws.rs.core.UriInfo;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import lumeafilmelor.core.ClientCinema;
import lumeafilmelor.db.ListaClientiCinemaDAO;

@Path("/clientCinema")
public class ClientCinemaFunctii {
	private static Logger log = LoggerFactory.getLogger(ContactFunctii.class);

	@POST
	 @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public boolean addClientCinema(@Context UriInfo uriInfo, ClientCinema client) throws IllegalArgumentException, UriBuilderException, SQLException {
        System.out.println("[ClientcinemaFinctii}: @POST: "+client.getNume()+"\n"+client.getPrenume()+"\n"+client.getTelefon()+"\n"+client.getLocuri()+"\n"+client.getScaune());
        return ListaClientiCinemaDAO.instance().addClientCinema(client);
	}
	
	@GET
    @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public List<String[]> getBilete() throws SQLException {
        log.info("[ClientCinemaFunctii] get Bilete Clienti cinema");
        return ListaClientiCinemaDAO.instance().getBilete();
    }
    
    @GET
    @Path("{IdFilm}")
    @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public List<String[]> getBileteById(@PathParam("IdFilm") String IdFilm) throws SQLException {
        log.info("[ClientCinemaFunctii] get Bilete Clienti cinema");
        return ListaClientiCinemaDAO.instance().getBileteById(IdFilm);
    }
	
}
