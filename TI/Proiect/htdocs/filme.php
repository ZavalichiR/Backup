<?php
  session_start();
?>
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
          <p class="detalii" >&emsp;"Trăim o viaţă şi nu ni se întâmplă să avem nici cinci minute de comunicare atât de puternică, atât de adevărată, ca aceea prilejuită de un spectacol de teatru sau de un film" așa că echipa <b>Lumea Filmelor</b> face tot posibilul să aducă cele mai bune filme de pe piață.</p>
          <p class="detalii" >&emsp;În continuare vă com prezenta o listă cu cele mai bune filme. <b>Vizionare plăcută!</b></p>
        </div>
      </div>
    <div class="box2">  

        <div class="movie-title">
          <?php echo $movie_name ?></h3>
        </div>
            </br></br>
            <h3>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Lista cu <span>Filme</span></h3>
            
            <ul class="list">
              <!-- Slideshow container -->
              <div class="slideshow-container">
             <?php
              
                $xmlDoc=new DOMDocument();
                $xmlDoc->load("xml/filme.xml");
                $element=$xmlDoc->getElementsByTagName('film');                               
                for($i=0; $i<($element->length); $i++) {    
                    $index=$i+1;                
                    $id=$element->item($i)->getElementsByTagName('id');
                    $originalt=$element->item($i)->getElementsByTagName('originalt');
                    $titlu=$element->item($i)->getElementsByTagName('title');
                    $src=$element->item($i)->getElementsByTagName('src');
                    $descriere=$element->item($i)->getElementsByTagName('descriere');

                    if ($titlu->item(0)->nodeType==1) {    
                      $movie_id=$id->item(0)->childNodes->item(0)->nodeValue;    
                      $movie_name=$titlu->item(0)->childNodes->item(0)->nodeValue;
                      $movie_originaln=$originalt->item(0)->childNodes->item(0)->nodeValue;
                      $movie_src=$src->item(0)->childNodes->item(0)->nodeValue;
                      $movie_descriere=$descriere->item(0)->childNodes->item(0)->nodeValue;
                      ?>

                      <div class="mySlides fade">
                        <div class="numbertext"> <?php echo $index?> / <?php echo $element->length ?></div>
                        <li>
                          <img src="<?php echo $movie_src ?>"" alt="" />
                          <h5><span> <?php echo $movie_name ?> </span></h5>
                          <br /> &emsp;<?php echo $movie_descriere ?>
                          <div class="wrapper"><a method='get' href='film.php?idFilm=<?php echo $movie_id?> ' class="link2"><span><span>Detalii</span></span></a></div> 
                        </li>
                      </div>
                      <?php
                    }
                   }
                       ?>

                  <a class="prev" onclick="plusSlides(-1)">&#10094;</a>
                  <a class="next" onclick="plusSlides(1)">&#10095;</a>
                </div>
                <br>

                <!-- The dots/circles -->
                <div style="text-align:center">
                  <?php for($i=1; $i<=($element->length); $i++) {?> 
                  <span class="dot" onclick="currentSlide(<?php echo $i ?>)"></span>  
                  <?php } ?>
                </div>

              </div>

              <div class="suport"> </br ></div>   
            </ul>

  </div>
</div>
