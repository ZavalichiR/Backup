<%@ page contentType="text/html; charset=UTF-8" %>
<%@ page import="lumeafilmelor.core.Filme" %>
<%@ page import="java.util.ArrayList"%>
<%@ page import="java.util.Collections"%>
<%@ page import="java.lang.reflect.Array"%>

<meta name="viewport" content="width=device-width, initial-scale=1">
 <link href="css/slideshow.css" rel="stylesheet" type="text/css" />
<style>
.mySlides {display:none}
</style>

<div id="content">
  <div class="line-hor"></div>
  <div class="box">
        <div class="inner">
          <h3>Filmele <span>Noastre</span></h3>
          <p class="detalii" >&emsp;"Trăim o viață și nu ni se întâmplă să avem nici cinci minute de comunicare atât de puternică, atât de adevărată, ca aceea prilejuită de un spectacol de teatru sau de un film" așa că echipa <b>Lumea Filmelor</b> face tot posibilul să aducă cele mai bune filme de pe piață.</p>
          <p class="detalii" >&emsp;În continuare vă vom prezenta o listă cu cele mai bune filme. <b>Vizionare plăcută!</b></p>
        </div>
      </div>
      
    <div class="box2">  
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
        
        <div class="movie-title">
        </div>
            </br></br>
            <h3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Lista cu <span>Filme</span></h3>
            
            <ul class="list">
              <!-- Slideshow container -->
             </br>
              </br>
              <div class="slideshow-container">
             <%
             	int dim=Array.getLength(filme);
             	for(int i=0;i<dim;++i)
             	{
             %>
             		<div class="mySlides fade">
                    <div class="numbertext"> <%=i+1 %> / <%=dim %></div>
                    <li>
                      <img src="<%=filme[i].getImagine() %>" alt="<%=filme[i].getTitlu() %>" />
                      <h5><span> <%=filme[i].getTitlu() %> </span></h5>
                      <br /> &emsp;<%=filme[i].getDescriere() %>
                      <div class="wrapper"><a method='get' href='Movie?idFilm=<%=filme[i].getId() %>' class="link2"><span><span>Detalii</span></span></a></div> 
                    </li>
                  </div>
               <%
             	}
               %>              
                  <a class="prev" onclick="plusSlides(-1)">&#10094;</a>
                  <a class="next" onclick="plusSlides(1)">&#10095;</a>
                </div>
                <br>

                <!-- The dots/circles -->
                <div style="text-align:center">
                  <%for(int i=1; i<=dim; i++) { %> 
                  <span class="dot" onclick="currentSlide(<%=i%>)"></span>  
                  <%} %>
                </div>

              </div>

              <div class="suport"> </br ></div>   
            </ul>

  </div>
</div>
