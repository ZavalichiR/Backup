package lumeafilmelor.webserver;

import java.io.IOException;
import java.io.PrintWriter;

import java.net.URI;


import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.ws.rs.client.Client;
import javax.ws.rs.client.ClientBuilder;
import javax.ws.rs.client.WebTarget;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.Response;
import javax.ws.rs.core.UriBuilder;

import org.glassfish.jersey.client.ClientConfig;
//import org.glassfish.jersey.jsonp.JsonProcessingFeature;
//import java.util.Arrays;
//import javax.json.JsonArray;
//import javax.json.JsonObject;

import com.google.gson.Gson;
import lumeafilmelor.core.Filme;

/**
 * Servlet implementation class ShowMoviesList
 */
@WebServlet("/ShowMoviesList")
public class ShowMoviesList extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ShowMoviesList() {
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
		
		PrintWriter pw = response.getWriter();
		
		ClientConfig config = new ClientConfig();
		Client client = ClientBuilder.newClient(config);
		WebTarget service = client.target(getBaseURI());

		Response responser = service.path("api").path("filme").request().accept(MediaType.APPLICATION_JSON).get(Response.class);		
		String ListaFilme = responser.readEntity(String.class);
		System.out.println(ListaFilme);
		
		Gson g = new Gson();
		Filme[] filme = g.fromJson(ListaFilme,Filme[].class);	
		
		request.setAttribute("filme",filme);
        System.out.println("ShowMoviesList:Servlet "+filme.getClass());
  
		request.getRequestDispatcher("filme.jsp").forward(request, response);
		
        
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		//doGet(request, response);
		doGet(request,response);
	
	}

}
