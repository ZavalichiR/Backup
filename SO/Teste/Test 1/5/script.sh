#!/bin/bash
echo "$#"
if [[ $# > '5' ]];then
	echo "Numar incorect de parametri: sintaxa ./"$0" <nr1> <nr2? ... <nr5> "
	exit
fi
 compare ()
{
	if [[ $1 -lt $2 ]];then
		return 0
	elif [[ $1 -eq $2 ]];then
		return 1
	else
		return 2
	fi
}

read -p "Introduceti un numar: " x
nrmari="" #vector de numere
for parametru in $*
do
	if [[ ! $parametru =~ ^-?[0-9]+$ ]];then
		echo " Parametrii trebuie sa fie numere"
		exit
	fi
	compare $x $parametru
	rez=$?
	if [[ $rez == '0' ]];then
		nrmari=$nrmari$parametru" " # " "- pune spatiu intre numere
	fi
done
echo " Numerele mai mari ca "$x" sunt: "$nrmari" "
