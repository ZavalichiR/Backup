<!DOCTYPE html>
<html>
	<head>
		<head>
			<meta charset="utf-8"/>
			<link rel="stylesheet" type="text/css" href="css/style.css"/>
			<script src="js/javascript2.js"></script>
			<title>L11</title>
		</head>
	</head>
	<body onload="loadInfo()">
		<header class="header">
			<h1>TI L11 (2-3)</h1>
		</header>

		<section class="main_section">
			<div c>
				<form action="index2.php" id="login">
					<input type="text" id="nume" />
					<input type="submit" value="Vizualizează" onclick="changeUser();" />
				</form>

				<form action="index2.php" method="post" enctype="multipart/form-data" id="upload">
				    Selectați fișierul:
				    <input type="file" name="fileToUpload" id="fileToUpload">
				    <input type="submit" value="Încarcă" onclick="loadAdauga(); return false;" name="submit">
				</form>
			</div>

			<span id="messages"></span>

			<hr/>

			<?php
				if(isset($_COOKIE['utilizator'])) {
					if(is_dir("utilizatori/" . $_COOKIE['utilizator'])) {
						echo "<table id=\"myTable\"><tr><th>Nume</th><th>Tip</th><th>Dată Modificare</th><th>Dimensiune</th><th>Link</th><th>Șterge</th></tr>";
						$rowIndex = 1;
						foreach(scandir("utilizatori/" . $_COOKIE['utilizator']) as $file) {
							$filePath = "utilizatori/" . $_COOKIE['utilizator'] . "/" . $file;

							echo "<tr><td class=\"text_left\">" . basename($filePath) .
								"</td><td>" . pathinfo($filePath, PATHINFO_EXTENSION) .
								"</td><td>" . date("F d Y H:i:s.",filemtime($filePath)) . 
								"</td><td>" . filesize($filePath) . " KB" . 
								"</td><td><a class=\"btn2\" href=\"" . $filePath . "\" target=\"_blank\"></a>" . 
								"</td><td><button class=\"btn1\" onclick=\"deleteFile('" . basename($filePath) . "', " . $rowIndex . ")\">X</button>" . 
								"</td></tr>";
							$rowIndex++;
						}
						echo "</table>";
					}
					else {
						echo "Utilizatorul nu există!";
					}
				}
				else {
					echo "Nu există cookie!";
				}
			?>
		
		</section>


	</body>
</html>
