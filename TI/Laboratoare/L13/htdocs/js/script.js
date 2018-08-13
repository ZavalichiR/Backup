var books=Array();
function Adauga(id)
{
	var local;
	local = localStorage.getItem('json');
	local = JSON.parse(local);
	if(local==null){
		local=Array();
	}
	local.push(books[id]);
	localStorage.setItem('json', JSON.stringify(local));
	console.log(JSON.parse(localStorage.getItem("json")));
	
}
function Cauta()
{
	var titlu=document.getElementById("intitle").value;
	var autor=document.getElementById("inauthor").value;

	var tabel = "<table class='table'><tr><td>Isbn</td><td>Titlu</td><td>Autor</td><td>Editura</td><td>An</td></tr>";
	if (window.XMLHttpRequest) {
		xmlhttp = new XMLHttpRequest();
		xmlhttp.onreadystatechange = function() {
			if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
				var JSONobj = JSON.parse(xmlhttp.responseText);
				for (var i = 0; i < JSONobj.items.length; ++i)
				{
					tabel += "<tr>";
					if(JSONobj.items[i].volumeInfo.industryIdentifiers){
						var isbn = JSONobj.items[i].volumeInfo.industryIdentifiers[0].identifier;
						tabel += "<td>"+isbn+"</td>";
					}
					else
					{
						tabel += "<td>-</td>";
					}

					if(JSONobj.items[i].volumeInfo.title){
						var titlu = JSONobj.items[i].volumeInfo.title;
						tabel += "<td>"+titlu+"</td>";
					}
					else
					{
						tabel += "<td>-</td>";
					}

					if( JSONobj.items[i].volumeInfo.authors)
					{
						var autor = JSONobj.items[i].volumeInfo.authors[0];
						tabel += "<td>"+autor+"</td>";
					}
					else
					{
						tabel += "<td>-</td>";
					}

					if(JSONobj.items[i].volumeInfo.publisher)
					{
						var editura = JSONobj.items[i].volumeInfo.publisher;
						tabel += "<td>"+editura+"</td>";
					}
					else
					{
						tabel += "<td>-</td>";
					}

					if(JSONobj.items[i].volumeInfo.publisherData)
					{
						var an = JSONobj.items[i].volumeInfo.publisherData;
						tabel += "<td>"+an+"</td>";
					}
					else
					{
						tabel += "<td>-</td>";
					}
					
					//books.push(JSONobj.items[i]);
					books = JSON.parse(this.responseText).items;
					tabel += '<td><button onclick="Adauga(' + i + ');">Adauga</button></td>'
					tabel += "</tr>"
				}
				//}
				tabel += "</table>";
				document.getElementById("carte").innerHTML = tabel;
			}	
		}
	}

	xmlhttp.open("GET", "https://www.googleapis.com/books/v1/volumes?q=inauthor:King+intitle:Shining", true);
	xmlhttp.send();
}
// localStorage.setItem('books', JSON.stringify(biblioteca))
//biblioteca = JSON.parse(localSotrage.getItem('books'))
//JSON.stringify(vector vector de obiecte
//1.) citire vector
//2) Eliminare element vizat din vectorul respectiv
//3) Salvare vector
//La pasul 1 si la pasul 3 ai de facut  encode respectiv decode


//1. Citire vector
//1.5 JSON.decode(...)
//2. vector.splice()
//3. JSON.stringify(vector)
//4 SetItem
 