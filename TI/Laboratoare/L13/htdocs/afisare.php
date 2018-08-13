<!DOCTYPE html>
<html >
    <head>
		<title>Biblioteca</title>
		<meta charset=\"utf-8\" />
		<link rel="stylesheet" type="text/css" media="screen" href="css/style.css"/>
		<script type="text/javascript" src="js/script.js"></script>

	</head>
	<body onload="localSt()">
	<header class="header">
		<h1>Biblioteca</h1> 
	</header>

		<div  lass=<main_section">
			<form method="post" action="index.php">
				<button onclick="localSt();"  >HOME</button>
			</form>
			<script type="text/javascript">
				var biblioteca = null;
				var titlu=document.getElementById("titlu");
				var autor=document.getElementById("autor");
				function Cauta(){
					var titlu=document.getElementById("titlu");
					var autor=document.getElementById("autor");
					var requestString = "https://www.googleapis.com/books/v1/volumes?q="+titlu.value+"+"+autor.value;
					console.log(requestString);
					var xhttp = new XMLHttpRequest();
					xhttp.onreadystatechange = function() {
						if (this.readyState == 4 && this.status == 200) {
							biblioteca = JSON.parse(this.responseText).items;
							var flag = false;
							genereazaTabel(flag);
						}
					};
					
					xhttp.open("GET", requestString, true);
					xhttp.send();
				}

				function newCell(data){
					return '<td>'+data+'</td>';

				}
				function newButton(id, sterge = false){
					if (sterge){
						return '<button class="btn2" onclick="sterge(' + id + ');">Sterge</button>';	
					}
					return '<button class="btn2" onclick="adauga(' + id + ');">Adauga</button>';
				}

				function genereazaTabel(flag = false){
					tabel='<table class="table"><tr><td>Isbn</td><td>Titlu</td><td>Autor</td><td>Editura</td><td>An</td></tr>';
					
					for(var i = 0; i < biblioteca.length; ++i){
						tabel += '<tr>';
						if(biblioteca[i].volumeInfo.industryIdentifiers)
							tabel += newCell(biblioteca[i].volumeInfo.industryIdentifiers[0].identifier);
						else
							tabel+="<td>-</td>";
						if(biblioteca[i].volumeInfo.title)
							tabel += newCell(biblioteca[i].volumeInfo.title);
						else
							tabel+="<td>-</td>";
						
						if(biblioteca[i].volumeInfo.authors)
							tabel += newCell(biblioteca[i].volumeInfo.authors);
						else
							tabel+="<td>-</td>";
						
						if(biblioteca[i].volumeInfo.publisher)
							tabel += newCell(biblioteca[i].volumeInfo.publisher);
						else
							tabel+="<td>-</td>";
						
						if(biblioteca[i].volumeInfo.publishedDate)
							tabel += newCell(biblioteca[i].volumeInfo.publishedDate);
						else
							tabel+="<td>-</td>";
						tabel += newCell(newButton(i, flag));
						tabel += '</tr>';
					}
					tabel += '</table>';
					document.getElementById('display').innerHTML = tabel;
				}

				function adauga(id){
					var biblioteca2 = null;
					biblioteca2 = localStorage.getItem('carti');
					if (biblioteca2 == null){
						biblioteca2 = Array();
					} else {
						biblioteca2 = JSON.parse(biblioteca2);
					}
					biblioteca2.push(biblioteca[id]);
					localStorage.setItem('carti', JSON.stringify(biblioteca2));
				}

				function localSt(){
					var biblioteca2 = null;
					biblioteca2 = localStorage.getItem('carti');
					if (biblioteca2 == null){
						biblioteca2 = Array();
					} else {
						biblioteca2 = JSON.parse(biblioteca2);
					}
					biblioteca = biblioteca2;
					var flag = true;
					genereazaTabel(flag);
				}

				function sterge(id){
					var biblioteca2 = null;
					biblioteca2 = localStorage.getItem('carti');
					if (biblioteca2 == null){
						biblioteca2 = Array();
					} else {
						biblioteca2 = JSON.parse(biblioteca2);
					}
					biblioteca2.splice(id,1);// Elimina elenetul #ID
					biblioteca = biblioteca2;
					localStorage.setItem('carti', JSON.stringify(biblioteca2));
					var flag = true;
					genereazaTabel(flag);
				}

				</script>
			<div  id="display"></div>
		</div>
	</body>
</html>