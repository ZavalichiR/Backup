#!/bin/bash

if [[ !($# == '2') ]]
	then
	echo "Numar incorect de parametri."
	exit
fi


if [[ ! $1 =~ ^-?[0-9]+$ ]]
	then
	echo "Primul parametru trebuie sa fie numar!"
	exit
fi
verificare()
{
	if [[ -d $1 ]]
		then
		return 0
	elif [[ -f $1 ]]
		then
		return 1
	else
		return 2
	fi
}

cd $HOME
verificare $2
rezultat=$?
echo "$rezultat"

if [[ $rezultat == '0' ]];then #sau $rezultat -eq 0
	echo "Directorul exista deja!"
	exit 
elif [[ $rezultat == '1' ]];then  #sau $rezultat -eq 1
	echo "Fisierul exista deja!"
	exit 
fi

mkdir $2
cd $2
i=0
while (( i <= $1 ))
do
	echo "Se creeaza fisier-"$i".text"
	touch "fisier-$i.text"
	i=$(($i+1))
done
#sau 

#for (( i=1; i<=$1;i++ ))
#do
#	echo "Se creeaza fisierul fisier-"$i".text "
#	touch "fisier-$i.text"
#done

echo "Directorul $2 si $(($i-1)) fisiere au fost create!"
