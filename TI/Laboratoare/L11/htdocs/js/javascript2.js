function loadAdauga() {
  var fd = new FormData();
  fd.append("fileToUpload", document.getElementById("fileToUpload").files[0]);

  var xhttp = new XMLHttpRequest();

  xhttp.open("POST", "adauga.php", true);

  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      try {
        var response = JSON.parse(this.responseText);
        addRow(response);
        document.getElementById("messages").innerHTML = "";
      }
      catch(err) {
        document.getElementById("messages").innerHTML = this.responseText;
      }
    }
  };

  xhttp.send(fd);
}

function addRow(data) {
  var table = document.getElementById("filesTable");
  var rows = table.rows.length;

  var row = table.insertRow();
  var cell = row.insertCell();
  cell.innerHTML = data['nume'];
  cell.className = "text_left";

  var cell = row.insertCell();
  cell.innerHTML = data['extensie'];

  var cell = row.insertCell();
  cell.innerHTML = data['dataModificare'];

  var cell = row.insertCell();
  cell.innerHTML = data['dimensiune'] + " KB";

  var cell = row.insertCell();
  cell.innerHTML = '<a href="' + data['link'] + '">Descarcă</a>';

  var cell = row.insertCell();
  cell.innerHTML = "<button type=\"button\" onclick=\"deleteFile('" + data['nume'] +  "', " + rows + ")\">X</button>";
}

function deleteFile(fileName, rowIndex) {
  var fd = new FormData();
  fd.append("fileToDelete", fileName);

  var xhttp = new XMLHttpRequest();
  xhttp.open("POST", "sterge.php", true);

  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      if(this.responseText == "0") {
        var table = document.getElementById("filesTable");
        table.deleteRow(rowIndex);
        console.log(table.rows);
      }
      else {
        document.getElementById("messages").innerHTML = this.responseText;
      }
    }
  };

  xhttp.send(fd);
}

function getCookie(cname) {
    var name = cname + "=";
    var decodedCookie = decodeURIComponent(document.cookie);
    var ca = decodedCookie.split(';');
    for(var i = 0; i <ca.length; i++) {
        var c = ca[i];
        while (c.charAt(0) == ' ') {
            c = c.substring(1);
        }
        if (c.indexOf(name) == 0) {
            return c.substring(name.length, c.length);
        }
    }
    return "";
}

function loadInfo() {
	var element = document.getElementById("nume");
	var nume = getCookie("utilizator");
	if(nume != "") {
		element.value = nume;
	}
	else {
		document.cookie = "utilizator=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";
	}
}

function changeUser() {
	var element = document.getElementById("nume");
  if(element.value != "") {
    document.cookie = "utilizator=" + element.value;
  }
  else {
    document.cookie = "utilizator=; expires=Thu, 01 Jan 1970 00:00:00 UTC; path=/;";
  }
	location.reload();
}