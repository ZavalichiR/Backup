#!/bin/bash

scrie()
{
	echo "host $1 { "
	echo "   option host-name \"$1\";" # Am folosit \ pentru a putea scrie ghilimele "
	echo -ne "   hardware ethernet "   # Nu se pune newline dupa afisare
	echo $2 | tr [:lower:] [:upper:]   # Afiseaza literele mari
	echo "   fixed-address $3;"
}

verificare()
{
	if [[ ! -f $1 ]];then
		echo "Fisierul de intrare nu exista"
		exit
	elif [[ ! -f $2 ]];then
		echo "Fisierul de iesire nu exista"
		exit
	fi
}

verificare $1 $2
IFS="," # pentru citire se foloseste delimitatorul ,
var="1"
while read ip mac nume comentarii
do
	echo "Procesare: linia $var  datele: $ip $mac $nume $comentarii"
	var=$(($var+1))
	mac2=`echo $mac | sed 's/\(\w\w\)\(\w\w\)\(\w\w\)\(\w\w\)\(\w\w\)\(\w\w\)/\1:\2:\3:\4:\5:\6/g'` # pune : dupa 2 caractere
	
	scrie $nume $mac2 $ip >>$2
done <$1  #fisierul din care se citeste
