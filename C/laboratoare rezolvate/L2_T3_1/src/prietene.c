/*
 * prietene.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include "prietene.h"
int validare(unsigned int a, unsigned int b) //valideaza intervalul [a, b] (a numar pozitiv, b numar strict pozitiv, si a<b, pentru a avea sens intervalul)
{
	int ok;
	if (a>=0 && b>0 && a<b)
	{
		ok=1;
	}
	else {
		ok=0;
	}
	return ok;
}
unsigned int suma_div(unsigned int x) //calculeaza suma divizorilor unui numar x
{
	unsigned int suma, i;
	suma=0; //pornim cu suma de la 0
	for (i=1; i<=x/2; i++) //pentru fiecare numar de la 1 la jumatatea lui x
	{
		if (x%i==0) //daca x se imparte exact la acel numar i
		{
			suma+=i; //adunam acel divizor i la suma
		}
	}
	return suma;
}
int prietene(unsigned int a, unsigned int b) //verifica daca 2 numere x si y sunt prietene
{
	int ok;
	unsigned int sa, sb;
	sa=suma_div(a); //calculam suma divizorilor pentru ambele numere
	sb=suma_div(b);
	if (sa==b && sb==a) //daca suma divizorilor unui numar este egala cu celalalt, reciproc, atunci numerele sunt prietene
	{
		ok=1;
	}
	else ok=0;
	return ok;
}
