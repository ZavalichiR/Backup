#!/bin/bash
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
		source functii.sh
                meniu
		opt=0
		while [ $opt !=  5 ]; do
                read -p "opt=" opt
                case $opt in
                1) editor $1;;
                2) compilator $fisier $1 $erori;;
                3) erori $erori;;
                4) executie $fisier $erori;;
                5) exit;;
                *) echo "Optiune invalida!";;
                esac
		done
           
        fi
else
        echo "Parametrii au fost introdusi gresit. !"
fi

