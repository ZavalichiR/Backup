/*
 * ma.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "ma.h"
double ma() //calculeaza media artimetica a 5 numere citite de la tastatura
{
	double media;
	int x, i, s;
	s=0; //pornim cu suma de la 0
	for (i=1; i<=5; i++) //pentru fiecare indice de la 1 la 5
	{
		printf("x%d=", i);
		scanf("%d", &x); //citim numarul corespunzator indicelui
		s+=x; //il adunam la suma
	}
	media=s/5.; //la final, dupa ce am facut suma celor 5 numere, o impartim la 5 pentru a obtine media aritmetica
	return media;
}
