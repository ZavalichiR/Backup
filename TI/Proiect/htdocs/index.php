<!DOCTYPE html>
<head>
  <title>Lumea Filmelor</title>
  <meta charset=utf-8" />
  <link href="css/style.css" rel="stylesheet" type="text/css" />
  <script src="js/tools.js" type="text/javascript"></script>
   <link href="css/slideshow.css" rel="stylesheet" type="text/css" />
   <link rel="shortcut icon" type="image/x-icon" href="images/favicon.png" />
</head>
<body onload="loadDoc('acasa.php')" id="page1">
<div >
  <div >
    <div id="main">
      <div id="header">
        <div class="row-1">
          <div ><a>
            <img class="Cposition" src="images/logotitlu.png" alt="logo"/>
            <img id = "logo1" src="images/logo-titlu.png" alt="Logo"/>
            <img id = "logo2" src="images/logo2-titlu.png" alt="Logo"/> 
            <img id = "logo3" src="images/pinguin.png" alt="Logo"/>  

          </a></div>
        </div>
		<!-- menu bar -->
        <div class="row-2" id="myDIV">
          <ul>
            <li><a href="#" onclick="loadDoc('acasa.php')" class="btn active">Acasă</a></li>
            <li><a href="#" onclick="loadDoc('filme.php')" class="btn">Filme</a></li>
            <li><a href="#" onclick="loadDoc('despre.php')" class="btn">Despre</a></li>
            <li><a href="#" onclick="loadDoc('contact.php')" class="btn">Contact</a></li>
			      <li class="last"><a href="#" onclick="loadDoc('sitemap.php')" class="btn">Sitemap</a></li>
          </ul>
        </div>
        <script>
          var header = document.getElementById("myDIV");
          var btns = header.getElementsByClassName("btn");
          for (var i = 0; i < btns.length; i++) {
            btns[i].addEventListener("click", function(){
              var current = document.getElementsByClassName("active");
              current[0].className = current[0].className.replace(" active", "");
              this.className += " active";
          });
          }
        </script>
      </div>

      <article id="continut"></article>
	  
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
</div>
</body>
</html>