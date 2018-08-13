function schimba(){
	var e=document.getElementById("nume");
	if(e.value!="")
	{
		document.cookie="utilizator="+e.value;
	}
	else
	{
		document.cookie = "utilizator=; expires=Thu, 01 Jan 1970 00:00:00 UTC;";
	}
	//location.reload();
}