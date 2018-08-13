<?php	
	session_start();
	$myFile = "../json/informatii.json";
	$myFile2 = "../json/informatiiClient.json";
	$arr_data = array();
	$formdata = array();
	$struc=array();

	// verificare daca datele au fost trimise prin POST
	if ($_SERVER['REQUEST_METHOD'] == "POST" && isset($_POST['nume']) && isset($_POST['mail']) && isset($_POST['mesaj']))
	{
		// preluam datele introduse de utilizator
		$utilizator = $_POST['nume'];
		$mail = $_POST['mail'];
		$mesaj = $_POST['mesaj'];
		
		try
		  {
			//Get form data
			$struct = array(
			   'nume'=> $_POST['nume'],
			   'mail'=> $_POST['mail'],
			   'mesaj'=>$_POST['mesaj']
			);
			
			$jsondata = file_get_contents($myFile);
			$arr_data = json_decode($jsondata, true);
			if($arr_data==null)
			{
				$arr_data=array();
			}
    		array_push($arr_data,$struct);
			$formdata=$arr_data;
			$jsondata = json_encode($formdata, JSON_PRETTY_PRINT);
			   																											
			if(file_put_contents($myFile, $jsondata)){
			    $message="Mesajul a fost trimis cu succes";
			   	
			}
			else {
		        $message="EROARE! Mesajul nu a fost trimis!";
			}

		   }
	   	catch (Exception $e) {
	           $message = "$e->getMessage()";  
	   		}
	}
	else
	{
		if ($_SERVER['REQUEST_METHOD'] == "POST" && isset($_POST['nume']) && isset($_POST['prenume']) && isset($_POST['telefon']) && isset($_POST['bilete']))
		{
			// preluam datele introduse de utilizator
			$nume = $_POST['nume'];
			$prenume = $_POST['prenume'];
			$telefon = $_POST['telefon'];
			$bilete = $_POST['bilete'];
			$bilete = json_decode($bilete);
			
			try
			  {
				//Get form data
				$struct = array(
				   'nume'=> $_POST['nume'],
				   'prenume'=> $_POST['prenume'],
				   'telefon'=>$_POST['telefon'],
				   'bilete'=>$bilete
				);
				
				$jsondata = file_get_contents($myFile2);
				$arr_data = json_decode($jsondata, true);
				if($arr_data==null)
				{
					$arr_data=array();
				}
	    		array_push($arr_data,$struct);
				$formdata=$arr_data;
				$jsondata = json_encode($formdata, JSON_PRETTY_PRINT);
				   																											
				if(file_put_contents($myFile2, $jsondata)){
				    $message="Biletele au fost inregistrate cu succes";
				   	
				}
				else {
			        $message="EROARE! Mesajul nu a fost trimis!";
				}

			   }
		   	catch (Exception $e) {
		           $message = "$e->getMessage()";  
		   		}

		   	 $message="Biletele au fost inregistrate cu succes";
		}
	}
	echo "<script type='text/javascript'>alert('$message');</script>"; 	
	echo "<script type='text/javascript'>window.location.href = '../index.php';</script>";
?>