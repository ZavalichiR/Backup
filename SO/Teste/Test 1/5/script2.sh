#!/bin/bash
verificare()
{
	if [[ $# > 5 ]];then
		echo "Eroare!!"
		echo "Sintaxa corecta: ./$0 nr1 nr2 .. nr5"
		exit
	fi
}

compare()
{
	if [[ $1 < $2 ]];then 
		return 0
	elif [[ $1 > $2 ]];then
		return 1
	else
		return 2
	fi
}
verificare $*
read -p "Numarul pentru comparat: " nr

sir=""
for param in $*
do
	compare $nr $param
	if [[ $? == '0' ]];then
		sir=$sir$param" "
	fi
done
if [[ $sir == "" ]];then
	sir="Nu sunt"
fi
echo "Numerele mai mari decat $nr sunt : $sir "
