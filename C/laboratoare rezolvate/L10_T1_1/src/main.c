/*
 * main.c
 *
 *  Created on: May 7, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "matrici.h"
int main(void)
{
	int n, m;
	double **m1=0, **m2=0, **suma=0;
	printf("n=");
	scanf("%d", &n);
	printf("m=");
	scanf("%d", &m);
	printf("Introduceti elementele primei matrice:\n");
	m1=aloca2d(n, m);
	citireMatrice(m1, n, m);
	printf("Introduceti elementele celei de a doua matrice:\n");
	m2=aloca2d(n, m);
	citireMatrice(m2, n, m);
	printf("\nMatricile citite sunt:\n");
	afisareMatrice(m1, n, m);
	printf("\n");
	afisareMatrice(m2, n, m);
	printf("\n");
	suma=aloca2d(n, m);
	printf("Matricea suma este:\n");
	sumaMatrice(m1, m2, suma, n, m);
	afisareMatrice(suma, n, m);
	dealoca2d(m1, n);
	dealoca2d(m2, n);
	dealoca2d(suma, n);
	return 0;
}
