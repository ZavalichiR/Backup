/*
 * pitici.c
 *
 *  Created on: Apr 16, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
#include "pitici.h"
void citire(FILE *fisier, double x[][30], int d1, int d2) //citeste o matrice din fisier, de d1 linii si d2 coloane
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
void afisare(FILE *fisier, double x[][30], int d1, int d2) //afiseaza in fisier o matrice de d1 linii si d2 coloane
{
	int i, j;
	for (i=0; i<d1; ++i)
		{
			for (j=0; j<d2; ++j)
			{
				fprintf(fisier, "%.2lf ", x[i][j]);
			}
			fprintf(fisier, "\n");
		}
	fprintf(fisier, "\n");
}
void suma(double x[][30], double y[][30], double s[][30], int x1, int x2, int y1, int y2) //calculeaza suma a doua matrici x si y, de dimensiuni arbitrare
{
	if (x1!=y1 || x2!=y2) //dimensiunile matricilor sumate trebuie sa se potriveasca pentru a face operatia de sumare
	{
		printf("Dimensiunile matricelor nu se potrivesc pentru operatia de adunare!\n");
	}
	else {
		int i, j;
		double suma; //variabila s semnifica suma pe fiecare componenta
		for (i=0; i<x1; ++i)
		{
			for (j=0; j<x2; ++j)
			{
				suma=x[i][j]+y[i][j];
				s[i][j]=suma; //pentru fiecare componenta in parte, calculam suma si o depunem pe pozitia corespunzatoare in matricea s
			}
		}
	}
}
void produs(double x[][30], double y[][30], double p[][30], int x1, int x2, int y1, int y2) //calculeaza produsul a 2 matrici de dimensiuni arbitrare
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
				p[i][j]=s; //dupa ce terminam o suma partiala de produse, o memoram in matricea p, caci va fi un singur element al matricii produs
			}
		}
	}
}
void transpunere(double x[][30], double t[][30], int n, int m) //transpune o matrice x data ca parametru, patratica de ordin n, si depune transpusa in matricea t
{
	int i, j;
	for (i=0; i<n; ++i) //parcurgem matricea pe linii
	{
		for (j=0; j<m; ++j) //si pe coloane
		{
			t[j][i]=x[i][j]; //in matricea t, depunem elementul de pe linia i, coloana j, exact pe dos, adica pe linia j, coloana i
			//deoarece la transpunerea unei matrici, coloanele devin linii si liniile devin coloane
		}
	}
}
void zile_munca(FILE *fisier, double p[][30], int n, double G) //calculeaza si afiseaza in fisier numarul de zile de munca pentru fiecare pitic
{
	int i;
	double z; //z=numarul de zile
	for (i=0; i<n; ++i) //parcurgem vectorul ce contine sumele de platit pentru fiecare pitic
	{
		fprintf(fisier, "Piticul %d are de muncit ", i+1);
		z=p[i][0]/G; //calculam numarul de zile de munca impartind suma de platit la suma de galbeni pe care o primeste zilnic
		if (z==(int)z) //daca obtinem un numar natural
		{
			fprintf(fisier, "%d zile.\n", (int)z); //afisam numarul de zile ca si numar intreg
		}
		else { //daca obtinem un numar zecimal
			fprintf(fisier, "%.2lf (%d) zile.\n", z, (int)ceil(z)); //facem si rotunjirea si conversia sa la intreg, prin functia ceil(), si apoi cast la (int)
		}
	}
}
