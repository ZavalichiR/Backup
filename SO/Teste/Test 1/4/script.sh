#!/bin/bash
verificare()
{
	if [[ -d $1 ]];then
		return 0
	elif [[ -f $1 ]];then
		return 1
	else
		return 2
	fi
}
verificare $1
ret=$?
echo "$ret"
if [[ $ret == 0 ]];then
	echo "Director existent"
	exit
elif [[ $ret == 1 ]];then
	echo "Fisier existent"
	exit
fi

if [[ ($# -lt 1) || ($# -gt 9) ]];then
	echo "Numarul parametrilor este incorect"
	exit
fi
mkdir $1
for index in $*
do
	if [[ $index == $1 ]];then
		continue
	fi
	touch "$1"/"$index"
done
