/*
 * main.c
 *
 *  Created on: May 7, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "data.h"
int main(void)
{
	DATA d;
	int tip;
	do {
		printf("Alegeti tipul de conversie: \n1.CONVERSIE 1\n2.CONVERSIE 2 ");
		scanf("%d", &tip);
		if (tip==1)
		{
			conversie1(&d);
			printf("Ziua din an: %d\n", d.ziAn);
		}
		else if (tip==2)
		{
			conversie2(&d);
			printf("Ziua din luna: %d\n", d.zi);
			printf("Luna: %d\n", d.luna);
		}
		else {
			printf("Alegeti o conversie valida.\n");
		}
	} while (tip!=1 && tip!=2);
	return 0;
}
