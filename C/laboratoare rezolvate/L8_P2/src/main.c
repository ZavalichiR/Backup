/*
 * main.c
 *
 *  Created on: Apr 10, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
int main(void)
{
	UI n, *v=0, *w=0;
	printf("n=");
	scanf("%u", &n);
	printf("Introduceti elementele vectorului: \n");
	v=citireVector(n);
	w=vectorSumaCifre(v, n);
	free(v);
	printf("Vectorul care contine suma cifrelor componentelor: \n");
	afisareVector(w, n);
	free(w);
	return 0;
}
