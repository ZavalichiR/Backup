mesaje()
{	echo "---------------Pentru comanda dorita apasati tasta: "
	echo "+ pentru adunare"
	echo "- pentru scadere"
	echo "* pentru inmultire"
	echo "/ pentru impartire"
	echo "% pentru returnarea restului"
}
hexatodeci()
{	
	echo "Numarul $1 din baza 16 in baza 10"
        echo "ibase=16; $1"|bc;
}
decitohexa()
{
	echo "Numarul $1 din baza 10 in baza 16"
	echo "obase=16; $1"|bc;
}

rel=1
while [ $rel -eq 1 ]; do
if [ $# -eq 2 ]; then
	if [ -f functii.sh ]
	 then
	 source functii.sh
	mesaje
	read -p "opt: " opt
	case $opt in
		'+') suma $1 $2;;
		'-') diferenta $1 $2;;
		'*') produs $1 $2;;	
		'/') impartire $1 $2;;
		'%') modulo $1 $2;;
		*) echo "Operatie invalida!"
		   exit;;
	esac
	else
		echo "Fisierul functii nu exista"
	fi
elif [ $# -eq 1 ]; then
	echo "Alegeti transformarea:"
	echo "1 Hexa to Deci;2 Deci to Hexa; 3 Both"
	read -p "R: " r
	case $r in
		'1') hexatodeci $1;;
		'2') decitohexa $1;;
		'3') hexatodeci $1;  decitohexa $1;;
		*) echo "Alegeti 1,2,sau 3"
		   exit;;
	esac 
else
	echo "Argumentele trebuie sa fie in numar de doua!"
fi
echo "Reluati programul?"
read -p "1 DA ||||  0 NU |||| Raspuns: " rel
done

exit 0
