<?php
	$DATE_TEST = array('intrebare1' => array('Which of the following type of class allows only one object of it to be created?', 'c'),
						'intrebare2' => array('Which of the following is not a type of constructor?', 'b'),
						'intrebare3' => array('Which of the following statements is correct?', 'b'),
						'intrebare4' => array('Which of the following is not the member of class?', 'b'),
						'intrebare5' => array('Which of the following concepts means determining at runtime what method to invoke?', 'c')
				);

	if (isset($_GET['raspuns1']) && isset($_GET['raspuns2']) && isset($_GET['raspuns3']) && isset($_GET['raspuns4']) && isset($_GET['raspuns5']))
	{
		$nrRaspunsuriCorecte = 0;
		for ($i = 1; $i <= 5; ++$i)
		{
			if ($_GET['raspuns'.$i] == $DATE_TEST['intrebare'.$i][1])
			{
				++$nrRaspunsuriCorecte;
			}
		}

		if ($nrRaspunsuriCorecte == 0)
		{
			$mesaj = "<span style='color: red; font-size: 1.2em;'>Din păcate, nu ai dat niciun răspuns corect.</span>";
		}
		else
		{
			$mesaj = "<span style='color: green; font-size: 1.2em;'>Felicitări! Ai dat <b>".$nrRaspunsuriCorecte."</b> răspunsuri corecte!</span>";
		}
		$afisareRaspunsuriCorecte = "font-weight: bold; font-style: italic;";
	}
	else
	{
		$afisareRaspunsuriCorecte = "";
	}
?>

<h2>Testează-ți cunoștințele de șofer auto experimentat, cu acest mic test de cultură generală</h2>

<?php
	if (isset($_GET['raspuns1']) && isset($_GET['raspuns2']) && isset($_GET['raspuns3']) && isset($_GET['raspuns4']) && isset($_GET['raspuns5']))
	{
		echo $mesaj;
	}
?>

<form action="<?php echo $_SERVER['PHP_SELF'];?>" method="get">
	<fieldset>
		<legend>Întrebarea 1</legend>
		<label><?php echo $DATE_TEST['intrebare1'][0];?></label> <br />
			<input type="radio" name="raspuns1" value="a" required /> Virtual class <br />
			<input type="radio" name="raspuns1" value="b" /> Abstract class <br />
			<input type="radio" name="raspuns1" value="c" /> Singleton class</span> <br />
			<input type="radio" name="raspuns1" value="d" /> Friend class
	</fieldset>
	<br />
	<fieldset>
		<legend>Întrebarea 2</legend>
		<label><?php echo $DATE_TEST['intrebare2'][0];?></label> <br />
			<input type="radio" name="raspuns2" value="a" required/> Copy constructor<br />
			<input type="radio" name="raspuns2" value="b" /> Friend constructor <br />
			<input type="radio" name="raspuns2" value="c" /> Default constructor </span><br />
			<input type="radio" name="raspuns2" value="d" /> Parameterized constructor
	</fieldset>
	<br />
	<fieldset>
		<legend>Întrebarea 3</legend>
		<label><?php echo $DATE_TEST['intrebare3'][0];?></label> <br />
			<input type="radio" name="raspuns3" value="a" required/> Base class pointer cannot point to derived class. <br />
			<input type="radio" name="raspuns3" value="b" /> Derived class pointer cannot point to base class.	 <br />
			<input type="radio" name="raspuns3" value="c" /> Pointer to derived class cannot be created. </span><br />
			<input type="radio" name="raspuns3" value="d" /> Pointer to base class cannot be created.
	</fieldset>
	<br />
	<fieldset>
		<legend>Întrebarea 4</legend>
		<label><?php echo $DATE_TEST['intrebare4'][0];?></label> <br />
			<input type="radio" name="raspuns4" value="a" required/> Static function  <br />
			<input type="radio" name="raspuns4" value="b" /> Friend function </span><br />
			<input type="radio" name="raspuns4" value="c" /> Const function <br />
			<input type="radio" name="raspuns4" value="d" /> Virtual function
	</fieldset>
	<br />
	<fieldset>
		<legend>Întrebarea 5</legend>
		<label><?php echo $DATE_TEST['intrebare5'][0];?></label> <br />
			<input type="radio" name="raspuns5" value="a" required/> Data hiding <br />
			<input type="radio" name="raspuns5" value="b" /> Dynamic Typing <br />
			<input type="radio" name="raspuns5" value="c" /> Dynamic binding <br />
			<input type="radio" name="raspuns5" value="d" /> Dynamic loading </span>
	</fieldset>
	<input type="hidden" name="sectiune" value="Test" />
	<br />
	<input type="submit" value="Rezultat" />
</form>