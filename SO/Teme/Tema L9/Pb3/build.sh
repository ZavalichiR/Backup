#!/bin/bash
if [[ ! -f "./inc/hdr.h" ]]
	then
	echo "Nu exista fisierul header \"hdr.h\"!"
	exit 1
fi

if [[ ! -f "./inc/pv.h" ]]
	then
	echo "Nu exista fisierul header \"pv.h\"!"
	exit 2
fi

if [[ ! -f "./obj/err.o" ]]
	then
	echo "Nu exista fisierul obiect \"err.o\"!"
	exit 3
fi

if [[ ! -f "./src/barbier.c" ]]
	then
	echo "Nu exista fisierul sursa \"barbier.c\"!"
	exit 4
fi

echo -n "Se compileaza fisierele sursa..."

gcc -o bin/barbier src/barbier.c obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"barbier.c\". Vezi fisierul \"error.log\"!"
	exit 5
fi

echo "OK"

echo -e "\nExecutie problema barbierului:\n"

read -p "Introduceti numarul de scaune: " nrScaune
read -p "Introduceti numarul de clienti: " nrClienti
echo

cd bin/
#executia problemei barbierului
./barbier $nrScaune $nrClienti