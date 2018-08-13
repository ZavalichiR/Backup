/*
 * conexiune.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "conexiune.h"
void durata (unsigned int h1, unsigned int h2, unsigned int m1, unsigned int m2, unsigned int s1, unsigned int s2, int h, int m, int s)
{
	//pornim de la secunde, deoarece trebuie sa facem imprumut de la minute, daca s1<s2
	if (s1>=s2)
	{
		s=s1-s2;
	}
	else { //daca s1<s2, imprumutam 60 de secunde = 1 minut
		s=60+s1-s2;
		m--;
	}
	if (m1>=m2) //procedam la fel si cu minutele
	{
		m+=m1-m2;
	}
	else { //daca m1<m2 atunci imprumutam 60 de minute = 1 ora
		m+=60+m1-m2;
		h--;
	}
	if (h1>=h2) //la fel si cu orele
	{
		h+=h1-h2;
	}
	else { //daca h1<h2 imprumutam "o zi" = 24 de ore
		h+=24+h1-h2;
	}
	printf("Durata conexiunii a fost de %d ore, %d minute, %d secunde\n", h, m, s); //afisam durata conexiunii
}
