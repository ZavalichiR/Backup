/*
 * conexiune.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "conexiune.h"
void deconectare (unsigned int h1, unsigned int dh, unsigned int m1, unsigned int dm, unsigned int s1, unsigned int ds, unsigned int h, unsigned int m, unsigned int s)
{
	if (s1+ds>=60) //pornim de la secunde, si adaugam un minut in plus daca suma depaseste 60
	{
		m++;
		s+=s1+ds-60;
	}
	else {
		s+=s1+ds;
	}
	if (m+m1+dm>=60) //la fel si cu minutele, dar tinem cont ca e posibil sa fi adaugat un minut in plus la verificarea secundelor (de aceea se adauga +m la verificare)
	{
		h++;
		m+=m1+dm-60;
	}
	else {
		m+=m1+dm;
	}
	if (h+h1+dh>=24) //asemanator cu numarul de ore, tot cu +h la verificare, pentru ca e posibil sa fi adaugat o ora in plus de la sumarea minutelor
	{
		h+=h1+dh-24;
	}
	else {
		h+=h1+dh;
	}
	printf("Conexiunea s-a incheiat la ora %.2d:%.2d:%.2d.\n", h, m, s); //afisam momentul deconectarii
}
