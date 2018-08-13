var slideIndex = 1;
// Next/previous controls
function plusSlides(n) {
  showSlides(slideIndex += n);
}

// Thumbnail image controls
function currentSlide(n) {
  showSlides(slideIndex = n);
}

function showSlides(n) {
  var i;
  var slides = document.getElementsByClassName("mySlides");
  var dots = document.getElementsByClassName("dot");
  if (n > slides.length) {slideIndex = 1} 
  if (n < 1) {slideIndex = slides.length}
  for (i = 0; i < slides.length; i++) {
      slides[i].style.display = "none"; 
  }
  for (i = 0; i < dots.length; i++) {
      dots[i].className = dots[i].className.replace(" active", "");
  }
  slides[slideIndex-1].style.display = "block"; 
  dots[slideIndex-1].className += " active";
}

var locuri_selectate=Array();
var scaune_selectate=Array();

//Afiseaza filmul in functie de id
function afiseazaFilm(id) {
	var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            var data = xhr.responseText;
        }
    }
    xhr.open('GET', "Movie?id="+id, true);
    xhr.send(null);
}

//Afiseaza lista cu toate filmele
function afiseazaFilme()
{
	var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            var data = xhr.responseText;
            document.getElementById("lista").innerHTML=data;
        }
    }
    xhr.open('GET', "ShowMoviesList", true);
    xhr.send(null);
}

//Afiseaza filmele cautate
function showResult(str) {
	var xhr = new XMLHttpRequest();
    xhr.onreadystatechange = function() {
        if (xhr.readyState == 4) {
            var data = xhr.responseText;
            document.getElementById("gasit").innerHTML=data;
        }
    }
    xhr.open('GET', "ReturnMovieName?str="+str, true);
    xhr.send(null);
}

//Verificare input pentru contact Echipa
function validare(){
	var nume=document.forms["contact"]["nume"];
	var email=document.forms["contact"]["mail"];
	var mesaj=document.forms["contact"]["mesaj"];
	nume.style.background = 'Black';
	email.style.background = 'Black';
	mesaj.style.background = 'Black';
	nume.style.color = 'White';
	email.style.color = 'White';
	mesaj.style.color = 'White';
		var error = "";
	    var illegalChars = /\W/; 
	
	    if (nume.value == "" || email.value=="" || mesaj.value=="") {
	        nume.style.background = 'Yellow';
	        email.style.background = 'Yellow';
	        mesaj.style.background = 'Yellow';
	        nume.style.color = 'Black';
			email.style.color = 'Black';
			mesaj.style.color = 'Black';

	        error = "Completați toate câmpurile!\n";
	        document.getElementById("eroareV").innerHTML=error;
	        //alert(error);
	        return false;
	 
	    } else if ((nume.value.length < 5) || (nume.value.length > 15)) {
	        nume.style.background = 'Yellow';
	        nume.style.color = 'Black';
	        error = "Numele trebuie să fie format din minim 5 litere, maxim 15!\n";
	        document.getElementById("eroareV").innerHTML=error;
			//alert(error);
			return false;
	 
	    } else if (illegalChars.test(nume.value)) {
	        nume.style.background = 'Yellow';
	        nume.style.color = 'Black';
	        error = "Numele conține caractere nepermise!\n";
	        document.getElementById("eroareV").innerHTML=error;
			//alert(error);
			return false;
	 
	    }	 
	    else {
	    	//Numele a fost validat
	        nume.style.background = 'Black';
	        nume.style.color = 'White';

	        var atpos = email.value.indexOf("@");
	    	var dotpos = email.value.lastIndexOf(".");
	    	if (atpos<1 || dotpos<atpos+2 || dotpos+2>=x.length) {
	    		email.style.background = 'Yellow';
	    		email.style.color = 'Black';
	    		error="Adresa de email nu este validă!";
	    		document.getElementById("eroareV").innerHTML=error;
	        	//alert(error);
	        	return false;
	    	}
	    	else{
	    		//Adresa a fost validata
	    		email.style.background = 'Black';
	        	email.style.color = 'White';
	    	}
	    }
	    return true;
}

