/*
 * main.c
 *
 *  Created on: Jun 15, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "pointeri.h"
int main(void)
{
	int *vector=0;
	int n, m;
	double **matrice=0;
	printf("Citire vector\n");
	printf("n=");
	scanf("%d", &n);
	vector=citesteVector(n);
	printf("Vectorul citit este: ");
	afiseazaVector(vector, n);
	printf("\nCitire matrice\n");
	printf("n=");
	scanf("%d", &n);
	printf("m=");
	scanf("%d", &m);
	matrice=citesteMatrice(n, m);
	printf("Matricea citita este:\n");
	afiseazaMatrice(matrice, n, m);

	free(vector);
	vector=0;
	elibereazaMemorieMatrice(matrice, n);
	matrice=0;
	return 0;
}
