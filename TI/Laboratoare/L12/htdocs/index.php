<?php
	session_start();
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
			<a href="cos.php" src="cos.png">
				<img border="0" alt="cos" src="cos.png" width="40" height="40">
			</a>
		</span>
		
		<section class="main_section">		
				<?php
					//verific daca s-a logat un ultilizator ( $_SESSION['utilizator'] este o variabila globala ) 
					if(!isset($_SESSION['utilizator']))
					{
				?>		
				
					<h3>Introduceți datele: </h3>
						<form action='api/login.php' method='post'> 
							<label>Nume: </label>
							<input type="text" name="utilizator" />
							<br />
							<label>Parolă: </label>
							<input type="password" name="parola" />
							<br />
							<input type="submit" value="Login" />
						</form>
				
					<?php
						if (isset($_SESSION['eroare']))
						{
							echo "<span style='color: red;'>".$_SESSION['eroare']."</span>";
							unset($_SESSION['eroare']);
						}
					}
					else{
						//daca este deja conectat
						echo "<font size=5> Bună ziua, ".$_SESSION['utilizator']."!</font></br>";
						echo"<pre>";
						echo "<form action='api/logout.php' >";
						echo "<button class='btnO' > Logout </button>";
						echo "</form>";
						echo"</pre>";
						echo "</br></br>";
											
												
						$handle = @fopen("../res/produse.txt", "r"); //descidem fisierul
						echo "<table id=\"myTable\"> <tr><th>ID</th><th>Nume</th><th>Producător</th><th>Pret</th><th>Modifică</th></tr>";
						echo "<font size=5> Produsele magazinului:</font>";
						if ($handle) {
							while (($buffer = fgets($handle, 4096)) !== false) {
								$produs= json_decode($buffer,true);
								
								echo "<tr><td>" .$produs["id"]. "</td>";
								echo" <td><a method='get' href='produs.php?idProdus=".$produs["id"]."' >" .$produs["nume"]. "</a></td>";								
								echo "<td>".$produs["producator"]."</td>";
								echo "<td>".$produs["pret"]." lei</td>";
								echo "<form action='api/modifica.php' method='post'>";
								echo "<td> <button class='btn1' name='modifica' value=".$produs[id]."> O </button></td>";
								echo "</form>";
								echo "</tr>";
								
							}
								?>
							</table>
								<form action='api/modifica.php' method='post'>
									<input type="hidden" name="golire">
									<input type="submit" class='btn1' value="Golire coș">
								</form>
								
							<?php
							if (!feof($handle)) {
								echo "Error: unexpected fgets() fail\n";
							}
							fclose($handle);
						}
					}					
				
					
					?>
				
			</section>
			
			
		<footer>Copyright &copy; 2017 ZAVA</footer>
	</body>
</html>