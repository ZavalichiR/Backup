#!/bin/bash

verificare()
{
	if [[ -d $1 ]]; then
		return 0;
	elif [[ -f $1 ]];then
		return 1;
	else
		return 2;
	fi
# pentru a afisa valoarea returnata se executa scriptul si se scrie echo $?
}
verificare $1 # se apeleaza functia de verificare
rezultatTest=$? # se salveaza intr-o variabila ce a returnat ultima functie apelata :in acest caz functia este ce de testare (verificare)
echo "Functia returneaza $rezultatTest "
if [[ $rezultatTest -eq 0 ]]; then

	echo "Eroare! Parametrul dat este director"
	exit 1
elif [[ $rezultatTest -eq 1 ]];then

	echo "Parametrul dat este fisier de tip text" 
	if [[ -s $1 ]]; then

		echo "Fisierul are continut"
	else

		echo "Fisierl este gol"
		exit 1
	fi

	nrL=`wc -l <$1`
	echo "Fisierul $1 are  $nrL linii"
	echo "------Continutul fisierului-----"
	#cat $1 | tr [:lower:] [:upper:] # lower to upper
	cat $1 | tr [:upper:] [:lower:]  # upper to lower
	exit 1
else

	echo "Parametrul este de alt tip"
	
fi
echo "Rezultat teste= $rezultatTest "
