/*
 * numere.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "numere.h"
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
int tip_numar(unsigned int x) //functie care returneaza -1, 0, sau 1, in functie de tipul numarului, deficient, perfect, sau abundent
{
	int rez;
	unsigned int sd=suma_div(x); //se calculeaza suma divizorilor folosind functia deja creata
	if (sd<x) //se compara cu numarul insusi si se returneaza valoarea corespunzatoare in urma comparatiei
	{
		rez=-1;
	}
	else if (sd==x)
	{
		rez=0;
	}
	else {
		rez=1;
	}
	return rez;
}
//urmatoarele functii folosesc functia tip_numar() pentru a decide ce tip de numere se afla in intervalul [a, b] dat ca parametru
//se parcurge intervalul de la a la b cu pas de o unitate si se testeaza fiecare numar in parte, iar in functie de ceea ce returneaza functia tip_numar, se afiseaza pe ecran numerele deficiente, abundente, sau perfecte
void perfecte(unsigned int a, unsigned int b)
{
	int i, tip;
	for (i=a; i<=b; i++)
	{
		tip=tip_numar(i);
		if (tip==0)
			{
			printf("%d; ", i);
			}
	}
}
void deficiente(unsigned int a, unsigned int b)
{
	int i, tip;
	for (i=a; i<=b; i++)
	{
		tip=tip_numar(i);
		if (tip==-1)
			{
			printf("%d; ", i);
			}
	}
}
void abundente(unsigned int a, unsigned int b)
{
	int i, tip;
	for (i=a; i<=b; i++)
	{
		tip=tip_numar(i);
		if (tip==1)
			{
			printf("%d; ", i);
			}
	}
}
