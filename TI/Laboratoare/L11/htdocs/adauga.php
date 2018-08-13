<?php
if(isset($_COOKIE['utilizator']) && $_COOKIE['utilizator'] != "") {
    $target_dir = "utilizatori/" . $_COOKIE['utilizator'] . "/";
}
else {
    $target_dir = "utilizatori/";
}
$target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
$uploadOk = 1;
$imageFileType = pathinfo($target_file,PATHINFO_EXTENSION);

// Check if file already exists
if (file_exists($target_file)) {
    echo "Fișierul selectat există deja";
    $uploadOk = 0;
}

// if everything is ok, try to upload file
if ($uploadOk != 0) {
    if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {
        $response = "{" .
            "\"nume\": \"" . $_FILES["fileToUpload"]["name"] . "\", " .
            "\"extensie\": \"" . pathinfo($_FILES["fileToUpload"]["name"],PATHINFO_EXTENSION) . "\", " .
            "\"dataModificare\": \"" . date("F d Y H:i:s.",filemtime($target_file)) . "\", " .
            "\"dimensiune\": \"" . $_FILES["fileToUpload"]["size"] . "\", " .
            "\"link\": \"" . $target_dir . $_FILES["fileToUpload"]["name"] .
            "\"}";
        echo $response;
    } else {
        echo "Fișierul nu a putut fi încărcat";
    }
}
?>