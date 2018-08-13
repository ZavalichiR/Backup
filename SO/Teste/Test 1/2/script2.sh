#!/bin/bash
verificare()
{
	if [[ ($# < 2) || ($# > 4) ]];then
		echo "Eroare!! Numarul parametrilor trebuie sa fie cuprins in intervalul [2,4] "
		exit
	fi
	for i in $*
	do
	#	cmp="$(echo $i | sed 's/[^[:digit:]]//g')"
	#	if [[ "$cmp" != "$i" ]];then
		cmp="$(echo $i | sed 's/[^[:digit:]]//g')"
		if [[ $cmp != $i ]];then
		#if [[ ! $i =~ ^-?[0-9]+$ ]];then # ^-?[0-9]+$ permite si numerele negetuve
		#if [[ $i == [^0-9] ]];then
		#if [[ ! $i == [0-9] ]];then 
			echo "Parametrii trebuie sa fie cifre"
			exit
		fi
	done
}
f()
{
	verificare $*
	case $# in
		2)echo "$(( $1 * $2)) ";;
	
		3)echo "$(( $1 *$2 + $3 )) ";;
	
		4)echo "$(( $1 * $2 + $3 * $4)) ";;
		
	esac
}

f $*
