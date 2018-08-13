<?php
	session_start();
	$n = count($_SESSION['cos']);
?>
<!DOCTYPE html>
<html>
	<head>
		<title>TI L12</title>
		<meta charset="utf-8" />
		<link rel="stylesheet" type="text/css" href="css/style.css" />
	</head>
	<body>
		<header class="header">
			<h1>Magazin online<h1>
		</header>
		<span class="location">
			<a href="index.php">
				<img border="0" alt="shop" src="shop.png" width="50" height="50">
			</a>
		</span>
		<section class="main_section">
		<?php
			//daca sunt produse in cos se afiseaza capul de tabel
			if($n)
			{
				echo " <font size=5> Produsele dumneavoastră </font>";
				echo "</br></br>";
				echo"<table id=\"myTable\"> <tr><th>ID</th><th>Nume</th><th>Producător</th><th>Pret</th></tr>";
			}
			
			//se afiseaza produsele
			 for($i=0 ;$i<$n ; $i++)
			 {
				$produs = $_SESSION['cos'][$i];
				echo "<td>".$produs['id']."</td>";
				echo "<td><a method='get' href='produs.php?idProdus=".$produs["id"]."' >" .$produs["nume"]. "</a></td>";
				echo "<td>".$produs['producator']."</td>";
				echo "<td>".$produs['pret']."</td>";		
				echo "<form action='api/modifica.php' method='post'>";
				echo "<td> <button class='btn1' name='modifica' value=".$produs[id]."> X </button></td></tr>";
				echo "</form>";
	
			}
			//daca nu sunt produse in cos se va afisa un mesaj
			if(!$n)
			{
				echo "<b> Coșul este gol! </br><b>";
				echo "<b> Vă rugăm să vizitați ";
				echo "<a href=".index.".".php."> magazinul </a>";
				echo " pentru a adăuga produse în coș <b>";
			}
			else
			{
				echo"</table>";
			}
			?> 
			 

		</section>

<footer>Copyright &copy; 2017 ZAVA</footer>