// Verificare date contact pentru Client
function validare2(){
	var nume=document.forms["confirmare"]["nume"];
	var prenume=document.forms["confirmare"]["prenume"];
	var telefon=document.forms["confirmare"]["telefon"];
	nume.style.background = 'White';
	prenume.style.background = 'White';
	telefon.style.background = 'White';
	nume.style.color = 'Black';
	prenume.style.color = 'Black';
	telefon.style.color = 'Black';

		var error = "";
	    var illegalChars = /\W/; 
	
	    if (nume.value == "" || prenume.value=="" || telefon.value=="") {
	        nume.style.background = 'Yellow';
	        prenume.style.background = 'Yellow';
	        telefon.style.background = 'Yellow';
	        nume.style.color = 'Black';
			prenume.style.color = 'Black';
			telefon.style.color = 'Black';

	        error = "Completați toate câmpurile!\n";
	        document.getElementById("eroareV").innerHTML=error;
	        //alert(error);
	        return false;
	 
	    } else if ((nume.value.length < 5) || (nume.value.length > 15)) {
	        nume.style.background = 'Yellow';
	        nume.style.color = 'Black';
	        error = "Numele trebuie să fie format din minim 5 litere, maxim 15!\n";
			document.getElementById("eroareV").innerHTML=error;
			//alert(error);
			return false;
	 
	    } else if (illegalChars.test(nume.value)) {
	    	
	        nume.style.background = 'Yellow';
	        nume.style.color = 'Black';
	        error = "Numele conține caractere nepermise!\n";
			document.getElementById("eroareV").innerHTML=error;
			//alert(error);
			return false;
	 
	    } 
	    else {
	    	//Numele a fost validat
	    	numeForm=nume.value;
	        nume.style.background = 'White';
	        nume.style.color = 'Black';

	        if ((prenume.value.length < 5) || (prenume.value.length > 15)) {
		        prenume.style.background = 'Yellow';
		        prenume.style.color = 'Black';
		        error = "Prenumele trebuie să fie format din minim 5 litere, maxim 15!\n";
				document.getElementById("eroareV").innerHTML=error;
				//alert(error);
				return false;
		 
		    } else if (illegalChars.test(prenume.value)) {
		        prenume.style.background = 'Yellow';
		        prenume.style.color = 'Black';
		        error = "Prenumele conține caractere nepermise!\n";
				document.getElementById("eroareV").innerHTML=error;
				//alert(error);
				return false;
		 
		    }
		    else{
			    	//Prenumele a fost validat
		    	prenumeForm=prenume.value;
		        nume.style.background = 'White';
		        nume.style.color = 'Black';

		        var stripped = telefon.value.replace(/[\(\)\.\-\ ]/g, '');
		    	if (isNaN(parseInt(stripped))) {
			        error = "Numărul de telefon conține caractere nepermise! \n";
			        telefon.style.background = 'Yellow';
			        telefon.style.color = 'Black';
			        document.getElementById("eroareV").innerHTML=error;
			       // alert(error);
					return false;
			    } else if (!(stripped.length == 10)) {
			        error = "Numărul de telefon trebuie să conțină 10 cifre!\n";
			        telefon.style.background = 'Yellow';
			        telefon.style.color = 'Black';
			        document.getElementById("eroareV").innerHTML=error;
			        //alert(error);
					return false;
			    }
		    	else{
		    		//Telefonul a fost validat
		    		telefonForm=telefon.value;
		    		telefon.style.background = 'White';
		        	telefon.style.color = 'Black';
		        	
		    	}
		    }
	        
	    }
	    return true;
	//}
}

// Pune locurile selectate //
function selectat(elem) {
	var loc_selectat=elem.id;

	var pozitie;
	var nr=elem.id;
	if(nr>=1 && nr<=12)
	{
		pozitie="r1-l"+nr;
	}else if(nr>=13 && nr<=24)
	{
		pozitie="r2-l"+(nr-12);
	}else if(nr>=25 && nr<=36)
	{
		pozitie="r3-l"+(nr-24);
	}else if(nr>=37 && nr<=48)
	{
		pozitie="r4-l"+(nr-36);
	}else if(nr>=49 && nr<=60)
	{
		pozitie="r5-l"+(nr-48);
	}else if(nr>=61 && nr<=72)
	{
		pozitie="r6-l"+(nr-60);
	}else if(nr>=73 && nr<=84)
	{
		pozitie="r7-l"+(nr-72);
	}else if(nr>=85 && nr<=97)
	{
		pozitie="r8-l"+(nr-84);
	}else if(nr>=98 && nr<=110)
	{
		pozitie="r9-l"+(nr-97);
	}else if(nr>=111)
	{
		pozitie="r10-l"+(nr-110);
	}
	

	if(elem.className=="loc-cinema"){
		elem.className="loc-cinema-selectat";
		locuri_selectate.push(loc_selectat);
		scaune_selectate.push(pozitie);
	}
	else{ 
		if(elem.className=="loc-cinema-selectat"){
		elem.className="loc-cinema";
		var index = locuri_selectate.indexOf(elem.id);
		locuri_selectate.splice(index, 1);
		scaune_selectate.splice(index,1);	
		}
		
	}

	document.getElementById("locuriSelectate").innerHTML=scaune_selectate;	
	document.getElementById("locuriSelectatef").innerHTML=scaune_selectate;
}


// trimite locurile selectate și informații client la Servlet Bilete //
function selecteaza(idFilm){
	
	var nume=document.forms["confirmare"]["nume"].value;
	var prenume=document.forms["confirmare"]["prenume"].value;
	var telefon=document.forms["confirmare"]["telefon"].value;
	var id=idFilm;
	
	if (window.XMLHttpRequest){
	    xmlhttp=new XMLHttpRequest();
	}
	else{
	    xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	}

	xmlhttp.onreadystatechange=function() {
	    if (this.readyState==4 && this.status==200) {
	    	
	    }
	  }
	locuriS=locuri_selectate;
	scauneS=scaune_selectate;
	xmlhttp.open("POST", "Bilete?locuriS="+locuriS+"&scauneS="+scauneS+"&nume="+nume+"&prenume="+prenume+"&telefon="+telefon+"&id="+id, true);
	
	xmlhttp.send();
}

// Pune locurile ocupate de catre alti utilizatori//
function seteazaLocuriOcupate(idFilm){
	var xmlhttp = new XMLHttpRequest();
    xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        var locuri=this.responseText;
        //alert(locuri);
        console.log(locuri);
        var locuriO=locuri.split(",");
        console.log(locuriO);
    	for (var i = 0; i < locuriO.length; i++)
			{
			  console.log(locuriO[i]);
			   var tag=document.getElementById(locuriO[i]);
			   tag.className="loc-cinema-blocat"
			}
       }
    };

	xmlhttp.open("GET", "Bilete?idFilm="+idFilm, true);
	xmlhttp.send();

}

// Incarca paginile //
function loadDoc(pagina) {
	var xmlhttp;

	if (window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
		xmlhttp.onreadystatechange = function() {
			if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
				document.getElementById("continut").innerHTML = xmlhttp.responseText;
				
				if (pagina == "ShowMoviesList") {
					showSlides(1);
				}
			}
		}
	}

	xmlhttp.open("GET", pagina, true);
	xmlhttp.send();
}



