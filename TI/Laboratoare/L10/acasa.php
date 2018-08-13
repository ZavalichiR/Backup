
<?php
	if (isset($_GET['nume']) && !empty($_GET['nume']))
	{
		echo "<span style='color: green;'>Bun venit, ".$_GET['nume']."!</span>";
	}
?>

<main>
	<form action="index.php?sectiune=acasa">
		<input type="hidden" name="acasa"/>
		Nume: <input type="text" name="nume" maxlength="30" size="30" />
		<input type="submit" value="->" />
	</form>
</main>