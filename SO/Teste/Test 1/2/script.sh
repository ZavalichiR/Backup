#!/bin/bash
#!/bin/bash

opereaza()
{
	case $# in
		2 ) return $(($1*$2));;
		3 ) return $(($1*$2+$3));;
		4 ) return $(($1*$2+$3*$4));;
		* ) echo "Eroare! Numar incorect de parametri!"
			exit 1;;
	esac
}


opereaza $*

echo "Rezultatul operatiei matematice este "$?"."
