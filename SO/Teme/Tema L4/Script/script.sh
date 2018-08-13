#!/bin/bash


help()
{
echo  "------------------------HELP-------------------------"
echo "./<nume_script> -h"
echo "./<nume_script> --help"
echo "./<nume_script> -p <nume_proiect>"
echo "./<nume_script> -p <nume_proiect> -n <numar intreg>"
echo "./<nume_script> -p <nume_proiect> -t <c/c++>"
echo "./<nume_script> -p <nume_proiect> -t <c/c++> -n <numar intreg>"

exit
}


Verificare()
{
	if [ $# -eq 0 ]; then
		echo "!!!!!!Nu ati introdus niciun argument!!!!!!"
		echo "Help:   ./script -h  sau  ./script --help "
		exit
	fi
	if [[ ($1 == '-h') || ($1 == '--help')]]; then
		help 
  	fi

	if [[ !($(($# % 2)) -eq 0) ]]; then #numarul argumentelor trebuie sa fie par
		echo "!!!!!!Numarul argumentelor este incorect!!!!!!"
		echo "Help:   ./script -h  sau  ./script --help "
		exit
	fi

	for (( i=1 ; i<=$# ; i++))
	do
		case $i in
			'1') if [[ $1 != '-p' ]]; then
				echo "!!!!! Primul argument a fost introdus gresit!!!!!"
				echo "Help:   ./script -h  sau  ./script --help"
				exit
			     fi;;
			'3') if [[ $3 == '-t' ]]; then
				if [[ !($4 == 'c') && !($4 == 'c++') ]]; then
					echo "!!!!!!Tipul programului a fost introdus gresit!!!!!"
					echo "Help   ./script -h  sau  ./script --help "
					exit
				fi
			     elif [[ $3 == '-n' ]]; then
				cmp1="$(echo $4 | sed 's/[^[:digit:]]//g')" #verifica daca este numar
				if [[ "$4" != "$cmp1" ]]; then
					echo "!!!!! Numarul de fisiere este eronat !!!!! "
					echo "Help:   ./script -h  sau  ./script --help "
					exit
				fi
			     else
				echo "!!!!! Argumentele au fost introdus gresit !!!!! "
				echo "Help:   ./script -h  sau  ./script --help "
				exit
			     fi;;
			'5') if [[ $5 == '-n' ]]; then
                                cmp2="$(echo $6 | sed 's/[^[:digit:]]//g')"                              
				 if [[ "$6" != "$cmp2" ]]; then
					echo "!!!!! Numarul de fisiere este eronat !!!!!"
                                        echo "Help:   ./script -h  sau  ./script --help"
					exit
                                fi
			     fi;;
		esac
	done
}

makeProject()
{
	mkdir $1
	cd $1
	mkdir bin obj src inc
	touch "$1$2"
	touch "$1.h"
	touch "build.sh"
	chmod +x build.sh
	chmod +w build.sh

	if [[ $3 != '0' ]];then
		
		for (( i=1 ; i<=$3 ; i++ ))
		do
			touch "inc/fisier$i.h"
		done	
	
		for (( i=1 ; i<=$3 ; i++ ))
		do
			touch "src/fisier$i$2"
			case $2 in
				'.c')echo "gcc -c src/fisier$i$2" >> build.sh;;
				'.cpp')echo "g++ -c src/fisier$i$2" >> build.sh;;
				*)echo " Tipul nu este c sau cpp "; exit;;
			esac

			
		done

			case $2 in
				'.c')echo "gcc $1$2 fisier*.o -o $1" >> build.sh;;
				'.cpp')echo "g++ $1$2 fisier*.o -o $1" >>  build.sh;;
				*)echo " Tipul nu este c sau cpp "; exit;;
			esac


	fi
}

DetaliiP()
{
	echo "Nume proiect: $1"
	echo "Tip proiect: $2"
	echo "Numar de fisiere: $3"
}


Verificare $*

nume="$2"
tip=".c"
nrfis="1"
if [[ $3 == '-t' ]]; then
	if [[ $4 == 'c++' ]]; then 
		tip=".cpp"
	fi
	if [[ $5 == '-n' ]]; then
		nrfis=$6
	fi
else
	if [[ $3 == '-n' ]]; then
		nrfis="$4"
	fi
fi

DetaliiP $nume $tip $nrfis
makeProject $nume $tip $nrfis


echo "mv fisier*.o obj" >> build.sh
echo "mv $nume bin" >> build.sh
