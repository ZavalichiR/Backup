package lumeafilmelor.webservices;

import java.sql.SQLException;
import java.util.List;
import java.util.Map.Entry;

import javax.ws.rs.Consumes;
import javax.ws.rs.DELETE;

import javax.ws.rs.GET;
import javax.ws.rs.PATCH;
import javax.ws.rs.POST;
import javax.ws.rs.PUT;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.Context;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.MultivaluedMap;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.Response.Status;
import javax.ws.rs.core.UriBuilderException;
import javax.ws.rs.core.UriInfo;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

import lumeafilmelor.core.User;
import lumeafilmelor.db.ListUserDAO;

// e.g., @ApplicationPath("api") + @Path("/users") =>
// http://localhost:8080/LumeaFilmelorWebServices/api/books
@Path("/users")
public class BooksResource {

    private static Logger log = LoggerFactory.getLogger(BooksResource.class);

    // based on: http://www.vogella.com/tutorials/REST/article.html#jerseyprojectsetup

    /**
     * Requests transfer of a current selected representation for the target resource (i.e., the
     * book collection)
     * @throws SQLException 
     */
    @GET
    @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public List<User> getUsers() throws SQLException {
        log.info("getUsers");
        return ListUserDAO.instance().getUsers();
    }

    /**
     * Requests transfer of a current selected representation for the target resource (i.e., a book
     * by ISBN).
     * @throws SQLException 
     */
    @GET
    @Path("{username}")
    @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public User getUser(@PathParam("username") String username) throws SQLException {
        return ListUserDAO.instance().getUser(username);
    }

    /**
     * Creates a new resource that has yet to be identified by the origin server (i.e., adds a book
     * or replaces and existing one).
     * @throws SQLException 
     * @throws UriBuilderException 
     * @throws IllegalArgumentException 
     */
    @POST
    @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public Response postUsers(@Context UriInfo uriInfo, User user) throws IllegalArgumentException, UriBuilderException, SQLException {
        log.info("postUsers: {}", user);
        Response response;
        if (ListUserDAO.instance().addUser(user)) {
            response = Response.created(uriInfo.getRequestUriBuilder().build()).entity(user).build();
        } else {
            response = Response.seeOther(uriInfo.getRequestUriBuilder().build()).build();
        }
        log.info("[UserResource] postUsers: response status: {} {}", response.getStatus(), response.getStatusInfo());
        return response;
    }

    /**
     * Appends data to a resource's existing representation(s).
     * <br>
     * Treat the addressed member as a collection in its own right and create a new entry within it.
     * <br>
     * <b>Not generally used! Use PATCH instead</b>
     */
    @POST
    @Path("{username}")
    @Produces({ MediaType.APPLICATION_JSON, MediaType.APPLICATION_XML })
    public Response postUser(@PathParam("username") String username) {
        return Response.status(Status.METHOD_NOT_ALLOWED).allow("GET", "PUT", "DELETE", "PATCH").build();
    }

    /**
     * Requests that the state of the target resource be created or replaced with the state defined
     * by the representation enclosed in the request message payload.
     * Replace the entire collection
     * <b>In this context having this method makes no sense, because usually one does not replace
     * the entire book collection</b>
     * 
     * @param book
     * @return
     */
    @PUT
    public Response putUsers(List<User> users) {
        //In this context having this method makes no sense, because usually one does not replace the entire book collection
        return Response.status(Status.METHOD_NOT_ALLOWED).allow("GET", "POST").build();
    }

    /**
     * Requests that the state of the target resource be created or replaced with the state defined
     * by the representation enclosed in the request message payload.
     * <br>
     * Partial content updates are possible by targeting a separately identified resource with state
     * that overlaps a portion of the larger resource, or by using the PATCH method
     * 
     * @param book
     *            book to be replaced
     * @return
     * @throws SQLException 
     */
    @PUT
    @Path("{username}")
    public Response putUser(@PathParam("username") String username, User newuser) throws SQLException {
        //Only the replace functionality is implemented
        Response response;
        if (ListUserDAO.instance().updateUser(username, newuser)) {
            response = Response.noContent().build();
        } else {
            response = Response.status(Status.NOT_FOUND).build();
        }
        return response;
    }

    /**
     * Requests that the origin server remove the association between the target resource and its
     * current functionality.
     * <br>
     * The entire collection is deleted.
     * <b>In this context having this method makes no sense, because usually one does delete the
     * entire book collection</b>
     * 
     * @return
     */
    @DELETE
    public Response deleteUsers() {
        return Response.status(Status.METHOD_NOT_ALLOWED).allow("GET", "POST").build();
    }

    /**
     * Requests that the origin server remove the association between the target resource and its
     * current functionality.
     * <br>
     * The book identified by the URI is removed.
     * 
     * @param isbn
     * @param book
     * @return
     * @throws SQLException 
     */
    @DELETE
    @Path("{username}")
    public Response deleteUser(@PathParam("username") String username) throws SQLException {
        //Only the replace functionality is implemented
        Response response;
        if (ListUserDAO.instance().deleteUser(username)) {
            response = Response.noContent().build();
        } else {
            response = Response.status(Status.NOT_FOUND).build();
        }
        return response;
    }

    /**
     * Requests that a set of changes described in the request entity be applied to the resource
     * identified by the Request URI.
     * <br>
     * Maybe use it for applying multiple patches on different resources (bulk update).
     * <br>
     * <b>Not generally used!</b>
     * 
     * @return
     */
    @PATCH
    public Response patchUsers() {
        return Response.status(Status.METHOD_NOT_ALLOWED).allow("GET", "POST").build();
    }

    /**
     * Requests that a set of changes described in the request entity be applied to the resource
     * identified by the Request URI.
     * <br>
     * The enclosed entity contains a set of instructions describing how a resource currently
     * residing on the origin server should be modified to produce a new version.
     * <br>
     * Change the title of the book with the specified isbn
     * <br>
     * id, isbn and addedDate cannot be modified
     * 
     * @param isbn
     * @return
     * @throws SQLException 
     */
    @PATCH
    @Path("{username}")
    @Consumes("application/x-www-form-urlencoded")
    public Response patchUsername(@PathParam("username") String username, MultivaluedMap<String, String> map) throws SQLException {
        log.info("patchUsername: {}", username);
        //Only the replace functionality is implemented
        Response response;
        User user = ListUserDAO.instance().getUser(username);
        if (user == null) {
            return Response.status(Status.NOT_FOUND).build();
        }
        for (Entry<String, List<String>> entry : map.entrySet()) {
            String value = entry.getValue().get(0);
            switch (entry.getKey()) {
                case "username":
                    user.setUsername(value);
                    break;
                case "password":
                    user.setPassword(value);
                    break;
                default:
                    return Response.status(Status.BAD_REQUEST).build();
            }
        }
        if (ListUserDAO.instance().updateUser(username, user)) {
            response = Response.noContent().build();
        } else {
            response = Response.status(Status.NOT_FOUND).build();
        }
        return response;
    }
}