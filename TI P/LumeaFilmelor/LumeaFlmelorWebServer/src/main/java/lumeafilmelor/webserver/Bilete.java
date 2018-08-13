package lumeafilmelor.webserver;

import java.io.IOException;
import java.io.PrintWriter;
import java.lang.reflect.Array;
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

import com.google.gson.Gson;

import lumeafilmelor.core.ClientCinema;
import lumeafilmelor.core.Filme;

/**
 * Servlet implementation class Bilete
 */
@WebServlet("/Bilete")
public class Bilete extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Bilete() {
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
		response.setContentType("text/plain");
		response.setCharacterEncoding("UTF-8");
				
		//Accesare Servicii Web
		ClientConfig config = new ClientConfig();
		Client client = ClientBuilder.newClient(config);
		WebTarget service = client.target(getBaseURI());
		String id=request.getParameter("idFilm");
		Response responser;
		responser = service.path("api").path("clientCinema").path(id).request(MediaType.APPLICATION_JSON).get(Response.class);
		
		String locuri = responser.readEntity(String.class);

		System.out.println("Servlet [Bilete]"+locuri);
		String locuriO=locuri.replace("[", "");
		locuriO=locuriO.replace("]", "");
		locuriO=locuriO.replace("\"","");

		response.getWriter().write(locuriO);
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		// TODO Auto-generated method stub
		response.setContentType("text/plain");
		response.setCharacterEncoding("UTF-8");
		
		String nume = request.getParameter("nume");
		String prenume = request.getParameter("prenume");
		String telefon = request.getParameter("telefon");
		String locuriS = request.getParameter("locuriS");
		String scauneS=request.getParameter("scauneS");
		String id=request.getParameter("id");
		System.out.println("Servlet: Bilete\n");
		System.out.println("IdFilm :"+id);
		System.out.println("Nume :"+nume);
		System.out.println("Prenume :"+prenume);
		System.out.println("Telefon :"+telefon);
		System.out.println("Locuri :"+locuriS);
		System.out.println("Scaune :"+scauneS);

		
		String data = "";
		PrintWriter pw = response.getWriter();
		ClientConfig config = new ClientConfig();
		Client client = ClientBuilder.newClient(config);
		WebTarget service = client.target(getBaseURI());

		
		
		
		
		ClientCinema clientCinema=new ClientCinema(id,nume, prenume, telefon,locuriS,scauneS);
		System.out.println(clientCinema.getNume());
		System.out.println(clientCinema.getPrenume());
		
		Response responser;
		responser = service.path("api").path("clientCinema").request(MediaType.APPLICATION_JSON).post(Entity.entity(clientCinema, MediaType.APPLICATION_JSON), Response.class);
	
		
	}

}
