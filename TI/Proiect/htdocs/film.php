<?php
  session_start();
?>
<!DOCTYPE html>
<head>
  <title>Lumea Filmelor</title>
  <meta charset=utf-8" />
  <link href="css/style.css" rel="stylesheet" type="text/css" />
  <script src="js/tools.js" type="text/javascript"></script>
   <link rel="shortcut icon" type="image/x-icon" href="images/favicon.png" />
</head>
<body onload="seteazaLocuriOcupate()"id="page1">
    <div id="main">
      <div id="header">
        <div class="row-1">
          <div ><a>
            <img class="Cposition" src="images/Logo4.png" alt="logo"/>
            <img id = "logo1" src="images/logo-titlu.png" alt="Logo"/>
            <img id = "logo2" src="images/logo2-titlu.png" alt="Logo"/> 
            <img id = "logo3" src="images/pinguin.png" alt="Logo"/>  

          </a></div>
        </div>
    <!-- menu bar -->
        <div class="row-2" id="myDIV">
          <ul>
            <li><a href="index.php" class="btn">Acasă</a></li>
          </ul>
        </div> 
      </div>


      <div id="content">
        <div class="box">
              <div class="inner2">
                <?php
                  $xmlDoc=new DOMDocument();
                  $xmlDoc->load("xml/filme.xml");
                  $element=$xmlDoc->getElementsByTagName('film');
                  $idFilm=$_GET["idFilm"];
                     
                  if ($_SERVER['REQUEST_METHOD'] == "GET" && isset($_GET['idFilm'])){
                          
                    $movie_name="";
                    for($i=0; $i<($element->length); $i++) {
                            
                      $id=$element->item($i)->getElementsByTagName('id');
                      $originalt=$element->item($i)->getElementsByTagName('originalt');
                      $titlu=$element->item($i)->getElementsByTagName('title');
                      $src=$element->item($i)->getElementsByTagName('src');
                      $gen=$element->item($i)->getElementsByTagName('gen');
                      $limba=$element->item($i)->getElementsByTagName('limba');
                      $premiera=$element->item($i)->getElementsByTagName('premiera');
                      $regizor=$element->item($i)->getElementsByTagName('regizor');
                      $actori=$element->item($i)->getElementsByTagName('actori');
                      $descriere=$element->item($i)->getElementsByTagName('descriere');
                      $durata=$element->item($i)->getElementsByTagName('durata');
                      $anul=$element->item($i)->getElementsByTagName('anul');
                      $trailer=$element->item($i)->getElementsByTagName('trailer');


                      if ($titlu->item(0)->nodeType==1) {
                        if ($id->item(0)->childNodes->item(0)->nodeValue==$idFilm) {                 
                                  
                          $movie_name=$titlu->item(0)->childNodes->item(0)->nodeValue;
                          $movie_originaln=$originalt->item(0)->childNodes->item(0)->nodeValue;
                          $movie_src=$src->item(0)->childNodes->item(0)->nodeValue;
                          $movie_gen=$gen->item(0)->childNodes->item(0)->nodeValue;
                          $movie_limba=$limba->item(0)->childNodes->item(0)->nodeValue;
                          $movie_premiera=$premiera->item(0)->childNodes->item(0)->nodeValue;
                          $movie_regizor=$regizor->item(0)->childNodes->item(0)->nodeValue;
                          $movie_actori=$actori->item(0)->childNodes->item(0)->nodeValue;
                          $movie_descriere=$descriere->item(0)->childNodes->item(0)->nodeValue;
                          $movie_durata=$durata->item(0)->childNodes->item(0)->nodeValue;
                          $movie_anul=$anul->item(0)->childNodes->item(0)->nodeValue;
                          $movie_trailer=$trailer->item(0)->childNodes->item(0)->nodeValue;
                          ?>
                          
                          <div class="img-box1 alt"> <img class="cursor" onclick="document.getElementById('lightbox').style.display='inline';" src="<?php echo $movie_src ?>" alt="Thor Ragnarok"">
                          <div class="movie-title">
                            <?php echo $movie_name ?></h3>
                            <hr></hr>
                          </div>
  
                            <div class="film-box">
                                    <ol>
                                      <button class="tiket" onclick="document.getElementById('lightbox2').style.display='inline';"></button>
                                      <li><h5>Titlul original:<span><?php echo $movie_originaln ?></span></h5></li>
                                      <li><h5>Gen:<span><?php echo $movie_gen ?></span></h5></li>
                                      <li><h5>Durata (in min.):<span><?php echo $movie_durata ?></span></h5></li>
                                      <li><h5>Limba:<span><?php echo $movie_limba ?></span></h5></li>
                                      <li><h5>Premiera în  data de:<span><?php echo $movie_premiera ?></span></h5></li>
                                      <li><h5>Regizor:<span><?php echo $movie_regizor ?></span></h5></li>
                                      <li><h5>Actori:<span><?php echo $movie_actori ?></span></h5></li>
                                      <li><h5>Anul:<span><?php echo $movie_anul ?></span></h5></li>
                                   </ol>
                                   <div class="descriere" ><p>&emsp;<?php echo $movie_descriere ?></p></div>
                                     
                            </div>
                          </div>
                          <?php
                              }
                            }
                          }
                        }
                    ?> 
                  
                    <!-- TRailer-->

                    <div id="lightbox" class="lightbox" style="display:none">
                       <table class="lightbox_table">
                          <td align="center">
                            <div  style="width:600px; background-color:white; border:5px solid black;">
                               <p class="exit" onclick="document.getElementById('lightbox').style.display='none';"style="cursor:pointer;"> </p>
                               <div style="position:relative;height:0;padding-bottom:56.21%"><iframe src="<?php echo $movie_trailer ?>" style="position:absolute;width:100%;height:100%;left:0" width="641" height="360" frameborder="0" gesture="media" allow="encrypted-media" allowfullscreen></iframe></div>
                            </div>
                         </td>
                       </table>
                    </div>

                    <!-- Trailer-->

                    <!-- Deschide fereastra cu locuri-->

                    <div id="lightbox2" class="lightbox" style="display:none" >
                       <table class="lightbox_table">
                          <td align="center">
                            <div  style="width:600px; background-color: #c8c5c5; border:5px solid black;">
                               <p class="exit" onclick="document.getElementById('lightbox2').style.display='none';" style="cursor:pointer;"> </p>
                               <div class="sala">
                                  <img class="ecran" src="images/ecran.png" alt="ecran">
                                  <table class="cinema-table">

                                    <tr>
                                      <span id="rand1">1</span>
                                      <?php
                                        for($i=1;$i<=12;++$i)
                                        {
                                          if($i==6)
                                          {
                                            ?>
                                            <td></td>
                                            <td></td>
                                            <td></td>
                                            <?php
                                          }
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo $i?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand-end">1</td>
                                    </tr>

                                    <tr>
                                      <td id="rand-start">2</td>
                                      <?php
                                        for($i=13;$i<=24;++$i)
                                        {
                                          if($i==18)
                                          {
                                            ?>
                                            <td></td>
                                            <td></td>
                                            <?php
                                          }
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo ($i-12);?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand-end">2</td>
                                    </tr>

                                    <tr>
                                      <td id="rand-start">3</td>
                                      <?php
                                        for($i=25;$i<=36;++$i)
                                        {
                                          if($i==30)
                                          {
                                            ?>
                                            <td></td>
                                            <td></td>
                                            <?php
                                          }
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo ($i-24);?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand-end">3</td>
                                    </tr>

                                    <tr>
                                      <td id="rand-start">4</td>
                                      <?php
                                        for($i=37;$i<=48;++$i)
                                        {
                                          if($i==42)
                                          {
                                            ?>
                                            <td></td>
                                            <td></td>
                                            <?php
                                          }
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo ($i-36);?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand-end">4</td>
                                    </tr>

                                   <tr>
                                      <td id="rand-start">5</td>
                                      <?php
                                        for($i=49;$i<=60;++$i)
                                        {
                                          if($i==54)
                                          {
                                            ?>
                                            <td></td>
                                            <td></td>
                                            <?php
                                          }
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo ($i-48);?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand-end">5</td>
                                    </tr>

                                    <tr>
                                      <td id="rand-start">6</td>
                                      <?php
                                        for($i=61;$i<=72;++$i)
                                        {
                                          if($i==66)
                                          {
                                            ?>
                                            <td></td>
                                            <td></td>
                                            <?php
                                          }
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo ($i-60);?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand-end">6</td>
                                    </tr>

                                    <tr>
                                      <td id="rand-start">7</td>
                                      <?php
                                        for($i=73;$i<=84;++$i)
                                        {
                                          if($i==78)
                                          {
                                            ?>
                                            <td></td>
                                            <td></td>
                                            <?php
                                          }
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo ($i-72);?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand-end">7</td>
                                    </tr>

                                    <tr>
                                      <td id="rand2-start">8</td>
                                      <?php
                                        for($i=85;$i<=97;++$i)
                                        {
                                          if($i==90)
                                          {
                                            ?>
                                            <td></td>
                                            <td></td>
                                            <?php
                                          }
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo ($i-84);?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand2-end">8</td>
                                    </tr>

                                    <tr>
                                      <td id="rand2-start">9</td>
                                      <?php
                                        for($i=98;$i<=110;++$i)
                                        {
                                          if($i==103)
                                          {
                                            ?>
                                            <td></td>
                                            <td></td>
                                            <?php
                                          }
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo ($i-97);?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand2-end">9</td>
                                    </tr>

                                    <tr>
                                      <td id="rand2-start">10</td>
                                      <?php
                                        for($i=111;$i<=125;++$i)
                                        {
                                          ?>
                                            <td><div class="casuta"><div onclick="selectat(this)" id="<?php echo $i;?>" class="loc-cinema"><span><?php echo ($i-110);?></span></div></div></td>
                                          <?php
                                        }
                                      ?>
                                      <td id="rand2-end">10<td>
                                    </tr>
                                    
                                  </table>    
                               </div> 
                                  <!-- Buton pentru formular -->
                                  <button class="continua" type="submit" onclick="document.getElementById('lightbox3').style.display='inline';">Continuă</button>

                                  <!-- Deschide formularul-->
                                  <div id="lightbox3" class="lightbox" style="display:none" >
                                   <table class="lightbox_table">
                                      <td align="center">
                                        <div  style="width:600px; background:url(images/background-formular-bilete2.jpg); border:5px solid black;">
                                           <p class="exit" onclick="document.getElementById('lightbox3').style.display='none';" style="cursor:pointer;">  </p>
                                            
                                            <div class="content2">  
                                              <h4> Vă rugăm să completați câmpurile:</h4>
                                               <div class="eroareVContact" id="eroareV" ></div>
                                              <form name="confirmare" action='api/sendInfo.php' onsubmit="return validare2()"method='post'>
                                                <fieldset >
                                                  <div class="nume">
                                                    <label style="color: #f1f1f1;" >Nume:</label>
                                                    <input  type="text" name="nume" placeholder="Ex: Nume"/>
                                                  </div>
                                                  <div class="prenume">
                                                    <label style="color: #f1f1f1;">Prenume:</label>
                                                    <input type="text" name="prenume" placeholder="Ex: Prenume"/>
                                                  </div>
                                                  <div class="telefon">
                                                    <label style="color: #f1f1f1;">Telefon:</label>
                                                    <input  type="text" name="telefon" placeholder="Ex: XXXXXXXXXX"/>
                                                  </div>
                                                  <div >
                                                    <input  type="hidden" id="bilete" name="bilete" value="">
                                                  </div>
                                                  <div class="bilete">
                                                    <label style="color: #f1f1f1;" >Bilete:</label>
                                                    <a name="locuri" id="locuriSelectatef"></a>
                                                  </div>
                                                </fieldset>
                                              <button class="finalizeaza" type="submit" onclick="selecteaza()">Finalizează</button>
                                            </form>
                                            </div>

                                          </div>
                                        </td>
                                      </table>>
                                    </div>
                                     <!-- Inchide formular-->
                                  <div class="mesaj" ><span>Locuri selectate:<a id="locuriSelectate"></a> </a> </span></div>                      
                            </div>
                         </td>
                       </table>
                    </div>

                    <!-- Inchide fereastra cu locuri-->
   
              </div>
            </div>
          </div>
          <div id="footer">
      <div class="left">
         <div class="right">
           <div class="footerlink">
             <p class="lf">Copyright &copy; 2017 <a href="#">Lumea Filmelor</a> - All Rights Reserved</p></br> 
              <p class="lf"> <a> Administrator </a> <a href="https://www.facebook.com/Zava96"> Răzvan Z. </a ></p> 
             <p><img id = "banner" src="images/banner.png" alt="Banner"/></p>
             <p class="rf">By <a href="https://www.facebook.com/Zava96" target="_blank">ZAVA</a></p>
             <div style="clear:both;"></div>
           </div>
         </div>
       </div>
      </div>
        </div>
      </div>
</body>
</html>