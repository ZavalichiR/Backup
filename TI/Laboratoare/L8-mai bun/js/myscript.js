function aduna(){
	var a=document.getElementById("x1").value;
	var b=document.getElementById("x2").value;
	var c=parseInt(a)+parseInt(b);
	document.getElementById("rez").innerHTML=c;
}

function ShowDate(){
	var d = new Date();
	document.getElementById("Section1_Date").innerHTML = "<b>Data</b>: "+d;
	setTimeout("ShowDate()","1000");
}

function ShowURL(){
	var x=location.href;
	document.getElementById("Section1_URL").innerHTML = "<b>Adresa URL</b>: "+x;
}

function ShowBrowserInfo(){
	var x = "Browser Name: " + navigator.appName;
	var y = "Version Info: " + navigator.appVersion;
	document.getElementById("Section1_BrowserInfo").innerHTML = "<b>Nume Browser</b>: "+x+"<br><b>Versiune Browser</b>: "+y;
}

function ShowSO(){
	var OSName="Unknown OS";
	if (navigator.appVersion.indexOf("Win")!=-1)
	{
		OSName="Windows";
	}
	if (navigator.appVersion.indexOf("Mac")!=-1){
		OSName="MacOS";
	}
	if (navigator.appVersion.indexOf("X11")!=-1)
	{
		OSName="UNIX";
	}
	if (navigator.appVersion.indexOf("Linux")!=-1)
	{
		OSName="Linux";
	}
	document.getElementById("Section1_SO").innerHTML = "<b>Sistem de operare</b>: "+OSName;
}

function loto(){
	var arr =[100,0];
	while(arr.length < 8)
	{
		var randomnumber = Math.floor(Math.random() * 256);
		arr[arr.length] = randomnumber;
	}
	for (i = 0; i < arr.length; i++)
	{ 
		arr[i]=arr[i].toString(16).toUpperCase();
	}
	document.getElementById("LOTOrez").value =arr;
	
	var matches=0;
	for(i=0;i<8;i++)
	{
		var object=document.getElementById("LOTO"+(i+1));
		object.style.backgroundColor="red";
		for(j=0;j<8;++j)
		{
			if(document.getElementById("LOTO"+(i+1)).value == arr[j])
			{
				matches++;
				object.style.backgroundColor="green";
			}
		}
	}
	document.getElementById("LOTOmatches").innerHTML="Ati nimerit "+matches+" numere!";
}

function LOTOclearAll(){
	for(i=0;i<8;i++)
	{
		var object=document.getElementById("LOTO"+(i+1));
		object.value="";
		object.style.backgroundColor="white";
		var object=document.getElementById("LOTOrez");
		object.value="";
	}
}











