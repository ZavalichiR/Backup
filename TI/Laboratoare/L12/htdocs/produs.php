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
	<body >
		<header class="header">
			<h1>Magazin online<h1>
		</header>
		
		<span class="location">
			<a href="index.php">
				<img border="0" alt="shop" src="shop.png" width="50" height="50">
			</a>		
			<a href="cos.php" src="cos.png">
				<img border="0" alt="cos" src="cos.png" width="40" height="40">
			</a>
		</span>
		<section class="main_section">
			<?php
			if ($_SERVER['REQUEST_METHOD'] == "GET" && isset($_GET['idProdus']))
			{
				$id_ob=$_GET['idProdus'];
				$handle = @fopen("../res/produse.txt", "r");		
				if ($handle) {
					
					while (($buffer = fgets($handle, 4096)) !== false) {
						$i=$i+1;

						//determin ce produs are id-ul $id_ob.
						$produs = json_decode($buffer,true);	
						if($id_ob == $produs["id"])
						{
			?>		

<span>
<font size="6">
	<u>Id produs:</u> <?php echo $produs['id']?></br>
	<u>Nume produs:</u> <?php echo $produs['nume']?> </br>
	<u>Producator:</u> <?php echo $produs['producator']?></br>
	<u>Pret:</u> <?php echo $produs['pret']?> lei</br>
</font>	
</span>

			<?php	
						}
					}
				}
					
					
				if (!feof($handle)) {
					echo "Error: unexpected fgets() fail\n";
					}
				fclose($handle);
			}	
			?> 
		</section>
		
<footer>Copyright &copy; 2017 ZAVA</footer>