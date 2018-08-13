<?php
	session_start();

	$myFile = "../json/bilete.json";
	$arr_data = array();
	$formdata = array();
	$struct=array();
	$locuri_selectate = array();

	if ($_SERVER['REQUEST_METHOD'] == "GET" && isset($_GET['locuri']))
	{
		eval('$locuri_selectate = ' . $_GET['locuri'] . ';');
		//$locuri_selectate=$_GET['locuri'];
		print_r($locuri_selectate);

		foreach ($locuri_selectate as $loc) {
  			try
			  {
				//Get form data
				$struct = array(
				   'loc'=> $loc
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
				file_put_contents($myFile, $jsondata);

			  }
		   	catch (Exception $e) {
		           $message = "$e->getMessage()";  
		   		}
			}
		
	}

	echo $locuri_selectate;
?>