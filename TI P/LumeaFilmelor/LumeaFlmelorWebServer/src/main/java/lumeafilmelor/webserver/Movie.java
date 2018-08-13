package lumeafilmelor.webserver;

import java.io.IOException;
import java.io.PrintWriter;
import java.net.URI;

import javax.servlet.ServletException;
import javax.servlet.annotation.MultipartConfig;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.client.WebTarget;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.UriBuilder;

import org.glassfish.jersey.client.ClientConfig;
import com.google.gson.Gson;
import lumeafilmelor.core.Filme;
/**
 * Servlet implementation class Movie
 */
@WebServlet("/Movie")
@MultipartConfig
public class Movie extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public Movie() {
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
		String filmId = request.getParameter("idFilm");
				
		//Accesare Servicii Web
		ClientConfig config = new ClientConfig();
		Client client = ClientBuilder.newClient(config);
		WebTarget service = client.target(getBaseURI());
		Response responser = service.path("api").path("filme").path(filmId).request().accept(MediaType.APPLICATION_JSON).get(Response.class);		
		
		String SFilm = responser.readEntity(String.class);
		//System.out.println(SFilm);
		
		Gson g = new Gson();
		Filme film = g.fromJson(SFilm,Filme.class);
		

		
		System.out.println("Servlet pentru :Movie\n"+"Titlu Film:"+film.getTitlu()+"\n"+film.getImagine()+"\nString JSON:"+SFilm );
		/// http://programmergate.com/pass-data-servlet-jsp/ ///
		
		/*HttpSession session=request.getSession();
		session.setAttribute("filme",film.getTitlu());
		request.getRequestDispatcher("film.jsp").forward(request, response);
		*/
		
		// Passiong Object
		
		request.setAttribute("film",film);
        System.out.println("Movie:Servlet "+film.getClass());

        
		request.getRequestDispatcher("film.jsp").forward(request, response);
		
		
		
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
		// TODO Auto-generated method stub
	}

}
