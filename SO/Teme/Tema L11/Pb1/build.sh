#!/bin/bash
if [[ ! -f "./inc/hdr.h" ]]
	then
	echo "Nu exista fisierul header \"hdr.h\"!"
	exit 1
fi

if [[ ! -f "./inc/mesaj.h" ]]
	then
	echo "Nu exista fisierul header \"mesaj.h\"!"
	exit 2
fi

if [[ ! -f "./obj/err.o" ]]
	then
	echo "Nu exista fisierul obiect \"err.o\"!"
	exit 3
fi

if [[ ! -f "./src/prod.c" ]]
	then
	echo "Nu exista fisierul sursa \"prod.c\"!"
	exit 4
fi

if [[ ! -f "./src/cons.c" ]]
	then
	echo "Nu exista fisierul sursa \"cons.c\"!"
	exit 5
fi

if [[ ! -f "./src/main.c" ]]
	then
	echo "Nu exista fisierul sursa \"main.c\"!"
	exit 6
fi

echo -n "Se compileaza fisierele sursa..."

gcc -o bin/prod src/prod.c obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"prod.c\". Vezi fisierul \"error.log\"!"
	exit 7
fi

gcc -o bin/cons src/cons.c obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"cons.c\". Vezi fisierul \"error.log\"!"
	exit 8
fi

gcc -o bin/main src/main.c obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"main.c\". Vezi fisierul \"error.log\"!"
	exit 9
fi

gcc -o bin/del src/del.c obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"del.c\". Vezi fisierul \"error.log\"!"
	exit 10
fi

echo "OK"

echo -e "\nExecutie problema producator-consumator:\n"

cd bin/
#executia problemei producator-consumator
./main