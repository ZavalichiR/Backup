#!/bin/bash
source script.sh #include scriptul cu functii

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



