/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "conexiune.h"
int main(void)
{
	unsigned int h1, h2, m1, m2, s1, s2, h, m, s;
	/*
	 * h, m si s reprezinta numarul de ore, minute, respectiv secunde a duratei conexiunii
	 * h1, m1, s1 reprezinta momentul deconectarii
	 * h2, m2, s2 reprezinta momentul conectarii
	 */
	h=0; //initializam cu 0, pentru a avea de unde scade in caz de imprumut si pentru a nu obtine valori reziduale cand efectuam operatiile
	m=0;
	s=0;
	printf("Introduceti momentul conectarii, in format hh:mm:ss\n"); //citim cele 2 momente ale conexiunii Internet (in format hh:mm:ss)
	scanf("%2d:%2d:%2d", &h2, &m2, &s2);
	printf("Introduceti momentul deconectarii, in format hh:mm:ss\n");
	scanf("%2d:%2d:%2d", &h1, &m1, &s1);
	durata(h1,h2,m1,m2,s1,s2,h,m,s); //apelam functia durata(), care va calcula si afisa durata conexiunii
	return 0;
}
