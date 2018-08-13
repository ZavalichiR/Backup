/*
 * masini.c
 *
 *  Created on: Apr 22, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "masini.h"
void citire(FILE *in, int a[][30], int n, int m)
{
	if (in==stdin)
	{
		printf("Introduceti, pentru fiecare autovehicul, numarul de kilometri parcursi in fiecare zi: \n");
	}
	int i, j;
	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; ++j)
		{
			if (in==stdin)
			{
				printf("Numarul de kilometri parcursi de masina %d in ziua %d: ", i+1, j+1);
			}
			fscanf(in, "%d", &a[i][j]);
		}
	}
}
void afisare(int a[][30], int n, int m)
{
	int i, j;
	for (i=0; i<n; ++i)
	{
		printf("Masina %d a parcurs:\n", i+1);
		for (j=0; j<m; ++j)
		{
			printf("\tin ziua %d -> %dkm\n", j+1, a[i][j]);
		}
	}
}
void afisareVector_intregi(int v[30], int n)
{
	int i;
	printf("(");
	for (i=0; i<n-1; ++i)
	{
		printf("%d, ", v[i]);
	}
	printf("%d)\n", v[n-1]);
}
void afisareVector_reali(double v[30], int n)
{
	int i;
	printf("(");
	for (i=0; i<n-1; ++i)
	{
		printf("%.2lf, ", v[i]);
	}
	printf("%.2lf)\n", v[n-1]);
}
PARC_AUTO calcul(int a[][30], int n, int m)
{
	PARC_AUTO parc;
	int i, j, nr_km, suma_km;
	for (i=0; i<n; ++i)
	{
		nr_km=0;
		for (j=0; j<m; ++j)
		{
			nr_km+=a[i][j];
		}
		parc.nr_total_km[i]=nr_km;
	}
	parc.nr_masini=n;
	for (j=0; j<m; ++j)
	{
		suma_km=0;
		for (i=0; i<n; ++i)
		{
			suma_km+=a[i][j];
		}
		parc.nr_mediu_km[j]=(double)suma_km/n;
	}
	return parc;
}
void afisareCalcul(PARC_AUTO p, int n, int m)
{
	printf("Numarul total de kilometri parcurs de fiecare masina:\n");
	afisareVector_intregi(p.nr_total_km, n);
	printf("Numarul total de masini: %d\n", p.nr_masini);
	printf("Numarul mediu de kilometri parcurs de masini, in fiecare zi: \n");
	afisareVector_reali(p.nr_mediu_km, m);
}
unsigned int rotire_stanga(unsigned int x, int k)
{
	unsigned int n, bit;
	n=sizeof(x)<<3;
	unsigned int MASCA=(unsigned int)1u<<(n-1);
	while (k)
	{
		bit=x&MASCA;
		bit>>=(n-1);
		x<<=1;
		x|=bit;
		--k;
	}
	return x;
}
void afisareBinara(unsigned int x)
{
	unsigned int MASCA, n, bit;
	MASCA=(unsigned int)0u;
	MASCA=~MASCA;
	MASCA>>=1;
	MASCA=~MASCA;
	n=sizeof(x)<<3;
	while (n)
	{
		bit=MASCA&x;
		bit>>=(n-1);
		printf("%u", bit);
		MASCA>>=1;
		--n;
	}
	printf("\n");
}
