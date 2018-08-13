<!DOCTYPE html>
<html>
<head>
<title>COOKIE</title>
<script type="text/javascript" src="js/javascript.js"></script>
<link rel="stylesheet" type="text/css" href="css/style.css">
</head>
<body>
	<header class="header">
	<h1>TI L11</h1>
	</header>
	<section class="main_section">
		<form action="index.php">
		
			<input type="text" id="nume" value="<?php echo (isset($_COOKIE['utilizator'])?$_COOKIE['utilizator']:"");?>" />
			<input type="submit" value="Submit!" onclick="schimba()" /> 
		</form>
		</br>
		<?php
		if (isset($_COOKIE['utilizator']))
            {
                if (isset($_GET['sterge']) && file_exists($_COOKIE['utilizator']."/".$_GET['sterge']))
                {
                    unlink($_COOKIE['utilizator']."/".$_GET['sterge']);
                    echo "MSG: Fisierul <font color=blue>".$_COOKIE['sterge']."</font> a fost sters cu succes din directorul <font color=green>".$_COOKIE['utilizator']."</font> !";
                }
                
                if (isset($_FILES['fisiere']))
                {
                    if (!file_exists($_COOKIE['utilizator']))
                    {
                        mkdir($_COOKIE['utilizator']);
                    }
                    
                    $destinatie=$_COOKIE['utilizator']."/".basename($_FILES['fisiere']['name']);
                    
                    if(move_uploaded_file($_FILES['fisiere']['tmp_name'],$destinatie))
                    {
                        echo "MSG: Fisierul <font color=blue>".$destinatie."</font> a fost incarcat cu succes !";
                    }
                    else
                    {
                        echo "MSG: Eroare la upload!";
                    }
                }
                
                if (is_dir($_COOKIE['utilizator']))
                {
                    echo "<table id=\"myTable\"> <tr><th>Nume</th><th>Tip</th><th>Data adăugării</th><th>Dimensiune</th><th>Link</th><th>Sterge</th></tr>";
                    foreach (scandir($_COOKIE['utilizator']) as $file)
                    {
                        if ($file != "." && $file != "..")
                        {
                            echo "<tr><td>" . $file . "</td>";
                            $ext = pathinfo($file, PATHINFO_EXTENSION);
                            echo "<td>" . $ext . "</td>";
                            $fpath = $_COOKIE['utilizator'] . '/' . $file;
                            echo "<td>" . date("F d Y H:i:s", filemtime($fpath)) . "</td>";
                            echo "<td>" . filesize($fpath) . " bytes</td>";
                            echo "<td><a class=\"btn2\" value=\"link\" href=" . $fpath . "></a></td>";
                            echo "<td><a class=\"btn1\" value=\"sterge\" href='?sterge=$file'></a></td>";
                            
                            
                        }
                    }
                    echo "</table>";
                }
                else
                {
                    echo "MSG: Nu exista un astfel de director!";
                }
            }
            else
            {
                echo "Introduceti un utilizatorator!";
            }
        ?>
		<form action="" method="POST" enctype="multipart/form-data" id="file-form">
			<input type="file" id="file-select" name="fisiere" multiple />
			<input type="submit" value="Upload" id="upload-button"/>
		</form>
		<!--
		<script>
			var form = document.getElementById('file-form');
			var fileSelect = document.getElementById('file-select');
			var uploadButton = document.getElementById('upload-button');

			form.onsubmit = function(event)
			{
				event.preventDefault();

				uploadButton.innerHTML = 'Uploading...';

				// Get the selected files from the input.
				var files = fileSelect.files;
				// Create a new FormData object.
				var formData = new FormData();
				// Loop through each of the selected files.
				for (var i = 0; i < files.length; i++)
				{
					var file = files[i];
					// Add the file to the request.
					formData.append('files[]', file, file.name);
				}
					
				var xhttp = new XMLHttpRequest();
				xhttp.onload = function() {
					if (xhhtp.status == 200)
					{
						uploadButton.innerHTML = 'Upload';
					}
				};
				xhttp.open("POST", "adauga.php", true);
				xhttp.send(formData);
			}
		</script>
		-->
	</section>
	

</body>
</html>