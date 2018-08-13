
window.onload = function() {
	loadDoc('acasa.html');
}

function calcul() {
    var x = document.getElementById("first").value;
    var y = document.getElementById("second").value;
	var select = document.getElementById("select").value;
	var z;
	x = parseFloat(x);
	y = parseFloat(y);
	if(!(isNaN(x) || isNaN(y)))
	{
		switch(select){
			case "plus":
				z = x + y;
				document.getElementById("result").innerHTML = "Rezultat: "+z;
				break;
			case "minus":
				z = x - y;
				document.getElementById("result").innerHTML = "Rezultat: "+z;
				break;
			case "multiply":
				z = x * y;
				document.getElementById("result").innerHTML = "Rezultat: "+z;
				break;
			case "divide":
				if(y == "0")
					{
					alert("Nu se face împărțire la 0.");
					document.getElementById("result").innerHTML = "Rezultat: -";
					}
					
				else
					{
					z = x / y;
					document.getElementById("result").innerHTML = "Rezultat: "+z;
					}
					
				break;
		}
			
	}
	else
	{
		alert("Introduceți numai cifre!");
	}
  
}

function verificare() {
	var xmlhttp;
	var name = document.getElementById("nume").value;
	var pass = document.getElementById("parola").value;
	var ok = false;

	if (window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
		xmlhttp.onreadystatechange = function() {
			if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
				var JSONobj = JSON.parse(xmlhttp.responseText);
				for (var i = 0; i < JSONobj.utilizatori.length; ++i)
				{
					if (JSONobj.utilizatori[i].nume == name && JSONobj.utilizatori[i].parola == pass)
					{
						document.getElementById("mesaj").innerHTML = "<span style='color: green;'>Autentificare cu succes!</span>";
						ok = true;
					}
				}
				if (!ok)
				{
					document.getElementById("mesaj").innerHTML = "<span style='color: red;'>Autentificare eșuată!</span>";
				}
			}
		}
	}
	document.getElementById("mesaj").innerHTML = "<span style='color: red;'>Autentificare</span>";
	xmlhttp.open("GET", "Json/utilizatori.json", true);
	xmlhttp.send();

}


function preiaXML(xml) {
    var xmlDoc = xml.responseXML;

    var carte = xmlDoc.getElementsByTagName("carte");
    var tabel = document.getElementById("tabel");

    document.getElementById("incarcare").style.display = "none";
    tabel.style.display = "block";
    document.getElementById("titluTabel").style.display = "block";

    console.log(carte.length);
    for (var i = 0; i < carte.length; ++i)
    {
    	var rand = tabel.insertRow(i + 1);
    	var id = rand.insertCell(0);
    	var titlu = rand.insertCell(1);
    	var autor = rand.insertCell(2);
    	var anAparitie = rand.insertCell(3);

    	id.innerHTML = carte[i].getElementsByTagName("id")[0].childNodes[0].nodeValue;
    	titlu.innerHTML = carte[i].getElementsByTagName("titlu")[0].childNodes[0].nodeValue;
    	autor.innerHTML = carte[i].getElementsByTagName("autor")[0].childNodes[0].nodeValue;
    	anAparitie.innerHTML = carte[i].getElementsByTagName("anAparitie")[0].childNodes[0].nodeValue;
    }
}

function citesteXML() {
	var xmlhttp;

	if (window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
		xmlhttp.onreadystatechange = function() {
			if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
				preiaXML(this);
			}
		}
	}

	xmlhttp.open("GET", "xml/biblioteca.xml", true);
	xmlhttp.send();
}

function loadDoc(pagina) {
	var xmlhttp;

	if (window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
		xmlhttp.onreadystatechange = function() {
			if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
				document.getElementById("continut").innerHTML = xmlhttp.responseText;
				
				if (pagina == "biblioteca.html") {
					setTimeout(function(){
						citesteXML();
					}, 2000);
				}	
				
			}
		}
	}

	xmlhttp.open("GET", pagina, true);
	xmlhttp.send();
}