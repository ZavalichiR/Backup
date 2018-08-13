/*
 * main.c
 *
 *  Created on: Apr 10, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "multimi.h"
int main(void)
{
	UI rel;
	rel=1;

	MULTIME a, b, inters, dif_s, reun;
	a=citireMultime('A');
	b=citireMultime('B');
	while (rel==1)
	{
		printf("\n");
		afisareMultime(a);
		afisareMultime(b);
		UI x;
		x=alegeMeniu();
		switch (x)
		{
		case 1:
			inters=intersectie(a, b);
			printf("\nMultimea de intersectie este:\n");
			afisareMultime(inters);
		break;
		case 2:
			dif_s=diferentaSimetrica(a, b);
			printf("\nMultimea diferenta simetrica este:\n");
			afisareMultime(dif_s);
		break;
		case 3:
			reun=reuniune(a, b);
			printf("\nMultimea reuniune este:\n");
			afisareMultime(reun);
		break;
		default: printf("\nReluati programul si alegeti o optiune valida!\n");
		break;
		}

		printf("\nReluati programul? (DA=1 / NU=0) ");
		scanf("%u", &rel);
	}
	free(a.elemente);
	a.elemente=0;
	free(b.elemente);
	b.elemente=0;
	free(inters.elemente);
	inters.elemente=0;
	free(dif_s.elemente);
	dif_s.elemente=0;
	return 0;
}
