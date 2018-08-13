package lumeafilmelor.webserver;

import java.io.IOException;
import java.net.URI;

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

import lumeafilmelor.core.Contact;


/**
 * Servlet implementation class Contact
 */
@WebServlet("/Contacts")
public class Contacts extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Contacts() {
        super();
        // TODO Auto-generated constructor stub
    }

    private static URI getBaseURI() {
        //TODO change the port to whatever is the server running on
        return UriBuilder.fromUri("http://localhost:8080/LumeaFilmelorWebServices/").build();
    }
    
	/**
	 * @see HttpServlet#doGet(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.getWriter().append("Served at: ").append(request.getContextPath());
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		String nume = request.getParameter("nume");
		String mail = request.getParameter("mail");
		String mesaj = request.getParameter("mesaj");
		
		//Accesare Servicii Web
		ClientConfig config = new ClientConfig();
		Client client = ClientBuilder.newClient(config);
		WebTarget service = client.target(getBaseURI());	
		
		//System.out.println(SFilm);
		
		System.out.println("Servlet pentru :Contact");
		System.out.println("Date primite:"+nume+", "+mail+", "+mesaj);
		Contact user=new Contact(nume,mail,mesaj);
		Response responser;
		responser = service.path("api").path("contacte").request(MediaType.APPLICATION_JSON).post(Entity.entity(user, MediaType.APPLICATION_JSON), Response.class);
	}
	

}
