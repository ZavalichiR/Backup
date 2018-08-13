var x=new Array(2);
var y=new Array(2);
var v=0;

function date(){
	var data=new Date();
	document.getElementById("date").innerHTML="Data: "+ data;
	setTimeout("date()","1000");
	document.getElementById("sistem").innerHTML="Sistem Operare: "+navigator.platform;
	document.getElementById("url").innerHTML="Adresa: "+ window.location.href;
	document.getElementById("browser").innerHTML="Versiune Browser: "+navigator.appVersion;
	document.getElementById("nume").innerHTML="Nume Browser: "+navigator.appName;
	
	}	

function loto() {
	var nr=0;
	var i;
	for(i=0;i<8;i++)
	{
		var c=Math.random()*20;
		var a=parseInt(c);
		var b=a.toString(16);
		document.getElementById("n"+i).innerHTML=b+"|";
		if(b==document.getElementById("v1").value || b==document.getElementById("v2").value|| b==document.getElementById("v3").value || b==document.getElementById("v4").value||b==document.getElementById("v5").value || b==document.getElementById("v6").value||b==document.getElementById("v7").value || b==document.getElementById("v8").value)
		{
			console.log("da");
			nr++;
		}
		else
			console.log("nu");
	}
	if(nr==0)
		document.getElementById("rezultat").innerHTML=nr + " numere";
	else if(nr==1)
		document.getElementById("rezultat").innerHTML=nr+ " număr";
	else
		document.getElementById("rezultat").innerHTML=nr + " numere";
}


function Draw(event){
	
	var desen=document.getElementById("desen");
	
	var ctx=desen.getContext("2d");
	
	var culoare1=document.getElementById("contur").value;
	var culoare2=document.getElementById("umplere").value;
	
	if(v==0){
		x[0]=event.offsetX;
		y[0]=event.offsetY;
		v++;
	}
	else {
		if(v==1){
			x[1]=event.offsetX;
			y[1]=event.offsetY;
			var x1=x[1]-x[0];
			var y1=y[1]-y[0];
			ctx.fillRect(x[0],y[0],x1,y1);
			ctx.fillStyle=culoare2;
			ctx.strokeRect(x[0],y[0],x1,y1);
			ctx.strokeStyle=culoare1;
			v=0;
		}
	}
	
}


function GenLinie(){
	var tabel=document.getElementById("tabel");
	var pozitie=document.getElementById("poz").value;
	var culoare=document.getElementById("culoare").value;
	var border=document.getElementById("border").value;
	var nr_R=tabel.rows.length;
	
	if(pozitie<nr_R || pozitie>nr_R){
		alert("Rand invalid!");
	}
	else{
		var nr_C=tabel.rows[0].cells.length;
		var row=tabel.insertRow(pozitie);
		
		for(var i=0;i<nr_C;i++){
			var cell=row.insertCell(i);
			cell.style.backgroundColor=culoare;
			cell.style.borderColor=border;
		}
	}
}
function GenColoana(){
	
	var tabel=document.getElementById("tabel");
	var pozitie=document.getElementById("poz").value;
	var culoare=document.getElementById("culoare").value;
	var border=document.getElementById("border").value;
	var nr_R=tabel.rows.length;
	var nr_C=tabel.rows[0].cells.length;
	
	if(pozitie<nr_C || pozitie>nr_C){
		alert("Coloana invalida!");
	}
	else{		
		for(var i=0;i<nr_R;i++){
			var row=tabel.rows[i];
			var cell=row.insertCell(pozitie);
			cell.style.backgroundColor=culoare;
			cell.style.borderColor=border;
		}
	}
}


function Calculator()
{
	// Get all the keys from document
	var keys = document.querySelectorAll('#calculator span');
	var operators = ['+', '-', 'x', '÷'];
	var decimalAdded = false;

	// Add onclick event to all the keys and perform operations
	for(var i = 0; i < keys.length; i++) {
		keys[i].onclick = function(e) {
			// Get the input and button values
			var input = document.querySelector('.screen');
			var inputVal = input.innerHTML;
			var btnVal = this.innerHTML;
			
			// Now, just append the key values (btnValue) to the input string and finally use javascript's eval function to get the result
			// If clear key is pressed, erase everything
			if(btnVal == 'C') {
				input.innerHTML = '';
				decimalAdded = false;
			}
			
			// If eval key is pressed, calculate and display the result
			else if(btnVal == '=') {
				var equation = inputVal;
				var lastChar = equation[equation.length - 1];
				
				// Replace all instances of x and ÷ with * and / respectively. This can be done easily using regex and the 'g' tag which will replace all instances of the matched character/substring
				equation = equation.replace(/x/g, '*').replace(/÷/g, '/');
				
				// Final thing left to do is checking the last character of the equation. If it's an operator or a decimal, remove it
				if(operators.indexOf(lastChar) > -1 || lastChar == '.')
					equation = equation.replace(/.$/, '');
				
				if(equation)
					input.innerHTML = eval(equation);
					
				decimalAdded = false;
			}
			
			// Basic functionality of the calculator is complete. But there are some problems like 
			// 1. No two operators should be added consecutively.
			// 2. The equation shouldn't start from an operator except minus
			// 3. not more than 1 decimal should be there in a number
			
			// We'll fix these issues using some simple checks
			
			// indexOf works only in IE9+
			else if(operators.indexOf(btnVal) > -1) {
				// Operator is clicked
				// Get the last character from the equation
				var lastChar = inputVal[inputVal.length - 1];
				
				// Only add operator if input is not empty and there is no operator at the last
				if(inputVal != '' && operators.indexOf(lastChar) == -1) 
					input.innerHTML += btnVal;
				
				// Allow minus if the string is empty
				else if(inputVal == '' && btnVal == '-') 
					input.innerHTML += btnVal;
				
				// Replace the last operator (if exists) with the newly pressed operator
				if(operators.indexOf(lastChar) > -1 && inputVal.length > 1) {
					// Here, '.' matches any character while $ denotes the end of string, so anything (will be an operator in this case) at the end of string will get replaced by new operator
					input.innerHTML = inputVal.replace(/.$/, btnVal);
				}
				
				decimalAdded =false;
			}
			
			// Now only the decimal problem is left. We can solve it easily using a flag 'decimalAdded' which we'll set once the decimal is added and prevent more decimals to be added once it's set. It will be reset when an operator, eval or clear key is pressed.
			else if(btnVal == '.') {
				if(!decimalAdded) {
					input.innerHTML += btnVal;
					decimalAdded = true;
				}
			}
			
			// if any other key is pressed, just append it
			else {
				input.innerHTML += btnVal;
			}
			
			// prevent page jumps
			e.preventDefault();
		} 
	}
}