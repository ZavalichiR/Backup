#!/bin/bash
if [[ ! -f "./inc/hdr.h" ]]
	then
	echo "Nu exista fisierul header \"hdr.h\"!"
	exit 1
fi

if [[ ! -f "./inc/mes.h" ]]
	then
	echo "Nu exista fisierul header \"mes.h\"!"
	exit 2
fi

if [[ ! -f "./obj/err.o" ]]
	then
	echo "Nu exista fisierul obiect \"err.o\"!"
	exit 3
fi

if [[ ! -f "./src/writer.c" ]]
	then
	echo "Nu exista fisierul sursa \"writer.c\"!"
	exit 4
fi

if [[ ! -f "./src/reader.c" ]]
	then
	echo "Nu exista fisierul sursa \"reader.c\"!"
	exit 5
fi

if [[ ! -f "./src/controller.c" ]]
	then
	echo "Nu exista fisierul sursa \"controller.c\"!"
	exit 6
fi

if [[ ! -f "./src/mesaj.c" ]]
	then
	echo "Nu exista fisierul sursa \"mesaj.c\"!"
	exit 7
fi

echo -n "Se compileaza fisierele sursa..."

gcc -o bin/writer src/writer.c src/mesaj.c obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"writer.c\". Vezi fisierul \"error.log\"!"
	exit 8
fi

gcc -o bin/reader src/reader.c src/mesaj.c obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"reader.c\". Vezi fisierul \"error.log\"!"
	exit 9
fi

gcc -o bin/controller src/controller.c src/mesaj.c obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"controller.c\". Vezi fisierul \"error.log\"!"
	exit 10
fi

gcc -o bin/del src/del.c src/mesaj.c obj/err.o 2> error.log
if [[ $? -ne 0 ]]
	then
	echo -e "\nAu aparut erori la compilarea fisierului \"del.c\". Vezi fisierul \"error.log\"!"
	exit 11
fi

echo "OK"

echo -e "\nExecutie problema cititor-scriitor:\n"

cd bin/
#executia problemei cititor-scriitor
./controller &
for i in 1 2 3 4; do (./writer &); done
for I in 1 2 3; do (./reader &); done
