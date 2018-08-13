<?php
  session_start();
?>
<?php

  $xmlDoc=new DOMDocument();
  $xmlDoc->load("../xml/filme.xml");
  $element=$xmlDoc->getElementsByTagName('film');
  $q=$_GET["q"];
 
  if (strlen($q)>0) {
    $hint="";
    for($i=0; $i<($element->length); $i++) {
      $titlu=$element->item($i)->getElementsByTagName('title');
      $idFilm=$element->item($i)->getElementsByTagName('id');
      
      if ($titlu->item(0)->nodeType==1) {
       
        if (stristr($titlu->item(0)->childNodes->item(0)->nodeValue,$q)) {
       
          if ($hint=="") {
       
            $id=$idFilm->item(0)->childNodes->item(0)->nodeValue;
            $hint= "<a class='selectFilm'  method='get' href='film.php?idFilm=".$id."' > " .$titlu->item(0)->childNodes->item(0)->nodeValue. " </a>";
          } 
          else {
            $id=$idFilm->item(0)->childNodes->item(0)->nodeValue;
            $hint=$hint. "</br><a class='selectFilm'  method='get' href='film.php?idFilm=".$id."' > " .$titlu->item(0)->childNodes->item(0)->nodeValue. " </a>";
          }
        }
      }
    }
  }

  if ($hint=="") {
    $response='<span style="color: red;">Nu a fost găsit</span>';
  } 
  else {
    $response=$hint;
  }
  echo $response;
?>
