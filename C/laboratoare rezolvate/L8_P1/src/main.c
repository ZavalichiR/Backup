/*
 * main.c
 *
 *  Created on: Apr 10, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "vectori.h"
int main(void)
{
	int *a=0, *b=0, *suma=0;
	int n;
	printf("n=");
	scanf("%d", &n);
	printf("Introduceti elementele primului vector:\n");
	a=xmalloc(n);
	citireVector(a, n);
	printf("Introduceti elementele celui de-al doilea vector:\n");
	b=xmalloc(n);
	citireVector(b, n);
	suma=sumaVectori(a, b, n);
	free(a);
	free(b);
	printf("Suma celor 2 vectori: \n");
	afisareVector(suma, n);
	free(suma);
	return 0;
}
