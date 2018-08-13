#!/bin/bash
cd $HOME
verificare()
{	
	if [[ ! $1 =~ ^-?[0-9]+$ ]];then # mai sunt si celelalte 2-3 metode
		echo "primul parametru trebuie sa fie numar"
		exit
	fi
	
	if [[ -d $2 ]];then
		return 1
	elif [[ -f $2 ]];then
		return 1;
	else
		return 2
	fi
}
verificare $1 $2

ret=$?

if [[ $ret == '0' ]];then
	echo "Director existent!!!"
	exit
elif [[ $ret == '1' ]];then
	echo "Fisier existet"
	exit
else
	pwd
	mkdir $2
fi

creare()
{
	cd $2
	#for (( i= 1; i <= $1;++i ))
	for i in `seq 1 $1` #proful prefera pe asta
	do
		touch "fisier-$i.txt"
	done
}

creare $1 $2
echo " Direcoturl si fisierele au fost create in $HOME"
