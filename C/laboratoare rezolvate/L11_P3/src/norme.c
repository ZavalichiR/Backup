/*
 * norme.c
 *
 *  Created on: May 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "norme.h"
void *xmalloc(size_t nrOcteti)
{
	void *p=0;
	p=malloc(nrOcteti);
	if (p==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei.\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
double* citireVector(int n)
{
	double *v=0;
	v=(double*)xmalloc(n*sizeof(double));
	int i;
	for (i=0; i<n; ++i)
	{
		printf("v[%d]=", i);
		scanf("%lf", v+i);
	}
	return v;
}
void afisareVector(double *v, int n)
{
	int i;
	printf("(");
	for (i=0; i<n-1; ++i)
	{
		printf("%.2lf, ", *(v+i));
	}
	printf("%.2lf)\n", *(v+n-1));
}
void meniu(NORME tab[], int nf, char *msg)
{
	int i;
	puts(msg);
	for (i=0; i<nf; ++i)
	{
		printf("\t%d-%s\n", i+1, tab[i].nume);
	}
	printf("\t0 - iesire\n");
	printf("\t?:");
}
double n1(double *v, int n)
{
	double valn1;
	valn1=0;
	int i;
	for (i=0; i<n; ++i)
	{
		valn1+=abs(*(v+i));
	}
	return valn1;
}
double n2(double *v, int n)
{
	double valn2;
	valn2=0;
	int i;
	for (i=0; i<n; ++i)
	{
		valn2+=(*(v+i))*(*(v+i));
	}
	valn2=sqrt(valn2);
	return valn2;
}
double ninf(double *v, int n)
{
	double valninf;
	valninf=abs(*(v+0));
	int i;
	for (i=1; i<n; ++i)
	{
		if (*(v+i)>valninf)
		{
			valninf=abs(*(v+i));
		}
	}
	return valninf;
}
