 
<div id="content">
  <div class="line-hor"></div>
  <div class="box">
        <div class="inner">
          <div class="detalii-sitemap">
          <h3>Site <span>Map</span></h3>
          <p>Aici puteți accesa ușor link-urile din site:</p>
          <ul class="sitemap-list">
              <li><a href="#" onclick="loadDoc('acasa.php')">Acasă</a></li>
              <li><a href="#" onclick="loadDoc('despre.php')">Despre</a></li>
              <li><a href="#" onclick="loadDoc('filme.php')">Filme</a>
                <ul>
                  <?php
                  $xmlDoc=new DOMDocument();
                  $xmlDoc->load("xml/filme.xml");
                  $element=$xmlDoc->getElementsByTagName('film');                               
                  for($i=0; $i<($element->length); $i++) {                    
                      $id=$element->item($i)->getElementsByTagName('id');
                      $titlu=$element->item($i)->getElementsByTagName('title');

                      if ($titlu->item(0)->nodeType==1) {    
                        $movie_id=$id->item(0)->childNodes->item(0)->nodeValue;    
                        $movie_name=$titlu->item(0)->childNodes->item(0)->nodeValue;
                     ?>

                          
                            <li><a method='get' href='film.php?idFilm=<?php echo $movie_id?>' > <?php echo $movie_name ?> </a></li>
                          
                      <?php
                      }
                    }
                 ?>
               </ul> 

              <li><a href="#" onclick="loadDoc('contact.php')">Contact</a></li>
              <li><a href="#" onclick="loadDoc('sitemap.php')">Site Map</a></li>
          </ul>
        </div>
        </div>
      </div>
</div>