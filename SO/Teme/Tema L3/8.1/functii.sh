#!/bin/bash
meniu()
{       echo "----------MENIU----------"
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
        *.c)gcc -o $1 $2 >&$3; echo "Fisierul  $2 a fost complilat cu succes";;
        *.cpp)g++ -o $1 $2 >&$3; echo "Fisierul  $2 a fost compilat cu succes";;
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

