/*
 * main.c
 *
 *  Created on: Apr 22, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "autovehicule.h"
int main(void)
{
	int n, consum;
	unsigned int nr_km;
	double v[30];
	char nume_fisier[32];
	PARC p;
	FILE *in;
	printf("Numarul de masini: ");
	scanf("%d", &n);
	getchar();
	printf("Consumul la suta de km: ");
	scanf("%d", &consum);
	getchar();
	printf("Firma are %.3d masini si fiecare masina a avut un consum de %.2dl la 100km.\n", n, consum);
	printf("Introduceti numele fisierului de intrare: ");
	fgets(nume_fisier, 31, stdin);
	nume_fisier[strlen(nume_fisier)-1]='\0';
	in=fopen(nume_fisier, "r");
	if (in==0)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului de intrare \"%s\".\n", nume_fisier);
		exit(EXIT_FAILURE);
	}
	citireVector(in, v, n, consum);
	fclose(in);
	afisareVector(v, n);
	p=calcul(v, n);
	afisareCalcul(p);
	nr_km=(unsigned int)(v[2]*100/consum);
	printf("Numarul inainte de rotire: \n");
	afisareBinara(nr_km);
	nr_km=rotireStanga(nr_km, 6);
	printf("Numarul dupa rotirea la stanga cu 6 pozitii: \n");
	afisareBinara(nr_km);
	return 0;
}
