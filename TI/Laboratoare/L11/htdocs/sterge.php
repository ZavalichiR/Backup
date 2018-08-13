<?php
if(isset($_COOKIE['utilizator']) && $_COOKIE['utilizator'] != "") {
    $user = $_COOKIE['utilizator'];
    $file = basename($_POST['fileToDelete']);
    $target_file = "utilizatori/" . $user . "/" . $file;
    
    if (file_exists($target_file)) {
        unlink($target_file);
        echo "0";
    }
    else {
        echo "Fișierul nu există";
    }
}
else {
    echo "Utilizatorul nu este conectat";
}
?>