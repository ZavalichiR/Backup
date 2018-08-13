/*
 * vectori.c
 *
 *  Created on: Apr 10, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "vectori.h"
int *xmalloc(int n)
{
	int *p=0;
	p=(int*)malloc(sizeof(int)*n);
	if (!p)
	{
		fprintf(stderr, "Eroare la alocarea memoriei!\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
void citireVector(int *a, int n)
{
	int i;
	for (i=0; i<n; ++i)
	{
		printf("Elementul %d:", i+1);
		scanf("%d", a+i);
	}
}
void afisareVector(int *a, int n)
{
	int i;
	for (i=0; i<n; ++i)
	{
		printf("%d;%c", *(a+i), (i==n-1)?'\n':' ');
	}
}
int *sumaVectori(int *x, int *y, int n)
{
	int *v_suma=0;
	v_suma=xmalloc(n);
	int i;
	for (i=0; i<n; ++i)
	{
		*(v_suma+i)=*(x+i)+*(y+i);
	}
	return v_suma;
}
