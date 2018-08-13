<?php	
	session_start();
	if (isset($_SERVER['REQUEST_METHOD']) == 'POST' && isset($_POST['golire'])){
		unset($_SESSION['cos']);
		header("Location: ../cos.php");
		die();
	}
	
	if ($_SERVER['REQUEST_METHOD'] == "POST" && isset($_POST['modifica']))
	{
		$id_ob=$_POST['modifica']; //aceasta variabila contine id-ul produsului
		$handle = @fopen("../../res/produse.txt", "r");
		if(!isset($_SESSION['cos']))	//daca in variabila globala $_SESSION['cos'] nu avem nimic atunci o initializam un un array nul
			$_SESSION['cos'] = array();

		if ($handle) {
			while (($buffer = fgets($handle, 4096)) !== false) {
				$i=$i+1;

				$produs = json_decode($buffer,true);	
				
				//determin produsull care are id-ul primit
				if($id_ob == $produs["id"])
				{
					
					//daca produsul nu se afla in vectorul cos
					if(!in_array($produs, $_SESSION['cos']))
					{
						array_push($_SESSION['cos'],$produs);	
					}	
					else
					{
						// il stergem daca se afla in vectorul cos
						$key = array_search($produs,$_SESSION['cos']);
						array_splice($_SESSION['cos'],$key,1);
					}
				}
				
				}
				
			if (!feof($handle)) {
				echo "Error: unexpected fgets() fail\n";
				}
			fclose($handle);
		}
		
	}
	header("Location: ../cos.php");
?>