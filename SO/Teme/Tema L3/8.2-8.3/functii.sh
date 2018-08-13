#!/bin/bash

suma()
{
	echo "Suma este `expr $1 + $2 ` "
}

diferenta()
{
	echo $1-$2= $(( $1 - $2 ))
}

produs()
{
	echo $1*$2= $(( $1 * $2 ))

}

impartire()
{
		if [ $2 -eq 0 ] 

	 then
		echo "Impartirea nu are sens!"
		exit 1
	else
		echo $1/$2= $(( $1 / $2 ))
	fi
}

modulo()
{
	if [ $2 -eq 0 ]
	 then
		echo "Operatia modulo nu are sens!"
		exit 1
	else
		echo $1%$2= $(( $1 % $2 ))
	fi
}

