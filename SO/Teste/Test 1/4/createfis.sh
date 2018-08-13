#!/bin/bash
if [[ ($# < '1') || ($# > '9') ]];then
	echo "Numarul argumentelor este gresit"
	exit
fi
ls
verificare ()
{	if [[ -d $1 ]];then
		return 0
	elif [[ -f $1 ]];then
		return 1
	else
		return 2
	fi

}
verificare $1
rez=$?
echo "$rez"
if [[ $rez == '0' ]];then
	echo " Exista deja un director cu acest nume "
	exit
elif [[ $rez == '1' ]];then
	echo "Exista deja un fisier cu acest nume"
	exit
fi
mkdir $1
cd $1
for parametru in $* #parcurge lista de argumente
do	if [[ $parametru == $1 ]];then #evitam sa creem un fisier cu acelsi nume ca al directorului
		continue
	fi
	touch $parametru
done
