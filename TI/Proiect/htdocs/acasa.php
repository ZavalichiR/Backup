<?php 
	session_start();
?>
	<div id="slogan">
        <div class="image png"></div>
		<div class="inside">
			<h2>Cu noi <span>vezi lumea altfel</span></h2>
			<p>Vizualizează-te ca pe ecranul de cinema. Priveşte-te reuşind deja să faci şi să obţii ce doreşti..</p>
		</div>
    </div>
    <div class="box">
        <div class="inner">
        	<div>
  				<div >
					 <form class="search">
						<input  type="text" placeholder="Search here..." onkeyup="showResult(this.value)">
						<div class="gasit" id="gasit"></div>
					</form>
				</div>
	        </div>
					
			<div class="sec2">
				<h3>Bine ați venit în <b>Lumea</b> <span>Filmelor</span></h3>
				<div class="img-box1"> <a method='get' href='film.php?idFilm=1'><img src="images/Filme/Dunkirk-page1.jpg" alt="LigaDreptatii" ></a>
					<span class="titlu">Filmul Anului</span>
					<div class="first"><p class="detalii">&emsp;Povestea filmului Dunkirk surprinde trupele britanice şi ale aliaţilor înconjurate de inamici pe plaja franceză şi forţate să facă faţă unui asalt aproape imposibil de rezistat.
					Filmul reuneşte o distribuţie impresionantă din care fac parte actorii Tom Hardy („Mad Max: Drumul furiei”), Mark Rylance, Kenneth Branagh, Cillian Murphy şi debutantul Fionn Whitehead. Filmul este produs de Christopher Nolan şi Emma Thomas, iar Jake Myers este producător executiv.</p></div>
				</div>    	
			</div>    
  		</div>
    </div>
    <div class="box2"> 
    	</br></br>
		<span id="filme-noi"> <h3>Filme <span>Noi</span></h3></span>
		<ul class="movies">
		    <li>
				<h4>Star Wars</h4>
				<a class="selectImg" method='get' href='film.php?idFilm=2'><img src="images/Filme/StarWars.jpg"  alt="Star Wars" /></a>
				<p>După ce a pășit in universul Star Wars (Star Wars: The Force Awakens (2015), Rey își continuă drumul epic, alături de Finn, Poe și Luke Skywalker, în următorul capitol din saga..</p>
			</li>
			<li>
				<h4>Jocuri Secrete</h4>
				<a class="selectImg" method='get' href='film.php?idFilm=3' ><img src="images/Filme/JocuriSecrete.jpg" alt="Jocuri Secrete" /></a>
				<p>Molly’s Game (2017) este un film biografic care urmărește povestea tinerei Molly Bloom, o fostă schioare profesionistă, care la sfârșitul anilor 2000 a devenit cunoscută sub numele de „prințesa poker-ului“</p>
			</li>
			<li class="last">
				<h4>Jumanji</h4>
				<a class="selectImg" method='get' href='film.php?idFilm=4' ><img src="images/Filme/Jumanji.jpg" alt="Jumanji" /></a>
				<p>Four teenagers discover an old video game console and are literally drawn into the game's jungle setting becoming the adult avatars they chose.</p>
			</li>
			<li class="clear">&nbsp;</li>
		</ul>
	</div>														            	