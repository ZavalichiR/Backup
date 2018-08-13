#!/bin/bash
if [[ $# -ne 1 ]]
	then
	echo "Trebuie sa existe un singur argument"
	exit
elif [[ ! $1 == [0-9] ]]
	then
	echo "Argumentul trebuie sa fie numar intreg"
 	exit
else
	echo "Argumentul este corect"
fi

if [[ ! -f "./inc/hdr.h" ]]
	then
	echo "Fisierul header \"hdr.h\" nu a fost gasit!"
	exit
fi

if [[ ! -f "./inc/pv.h" ]]
	then
	echo "Fisierul header \"pv.h\" nu a fost gasit!"
	exit
fi

if [[ ! -f "./obj/err.o" ]]
	then
	echo "Fisierul obiect \"err.o\"! nu a fost gasit"
	exit
fi

if [[ ! -f "./src/philosopher.c" ]]
	then
	echo "Fisierul sursa \"philosopher.c\"! nu a fost gasit"
	exit
fi

echo -n "Fisierele header, obiect si sursa au fost gasite cu succes"

gcc src/philosopher.c -o bin/philosopher obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"philosopher.c\". Vezi fisierul \"error.log\"!"
	exit
fi

cd bin/
./philosopher $1
