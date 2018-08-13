/*
 * ordonare_matrice.c
 *
 *  Created on: May 7, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "ordonare_matrice.h"

void *xmalloc(size_t nrOcteti)
{
	void *p=malloc(nrOcteti);
	if (p==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei.\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
double **aloca2d(int n, int m)
{
	double **a=0;
	int i;
	a=(double**)xmalloc(n*sizeof(double*));
	for (i=0; i<n; ++i)
	{
		*(a+i)=(double*)xmalloc(m*sizeof(double));
	}
	return a;
}
void dealoca2d(double **a, int n)
{
	int i;
	for (i=0; i<n; ++i)
	{
		free(*(a+i));
		*(a+i)=0;
	}
	free(a);
}
void citireMatrice(FILE *in, double **a, int n, int m)
{
	int i, j;
	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; ++j)
		{
			fscanf(in, "%lf", *(a+i)+j);
		}
	}
}
void afisareMatrice(double **a, int n, int m)
{
	int i, j;
	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; ++j)
		{
			printf("%.2lf ", *(*(a+i)+j));
		}
		printf("\n");
	}
}
double valMax(double *v, int n)
{
	double maxim;
	maxim=*(v+0);
	int i;
	for (i=1; i<n; ++i)
	{
		if (*(v+i)>maxim)
		{
			maxim=*(v+i);
		}
	}
	return maxim;
}
void swap(double **l1, double **l2)
{
	double *aux;
	aux=*l1;
	*l1=*l2;
	*l2=aux;
}
void ordonareMatrice(double **a, int n, int m)
{
	double *v=(double*)xmalloc(n*sizeof(double));
	int i;
	for (i=0; i<n; ++i)
	{
		*(v+i)=valMax(*(a+i), n);
	}
	int k, ok;
	double aux;
	k=n-1;
	do {
		ok=0;
		for (i=0; i<k; ++i)
		{
			if (*(v+i)>*(v+i+1))
			{
				aux=*(v+i);
				*(v+i)=*(v+i+1);
				*(v+i+1)=aux;
				swap(a+i, a+i+1);
				ok=1;
			}
		}
		--k;
	} while (ok);
}
