/*
 * caracter.c
 *
 *  Created on: Mar 20, 2015
 *      Author: student
 */
#include "caracter.h"
int nr_aparitii(int c, char sir[]) //contorizeaza numarul de aparitii al caracterului c in sirul "sir"
{
	int nr_ap, i;
	nr_ap=0; //pornim cu numarul de aparitii de la 0
	i=0; //i=pozitia curenta in sir (sirul de caractere se comporta exact ca un vector de caractere, adica indexarea se face de la 0 la numarul de pozitii-1 = strlen(sir)-1)
	while (sir[i]!='\0') //parcurgerea nu o facem pana la strlen(sir)-1 pentru ca putem parcurge sirul pana la intalnirea caracterului '\0', adica "sfarsit de sir", fara a mai apela functia strlen(), care necesita timp de executie
	{
		if (sir[i]==c) //verificam egalitatea caracterului curent cu caracterul cautat
			++nr_ap; //daca sunt egale, incrementam numarul de aparitii
		++i; //trecem la pozitia caracterului urmator din sirul s
	}
	return nr_ap;
}
