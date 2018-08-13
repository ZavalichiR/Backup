<?php	
	session_start();
	
	// verificare daca datele au fost trimise prin POST
	if ($_SERVER['REQUEST_METHOD'] == "POST" && isset($_POST['utilizator']) && isset($_POST['parola']))
	{
		// preluam datele introduse de utilizator
		$utilizator = $_POST['utilizator'];
		$parola = $_POST['parola'];

		// verificam daca datele sunt corecte
		if (!preg_match("/^[a-z\d_]{4,10}$/i", $utilizator))
		{
			$_SESSION['eroare'] = "Numele de utilizator trebuie să conțină între 4 și 10 de caractere alfanumerice sau / și underscore!";
			header("Location: ../index.php");
			exit();
		}
		if (!preg_match("/^[a-z\d]{4,10}$/i", $parola))
		{
			$_SESSION['eroare'] = "Parola trebuie să conțină între 6 și 10 de caractere alfanumerice!";
			header("Location: ../index.php");
			exit();
		}
		
		if (empty($utilizator) || empty($parola))
		{
			$_SESSION['eroare'] = "Câmpuri goale";
			header("Location: ../index.php");
			exit();
		}
		else
		{
		
			$listaUtilizatori = "utilizatori.txt";
			$handle = file_get_contents("utilizatori.txt", "r") or die('Nu se poate deschide fisierul cu lista de utilizatori!');

			
			// cautam in lista de utilizatori
			$gasit = false;
			$json_content = json_decode($handle, true);
			foreach ($json_content["utilizatori"] as &$json_value)
			{
				// daca exista o potrivire
				if ($json_value["nume_utilizator"] == $utilizator && $json_value["parola"] == $parola )
				{
					// salvam sesiunea
					$_SESSION['utilizator'] = $utilizator;
					
					$gasit = true;

					break;
				}
			}
				
			if (!$gasit)
			{
				$_SESSION['eroare'] = "Numele de utilizator și / sau parola nu sunt corecte!"; //alta variabila globala
				header("Location: ../index.php");
			}
			else
			{
				header("Location: ../index.php");
				exit();
			}
		
		}
		
		
	}
	

?>