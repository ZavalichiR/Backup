package lumeafilmelor.webservices;

import java.sql.SQLException;

import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.UriBuilderException;
import javax.ws.rs.core.UriInfo;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import lumeafilmelor.core.Contact;
import lumeafilmelor.db.ListaContacteDAO;

@Path("/contacte")
public class ContactFunctii {
	private static Logger log = LoggerFactory.getLogger(ContactFunctii.class);

	@POST
	 @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public boolean addContact(@Context UriInfo uriInfo, Contact user) throws IllegalArgumentException, UriBuilderException, SQLException {
        System.out.println("[ContactFunctii}: @POST: "+user.getNume()+", "+user.getMail()+", "+user.getMesaj());
        return ListaContacteDAO.instance().addContact(user);
    }
	/*@Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public Response postContact(@Context UriInfo uriInfo, Contact user) throws IllegalArgumentException, UriBuilderException, SQLException {
        log.info("postUsers: {}  {}  {}", user.getNume(),user.getMail(),user.getMesaj());
        Response response;
        if (ListaContacteDAO.instance().addContact(user)) {
        	log.info("ContactFunctii-if");
            response = Response.created(uriInfo.getRequestUriBuilder().build()).entity(user).build();
        } else {
        	log.info("ContactFunctii-else");
            response = Response.seeOther(uriInfo.getRequestUriBuilder().build()).build();
        }
        log.info("[ContactFunctii2]");
        return response;
    }*/
}
