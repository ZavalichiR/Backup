/*
 * main.c
 *
 *  Created on: May 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "norme.h"
int main(void)
{
	double *v=0;
	int n;
	printf("Introduceti numarul de elemente ale vectorului: ");
	scanf("%d", &n);
	v=citireVector(n);
	printf("\nVectorul citit este:\n");
	afisareVector(v, n);
	char *msg="\nProgram de calcul al normelor unui vector n-dimensional\n";
	NORME tab[]={{"Norma 1", n1},
				{"Norma 2", n2},
				{"Norma infinit", ninf}};
	int nf, optiune;
	nf=sizeof(tab)/sizeof(*(tab+0));
	meniu(tab, nf, msg);
	scanf("%d", &optiune);
	while (optiune>=1 && optiune<=nf)
	{
		--optiune;
		printf("%s a vectorului citit este ", tab[optiune].nume);
		printf("%lf.\n", (*tab[optiune].f)(v, n));
		meniu(tab, nf, msg);
		scanf("%d", &optiune);
	}
	free(v);
	v=0;
	return 0;
}
