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

import org.apache.tomcat.util.buf.StringUtils;
import org.glassfish.jersey.client.ClientConfig;
import org.glassfish.jersey.client.HttpUrlConnectorProvider;

import com.google.gson.Gson;

import lumeafilmelor.core.Filme;
import lumeafilmelor.core.User;


@WebServlet("/ReturnMovieName")
public class ReturnMovieName extends HttpServlet {
	private static final long serialVersionUID = 1L;
       
    /**
     * @see HttpServlet#HttpServlet()
     */
    public ReturnMovieName() {
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
		
		
		response.setContentType("text/plain");
		response.setCharacterEncoding("UTF-8");
		
		String partialName = request.getParameter("str");
		String data = "";
		PrintWriter pw = response.getWriter();
		ClientConfig config = new ClientConfig();
		Client client = ClientBuilder.newClient(config);
		WebTarget service = client.target(getBaseURI());

		Response responser = service.path("api").path("filme").request().accept(MediaType.APPLICATION_JSON).get(Response.class);		
		String ListaFilme = responser.readEntity(String.class);
		System.out.println("Servlet: ReturnMovieName\n");
		System.out.println(ListaFilme);
		Gson g = new Gson();
		Filme[] filme = g.fromJson(ListaFilme,Filme[].class);
		if(partialName!="") {
			for (Filme tab : filme) {
				int flag = tab.getTitlu().toLowerCase().indexOf(partialName.toLowerCase());
				int flag2=tab.getOriginalTitlu().toLowerCase().indexOf(partialName.toLowerCase());
		          if(flag==0 || flag==0 || contains(tab.getTitlu(),partialName) ||contains(tab.getOriginalTitlu(),partialName))
		          {
		        	  System.out.println("intrat");
		        	  data="<a class='selectFilm'  method='get' href='Movie?idFilm="+tab.getId()+"' > "+tab.getTitlu()+" </a><br/>";
		        	  response.getWriter().write(data);
		          }
		          else
		          {
		        	  System.out.println("Nu intrat");
		          }
		          
		      }
	       
		}
		
        
	}

	/**
	 * @see HttpServlet#doPost(HttpServletRequest request, HttpServletResponse response)
	 */
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		doGet(request, response);
	}
	
	public boolean contains( String container, String str ) {
		container = container == null ? "" : container;
		str = str == null ? "" : str;

		  // Works, but is not the best.
		  //return haystack.toLowerCase().indexOf( needle.toLowerCase() ) > -1

		  return container.toLowerCase().contains( str.toLowerCase() );
		}
}
