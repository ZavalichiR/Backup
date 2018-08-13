/*
 * matrici.c
 *
 *  Created on: May 7, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrici.h"
void *xmalloc(size_t nrOcteti)
{
	void *p=malloc(nrOcteti);
	if (p==0)
	{
		fprintf(stderr, "Eroare la alocare.\n");
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
void citireMatrice(double **a, int n, int m)
{
	int i, j;
	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; ++j)
		{
			printf("a[%d][%d]=", i, j);
			scanf("%lf", *(a+i)+j);
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
void sumaMatrice(double **a, double **b, double **s, int n, int m)
{
	int i, j;
	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; ++j)
		{
			*(*(s+i)+j)=*(*(a+i)+j)+*(*(b+i)+j);
		}
	}
}
