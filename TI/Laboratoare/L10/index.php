<!DOCTYPE html>
<html>
	<head>
		<title>TI</title>
		<meta charset="utf-8" />
		<link rel="stylesheet" type="text/css" href="css/style.css" />
	</head>
	<body>
		<header id="antet">
			<span id="titlu">TI</span>
			<nav>
				<a href="index.php?sectiune=acasa" >
					   <?php if (isset($_GET['sectiune']) && $_GET['sectiune'] == "acasa");?> Acasa </a>
				<a href="index.php?sectiune=info">
					   <?php if (isset($_GET['sectiune']) && $_GET['sectiune'] == "info");?> Informații </a>
				<a href="index.php?sectiune=test" >
						 <?php if (isset($_GET['sectiune']) && $_GET['sectiune'] == "test");?> Test grilă </a>
			</nav>
		</header>
		
		<main>
			<section>
				<?php
					if (!isset($_GET['sectiune']))
					{
						$sectiune = "acasa.php";
					}
					else
					{
						$sectiune = $_GET['sectiune'];
						$sectiune = $sectiune.".php";
					}
					include($sectiune);
				?>
			</section>
		</main>
		<footer>
			Copyright &copy; 2017 - By Zava
		</footer>
	</body>
</html>