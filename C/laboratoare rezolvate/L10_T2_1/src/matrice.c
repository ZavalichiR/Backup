/*
 * matrice.c
 *
 *  Created on: May 9, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
void* xmalloc(size_t nrOcteti)
{
	void *p;
	p=malloc(nrOcteti);
	if (p==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei.\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
void aloca2d(double **a, unsigned int n, unsigned int m)
{
	int i;
	a=(double**)xmalloc(n*sizeof(double*));
	for (i=0; i<n; ++i)
	{
		*(a+i)=(double*)xmalloc(m*sizeof(double));
	}
}
void dealoca2d(double **a, unsigned int n)
{
	int i;
	for (i=0; i<n; ++i)
	{
		free(*(a+i));
		*(a+i)=0;
	}
	free(a);
}
double** citireMatrice(unsigned int n, unsigned int m)
{
	double **a=0;
	aloca2d(a, n, m);
	int i, j;
	printf("Elementul de pe: \n");
	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; ++j)
		{
			printf("\t-> linia %d, coloana %d: ", i+1, j+1);
			scanf("%lf", *(a+i)+j);
		}
	}
	return a;
}
void afisareMatrice(MATRICE* matrice)
{
	int i, j;
	for (i=0; i<matrice->n; ++i)
	{
		for (j=0; j<matrice->m; ++j)
		{
			printf("%s[%d][%d]=%.2lf ", matrice->nume, i, j, *(*(matrice->a+i)+j));
		}
		printf("\n");
	}
}
MATRICE incarcareInformatii(char *nume)
{
	MATRICE matrice;
	printf("Introduceti numele matricei: ");
	nume=(char*)xmalloc(32*sizeof(char));
	fgets(nume, 31, stdin);
	matrice.nume=nume;
	printf("Numarul de linii: ");
	scanf("%u", &matrice.n);
	printf("Numarul de coloane: ");
	scanf("%u", &matrice.m);
	printf("Introduceti elementele matricei:\n");
	matrice.a=citireMatrice(matrice.n, matrice.m);
	printf("Matricea introdusa este:\n");
	afisareMatrice(&matrice);
	return matrice;
}
