/*
 * autovehicule.c
 *
 *  Created on: Apr 22, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "autovehicule.h"
void citireVector(FILE *in, double v[], int n, int c)
{
	int i;
	int aux;
	for (i=0; i<n; ++i)
	{
		fscanf(in, "%d", &aux);
		v[i]=aux*c/100.;
	}
}
void afisareVector(double v[], int n)
{
	int i;
	printf("(");
	for (i=0; i<n-1; ++i)
	{
		printf("%5.2lf, ",v[i]);
	}
	printf("%5.2lf)\n", v[n-1]);
}
PARC calcul(double v[], int n)
{
	PARC p;
	double s;
	int i;
	s=0;
	for (i=0; i<n; ++i)
	{
		s+=v[i];
	}
	p.nr_total_litri=s;
	p.nr_mediu_litri=s/n;
	p.nr_autovehicule=n;
	return p;
}
void afisareCalcul(PARC p)
{
	printf("Numarul total de litri consumati de autovehicule: %.2lf\n", p.nr_total_litri);
	printf("Numarul de autovehicule: %d\n", p.nr_autovehicule);
	printf("Numarul mediu de litri consumati de autovehiculele firmei: %.2lf\n", p.nr_mediu_litri);
}
unsigned int rotireStanga(unsigned int x, int k)
{
	int n;
	unsigned int MASCA, biti;
	n=sizeof(x)<<3;
	MASCA=(unsigned int)0u;
	MASCA=~MASCA;
	MASCA>>=k;
	MASCA=~MASCA;
	biti=x&MASCA;
	biti>>=(n-k);
	x<<=k;
	x|=biti;
	return x;
}
void afisareBinara(unsigned int x)
{
	unsigned int MASCA, bit;
	int n;
	n=sizeof(x)<<3;
	MASCA=(unsigned int)0u;
	MASCA=~MASCA;
	MASCA>>=1;
	MASCA=~MASCA;
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
