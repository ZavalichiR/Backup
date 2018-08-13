/*
 * matrice.c
 *
 *  Created on: Apr 15, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "matrice.h"
void citire(FILE *fisier, double x[][20], int d1, int d2) //citeste o matrice din fisier, de d1 linii si d2 coloane
{
	int i, j;
	double aux; //folosim o auxiliara pentru a citi numere reale din fisier inainte de a le pune in matrice
	for (i=0; i<d1; ++i)
	{
		for (j=0; j<d2; ++j)
		{
			fscanf(fisier, "%lf", &aux);
			x[i][j]=aux;
		}
	}
}
void afisare(double x[][20], int d1, int d2) //afiseaza pe ecran o matrice de d1 linii si d2 coloane
{
	int i, j;
	for (i=0; i<d1; ++i)
		{
			for (j=0; j<d2; ++j)
			{
				printf("%.2lf ", x[i][j]);
			}
			printf("\n");
		}
	printf("\n");
}
void suma(double x[][20], double y[][20], int x1, int x2, int y1, int y2) //calculeaza suma a doua matrici x si y, de dimensiuni arbitrare
{
	if (x1!=y1 || x2!=y2) //dimensiunile matricilor sumate trebuie sa se potriveasca pentru a face operatia de sumare
	{
		printf("Dimensiunile matricelor nu se potrivesc pentru operatia de adunare!\n");
	}
	else {
		int i, j;
		double s; //variabila s semnifica suma pe fiecare componenta
		for (i=0; i<x1; ++i)
		{
			for (j=0; j<x2; ++j)
			{
				s=x[i][j]+y[i][j];
				printf("%.2lf ", s); //pentru fiecare componenta in parte, calculam suma si o afisam direct pe ecran
			}
			printf("\n");
		}
	}
}
void produs(double x[][20], double y[][20], int x1, int x2, int y1, int y2) //calculeaza produsul a 2 matrici de dimensiuni arbitrare
{
	if (x2!=y1) //pentru a putea calcula produsul, numarul de coloane ale primei matrici trebuie sa fie egal cu numarul de linii ale celei de a doua
	{
		printf("Dimensiunile matricelor nu se potrivesc pentru operatia de inmultire!\n");
	}
	else {
		int i, j;
		for (i=0; i<x1; ++i) //parcurgem liniile primei matrici pentru ca trebuie sa inmultim fiecare linie a ei cu fiecare coloana a matricei 2
		{
			for (j=0; j<y2; ++j) //parcurgem coloanele matricei a doua
			{
				int k;
				double s;
				s=0; //suma s va fi suma "partiala" care se formeaza din produsele de forma a11*b11 + a12*b21 + ... + a1n * bm1, de exemplu, pt primul element
				for (k=0; k<x2; ++k) //variabila k parcurge prima matrice pe coloane, dar, in acelasi timp, a doua matrice pe linii, si astfel formam produsele de tipul celor de mai sus
					s+=x[i][k]*y[k][j];
				printf("%.2lf ", s); //dupa ce terminam o suma partiala de produse, o afisam, caci va fi un singur element al matricii produs
			}
			printf("\n");
		}
	}
}
