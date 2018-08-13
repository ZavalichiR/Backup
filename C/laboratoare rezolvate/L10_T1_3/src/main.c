/*
 * main.c
 *
 *  Created on: May 7, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "ordonare_matrice.h"
int main(void)
{
	FILE *in;
	in=fopen("in.txt", "r");
	if (in==0)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"in.txt\"\n");
		exit(EXIT_FAILURE);
	}
	double **a=0;
	int n, m;
	fscanf(in, "%d", &n);
	fscanf(in, "%d", &m);
	a=aloca2d(n, m);
	citireMatrice(in, a, n, m);
	printf("Matricea citita este:\n");
	afisareMatrice(a, n, m);
	ordonareMatrice(a, n, m);
	printf("Matricea ordonata:\n");
	afisareMatrice(a, n, m);
	dealoca2d(a, n);
	return 0;
}
