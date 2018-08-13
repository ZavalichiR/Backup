package lumeafilmelor.webserver;


import java.io.IOException;
import java.io.PrintWriter;
import java.net.URI;
import java.util.Enumeration;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.client.Entity;
import javax.ws.rs.client.WebTarget;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.UriBuilder;

import org.glassfish.jersey.client.ClientConfig;
import org.glassfish.jersey.client.HttpUrlConnectorProvider;

import lumeafilmelor.core.User;


/**
 * Servlet implementation class TestServlet
 */
@WebServlet("/TestServlet")
public class TestServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public TestServlet() {
        super();
        // TODO Auto-generated constructor stub
    }

    private static URI getBaseURI() {
        //TODO change the port to whatever is the server running on
        return UriBuilder.fromUri("http://localhost:8080/LumeaFilmelorWebServices/").build();
    }


    public static void main(String[] args) {
        
    }
    /**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		
			
		response.setContentType("text/html");
		response.setCharacterEncoding("utf-8");
		PrintWriter pw = response.getWriter();
		pw.append("<h1>(Sunt in Test Servlet-WebServer)Exemplu de servlet</h1>");

        pw.append("Context path: ").append(request.getContextPath()).append("<br/>");
        pw.append("Request URI: ").append(request.getRequestURI()).append("<br/>");
        pw.append("Parameter map: ").append(request.getParameterMap().toString()).append("<br/>");
        request.setAttribute("Numar Random", Math.random());
        pw.append("Attributes: ").append("<br/>");
        Enumeration<String> attributeNames =  request.getAttributeNames();
        while (attributeNames.hasMoreElements()) {
            String attr = attributeNames.nextElement();
            pw.append("- ").append(attr).append(": ").append(request.getAttribute(attr).toString()).append("<br/>");
        }
        
        ClientConfig config = new ClientConfig();
        //config.register(Custom);
        Client client = ClientBuilder.newClient(config);
        // Next line of code is a workaround for using PATCH
        // A value of true declares that the client will try to set unsupported HTTP method to java.net.HttpURLConnection via reflection.
        // PATCH workaround:
        //    - alternative to client.property(HttpUrlConnectorProvider.SET_METHOD_WORKAROUND, true);
        //    - also allow PATCH to have a response body
        //    - see user1648865 response from https://stackoverflow.com/questions/17897171/how-to-have-a-patch-annotation-for-jax-rs 
        client.property(HttpUrlConnectorProvider.SET_METHOD_WORKAROUND, true);
        //
        WebTarget service = client.target(getBaseURI());
        Response responser;
        User user;

        responser = service.path("api").path("users").request().accept(MediaType.APPLICATION_JSON).get(Response.class);
        pw.append("User collection").append(responser.toString());

        // create a book and added to the collection
        user = new User("admin", "admin");
        responser = service.path("api").path("users").request(MediaType.APPLICATION_XML)
                .post(Entity.entity(user, MediaType.APPLICATION_XML), Response.class);
        // Return code should be 201 == created resource
        pw.append("User added").append( responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

        responser = service.path("api").path("users").request().accept(MediaType.APPLICATION_JSON).get(Response.class);
        pw.append("User collection").append( responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

       user = new User("user","user");
        responser = service.path("api").path("users").request(MediaType.APPLICATION_JSON)
                .post(Entity.entity(user, MediaType.APPLICATION_JSON), Response.class);
        // Return code should be 201 == created resource
        pw.append("User added").append(  responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

        user = new User("Răzvan", "Zavalichi");
        responser = service.path("api").path("users").request(MediaType.APPLICATION_JSON)
                .post(Entity.entity(user, MediaType.APPLICATION_JSON), Response.class);
        // Return code should be 201 == created resource
        pw.append("User added").append(  responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

        responser = service.path("api").path("users").path("admin").request().accept(MediaType.APPLICATION_JSON)
                .get(Response.class);
        pw.append("Book collection").append(  responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

        responser = service.path("api").path("users").path("admin").request(MediaType.APPLICATION_JSON)
                .post(Entity.entity(user, MediaType.APPLICATION_JSON), Response.class);
        // Return code should be 201 == created resource
        pw.append("POST request on colection item is not allowed").append( responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

        responser = service.path("api").path("users").request(MediaType.APPLICATION_JSON)
                .put(Entity.entity("", MediaType.APPLICATION_JSON), Response.class);
        pw.append("Replace entire book collection is not allowed").append( responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

        // PUT
        user = new User("manele","manele");
        responser = service.path("api").path("users").path("user").request(MediaType.APPLICATION_JSON)
                .put(Entity.entity(user, MediaType.APPLICATION_JSON), Response.class);
        pw.append("Replace book with username user").append(  responser.toString()+"<br/>").append(responser.readEntity(String.class));;

        responser = service.path("api").path("users").request().accept(MediaType.APPLICATION_JSON).get(Response.class);
        pw.append("User collection").append(  responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

        // DELETE
        responser = service.path("api").path("users").request().accept(MediaType.APPLICATION_JSON).delete(Response.class);
        pw.append("DELETE request is not allowed").append(  responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

        responser = service.path("api").path("users").path("").request().accept(MediaType.APPLICATION_JSON)
                .delete(Response.class);
        pw.append("Delete user with username admin").append( responser.toString()+"<br/>").append(responser.readEntity(String.class)).append("<br/>");

        responser = service.path("api").path("users").request().accept(MediaType.APPLICATION_JSON).get(Response.class);
        pw.append("User collection").append( responser.toString()+"<br/>").append(responser.readEntity(String.class));;

        //PATCH
        //header("X-HTTP-Method-Override", "PATCH") <-- does not work
        responser = service.path("api").path("users").path("cristian").request().accept(MediaType.APPLICATION_JSON).method(
                "PATCH", Entity.entity("hristofor", MediaType.APPLICATION_FORM_URLENCODED),
                Response.class);
        pw.append("Patch user with username cristian; changed username").append(responser.toString()+"<br/>").append(responser.readEntity(String.class));

        responser = service.path("api").path("users").request().accept(MediaType.APPLICATION_JSON).get(Response.class);
        pw.append("Book collection").append( responser.toString()+"<br/>").append(responser.readEntity(String.class));
        
        
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}

}
