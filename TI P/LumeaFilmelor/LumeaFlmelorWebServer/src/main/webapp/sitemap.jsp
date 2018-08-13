 <%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="lumeafilmelor.core.Filme" %>
<%@ page import="java.util.ArrayList"%>
<%@ page import="java.util.Collections"%>
<%@ page import="java.lang.reflect.Array"%>
 <%@ page contentType="text/html; charset=UTF-8" %>
<div id="content">
  <div class="line-hor"></div>
  
  <%
			Filme[] filme = (Filme[])request.getAttribute("filme");
            if(filme!=null)
             	{
                   	System.out.println("OK");
               	}                       
            else
                {
                  	System.out.println("Atribut NULL");
                   	out.print("Atribut NULL");
                }
        %> 
        
  <div class="box">
        <div class="inner">
          <div class="detalii-sitemap">
          <h3>Site <span>Map</span></h3>
          <p>Aici puteți accesa ușor link-urile din site:</p>
          <ul class="sitemap-list">
              <li><a href="#" onclick="loadDoc('acasa.jsp')">Acasă</a></li>
              <li><a href="#" onclick="loadDoc('despre.jsp')">Despre</a></li>
              <li><a href="#" onclick="loadDoc('ShowMoviesList')">Filme</a>
               	 <ul>
                    <%
		             	int dim=Array.getLength(filme);
		             	for(int i=0;i<dim;++i)
		             	{
		             %>
					<li ><a href='Movie?idFilm=<%=filme[i].getId() %>'> <%=filme[i].getTitlu() %> </a></li>
					<%
		             	}
					%>

               </ul> 
				</li>
              <li><a href="#" onclick="loadDoc('contact.jsp')">Contact</a></li>
              <li><a href="#" onclick="loadDoc('sitemap.jsp')">Site Map</a></li>
          </ul>
        </div>
        </div>
      </div>
</div>