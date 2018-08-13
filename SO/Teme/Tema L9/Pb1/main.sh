#!/bin/bash
if [[ ! -f "./inc/hdr.h" ]]
	then
	echo "Fisierul header \"hdr.h\" nu a fost gasit!"
	exit
fi

if [[ ! -f "./inc/pcsem.h" ]]
	then
	echo "Fisierul header \"pcsem.h$\" nu a fost gasit!"
	exit
fi

if [[ ! -f "./obj/err.o" ]]
	then
	echo "Fisierul obiect \"err.o\" nu a fost gasit!"
	exit
fi

if [[ ! -f "./src/init.c" ]]
	then
	echo "Fisierul sursa \"init.c\" nu a fost gasit!"
	exit
fi

if [[ ! -f "./src/prod.c" ]]
	then
	echo "Fisierul sursa \"prod.c\" nu a fost gasit!"
	exit
fi

if [[ ! -f "./src/cons.c" ]]
	then
	echo "Fisierul  sursa \"cons.c\" nu a fost gasit!"
	exit
fi

if [[ ! -f "./src/del.c" ]]
	then
	echo "Fsisierul sursa \"del.c\" nu a fost gasit!"
	exit
fi

echo -n "Fisierele sursa, header si obiect au fost gasite cu succes"

gcc src/prod.c -o bin/prod obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"prod.c\". Vezi fisierul \"error.log\"!"
	exit 8
fi

gcc src/cons.c -o bin/cons obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"cons.c\". Vezi fisierul \"error.log\"!"
	exit 9
fi

gcc src/init.c -o bin/init obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"init.c\". Vezi fisierul \"error.log\"!"
	exit 10
fi

gcc src/del.c -o bin/del obj/err.o 2>error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"del.c\". Vezi fisierul \"error.log\"!"
	exit 11
fi



echo -e "\nProducator-Consumator:\n"

cd bin/

#initializarea semafoarelor si a zonei de memorie comuna:
./init
#lansarea a 3 procese producator si a 2 consumator
./prod & ./prod & ./cons & ./cons & ./prod
#stergerea zonei comune de memorie si a setului de semafoare
./del
