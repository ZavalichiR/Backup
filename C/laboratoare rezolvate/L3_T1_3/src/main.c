/*
 * main.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "bubblesort.h"
int main(void)
{
	FILE *in; //declaram o variabila de tip fisier
	int v[30];
	unsigned int n;
	in=fopen("inP12.dat", "r"); //citim fisierul de intrare de pe disc "inP12.dat", deci al doilea parametru al functiei fopen() este "r" ("read")
	if (in==0) //daca fopen() a returnat 0, adica deschiderea fisierului a esuat
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"inP12.dat\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //inchidem programul, deoarece nu avem de unde sa citim datele de intrare
	}
	fscanf(in, "%u", &n); //citim de pe prima linie a fisierului numarul de elemente ale vectorului
	citesteVector(in, v, n); //apelam functia de citire a vectorului v din fisierul in, cu numarul de elemente n
	afisareVector(v, n); //apelam functia de afisare a vectorului v, cu n elemente
	sortare(v, n); //sortam vectorul v crescator, prin apelul functiei sortareVector
	afisareVector(v, n); //afisam din nou vectorul pe ecran, dar de aceasta data va fi sortat de functia apelata anterior
	fclose(in); //inchidem obligatoriu fisierul de intrare folosit
	return 0;
}
