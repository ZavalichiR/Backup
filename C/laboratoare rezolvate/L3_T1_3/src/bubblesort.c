/*
 * bubblesort.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "bubblesort.h"
void citesteVector(FILE *in, int a[], unsigned int n) //citeste n elemente ale unui vector din fisierul de intrare "in"
{
	int i;
	for (i=0; i<n; ++i)
	{
		fscanf(in, "%d", &a[i]);
	}
}
void afisareVector(int a[], unsigned int n) //afiseaza pe ecran n elemente ale vectorului a, in format (a1, a2, ..., an)
{
	int i;
	printf("(");
	for (i=0; i<n-1; ++i)
	{
		printf("%d; ", a[i]);
	}
	printf("%d)\n", a[n-1]);
}
void sortare(int a[], unsigned int n) //sorteaza vectorul a, cu n elemente (metoda BubbleSort)
{
	int i, j, ok, aux; //avem nevoie de variabila ok care retine daca s-au efectuat interschimbari sau nu la o parcurgere
	j=n-1;
	do {
		ok=0; //pornim cu ok=0, adica presupunem ca nu s-a facut nicio interschimbare
		i=0; //incepem parcurgerea vectorului de la primul element
		while (i<j) //se parcurge vectorul pana la penultimul, deoarece acesta va fi comparat cu ultimul
		{
			if (a[i]>a[i+1]) //daca 2 elemente consecutive sunt in relatia de ordine "mai mare"
			{
				aux=a[i]; //le interschimbam
				a[i]=a[i+1];
				a[i+1]=aux;
				ok=1; //retinem ca s-a facut o interschimbare
			}
			++i; //trecem la urmatorul element
		}
		--j; //dupa ce terminam o parcurgere, stim ca elementul de pe ultima pozitie va fi clar cel mai mare, deci nu va mai fi nevoie sa il comparam
	} while (ok==1); //procesul se repeta cat timp se fac interschimbari in vector
}
