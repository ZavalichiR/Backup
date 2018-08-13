/*
 * main.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "conexiune.h"
int main(void)
{
	unsigned int h1, m1, s1, dh, dm, ds, h, m, s;
	/*
	 * h1, m1, s1 reprezinta momentul conectarii, in ore, minute, respectiv secunde
	 * dh, dm, ds reprezinta durata in ore, minute, secunde a conexiunii
	 * h, m, s reprezinta momentul deconectarii, in ore, minute, respectiv secunde
	 */
	printf("Introduceti momentul conectarii (hh:mm:ss): "); //citim momentul conectarii
	scanf("%d:%d:%d", &h1, &m1, &s1);
	printf("Introduceti durata conexiunii (hh:mm:ss): "); //citim durata
	scanf("%d:%d:%d", &dh, &dm, &ds);
	h=0; //initializam cu 0 pentru a nu obtine valori reziduale cand efectuam operatiile
	m=0;
	s=0;
	deconectare(h1,dh,m1,dm,s1,ds,h,m,s); //apelam functia deconectare() care calculeaza si afiseaza momentul intreruperii conexiunii Internet
	return 0;
}
