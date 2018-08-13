/*
 * pointeri.c
 *
 *  Created on: Jun 15, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "pointeri.h"

void* xmalloc(size_t nrOcteti)
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
int* citesteVector(int n)
{
	int *v=0;
	v=(int*)xmalloc(n*sizeof(int));

	int i;
	for (i=0; i<n; ++i)
	{
		printf("v[%d]=", i);
		scanf("%d", v+i);
	}

	return v;
}
void afiseazaVector(int *v, int n)
{
	int i;
	for (i=0; i<n; ++i)
	{
		printf("%d; ", *(v+i));
	}
}
double **alocaMemorieMatrice(int n, int m)
{
	double **a=0;
	a=(double**)xmalloc(n*sizeof(double*));

	int i;
	for (i=0; i<n; ++i)
	{
		*(a+i)=(double*)xmalloc(m*sizeof(double));
	}
	return a;
}
void elibereazaMemorieMatrice(double **a, int n)
{
	int i;
	for (i=0; i<n; ++i)
	{
		free(*(a+i));
		*(a+i)=0;
	}
	free(a);
}
double** citesteMatrice(int n, int m)
{
	double **a=0;
	int i, j;
	a=alocaMemorieMatrice(n, m);

	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; ++j)
		{
			printf("a[%d][%d]=", i, j);
			scanf("%lf", *(a+i)+j);
		}
	}

	return a;
}
void afiseazaMatrice(double **a, int n, int m)
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
