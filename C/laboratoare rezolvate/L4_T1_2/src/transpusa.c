/*
 * transpusa.c
 *
 *  Created on: Apr 16, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "transpusa.h"
void citire(double x[][20], int n, char nume_matrice) //citeste o matrice patratica de ordin n de la tastatura
{
	int i, j;
	double aux; //folosim o variabila auxiliara pentru ca citim din fisier numere reale ce trebuie depuse intr-o matrice
	for (i=0; i<n; ++i)
	{
		for (j=0; j<n; ++j)
		{
			fprintf(stdout, "%c[%d][%d]=", nume_matrice, i+1, j+1);
			fscanf(stdin, "%lf", &aux);
			x[i][j]=aux;
		}
	}
}
void afisare(double x[][20], int n) //afiseaza pe ecran o matrice patratica de ordin n
{
	int i, j;
	for (i=0; i<n; ++i)
	{
		for (j=0; j<n; ++j)
		{
			printf("%.2lf ", x[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
void transpunere(double x[][20], double t[][20], int n) //transpune o matrice x data ca parametru, patratica de ordin n, si depune transpusa in matricea t
{
	int i, j;
	for (i=0; i<n; ++i) //parcurgem matricea pe linii
	{
		for (j=0; j<n; ++j) //si pe coloane
		{
			t[j][i]=x[i][j]; //in matricea t, depunem elementul de pe linia i, coloana j, exact pe dos, adica pe linia j, coloana i
			//deoarece la transpunerea unei matrici, coloanele devin linii si liniile devin coloane
		}
	}
}
void produs(double x[][20], double y[][20], double p[][20], int n) //calculeaza produsul a 2 matrici x si y, patratice de ordin n si depunde rezultatul in matricea p
{
	int i, j;
	for (i=0; i<n; ++i) //parcurgem liniile primei matrici pentru ca trebuie sa inmultim fiecare linie a ei cu fiecare coloana a matricei 2
	{
		for (j=0; j<n; ++j) //parcurgem coloanele matricei a doua
		{
			int k;
			double s;
			s=0; //suma s va fi suma "partiala" care se formeaza din produsele de forma a11*b11 + a12*b21 + ... + a1n * bm1, de exemplu, pt primul element
			for (k=0; k<n; ++k) //variabila k parcurge prima matrice pe coloane, dar, in acelasi timp, a doua matrice pe linii, si astfel formam produsele de tipul celor de mai sus
				s+=x[i][k]*y[k][j];
			p[i][j]=s; //dupa ce terminam o suma partiala de produse, o depunem in matricea p, caci va fi un singur element al matricii produs
		}
	}
}
