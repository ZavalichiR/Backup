/*
 * main.c
 *
 *  Created on: Apr 22, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "masini.h"
int main(void)
{
	FILE *in;
	char nume_fisier[32];
	int n, m, masini[30][30];
	unsigned int numar_rotit;
	printf("Introduceti numele fisierului de intrare: ");
	fgets(nume_fisier, 31, stdin);
	nume_fisier[strlen(nume_fisier)-1]='\0';
	if (strcmp(nume_fisier, "stdin")!=0)
	{
		in=fopen(nume_fisier, "r");
		if (in==0)
		{
			fprintf(stderr, "Eroare la deschiderea fisierului de intrare \"%s\".\n", nume_fisier);
			exit(EXIT_FAILURE);
		}
	}
	else {
		in=stdin;
	}
	if (in==stdin)
	{
		printf("Numarul de autovehicule: ");
	}
	fscanf(in, "%d", &n);
	if (in==stdin)
	{
		printf("Numarul de zile pentru care s-au facut inregistrarile: ");
	}
	fscanf(in, "%d", &m);
	citire(in, masini, n, m);
	fclose(in);
	afisare(masini, n, m);
	PARC_AUTO p;
	p=calcul(masini, n, m);
	afisareCalcul(p, n, m);
	printf("Numarul initial: \n");
	numar_rotit=(unsigned int)masini[2][1];
	numar_rotit=(unsigned int)floor(numar_rotit);
	afisareBinara(numar_rotit);
	numar_rotit=rotire_stanga(numar_rotit, 2);
	printf("Numarul rotit la stanga cu 2 pozitii: \n");
	afisareBinara(numar_rotit);
	return 0;
}
