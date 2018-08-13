#!/bin/bash

meniu()
{	echo "----------MENIU----------"
	echo "[1] Editor!"
	echo "[2] Compilator!"
	echo "[3] Erori!"
	echo "[4] Executie!"
	echo "[5] EXIT!"
}

editor()
{
	vi $1
}

compilator()
{
	if [ -f $1 ]; then
		rm $1
	fi
	if [ -f $3 ]; then
		rm $3
	fi
	
	case $2 in
	*.c)gcc -o $1 $2 >&$3; echo "Fisierul $1 $2 a fost complilat";;
	*.cpp)g++ -o $1 $2 >&$3; echo "Fisierul $1 $2 a fost compilat";;	
	esac
}

erori()
{
	if [ -s $1 ]; then
		echo "Exista erori! Erorile au fost puse in fisierul $1"
		cat $1
	else
		echo "Nu exista erori!"
	fi
}

executie()
{
	if [[ !(-f $1) ]]; then
		echo "Nu exista fisier executabil!"
	elif [ -s $2 ]; then
		echo "Exista erori!"
	else
		./$1
	fi
}





if [ $# -eq 1 ]; then
	
	case $1 in
	*.c)fisier=`basename $1 .c`;;
	*.cpp)fisier=`basename $1 .cpp`;;
	*) echo "Extensia nu este .c sau .cpp";;
	esac	
	erori="$fisier.err"
	if [[ !(-f $1) ]]; then
		echo "Fisierul nu exista!"
	else
		meniu
		read -p "opt=" opt

		case $opt in
		1) editor $1;;
		2) compilator $fisier $1 $erori;;
		3) erori $erori;;
		4) executie $fisier $erori;;
		5) exit;;
		*) echo "Optiune invalida!";;
		esac

		sh $0 $1	
	fi
else
	echo "Parametrii au fost introdusi incorect. ./script.sh program.c !"
fi

