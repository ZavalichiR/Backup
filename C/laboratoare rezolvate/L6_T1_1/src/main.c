/*
 * main.c
 *
 *  Created on: Mar 27, 2015
 *      Author: student
 */
#include <stdio.h>
#include "impachetare.h"
int main(void)
{
	WORD z, l, a;
	printf("Introduceti data in format zz/ll/aaaa: ");
	scanf("%2hu/%2hu/%4hu", &z, &l, &a); //citim data in format zz/ll/aaaa
	impachetare(z, l, a); //inpachetam data intr-un sir de 16 biti (2 octeti) si afisam acest sir de biti pe ecran
	printf("\n<     ><  ><   >\n   ^     ^   ^  \n  ANUL LUNA ZIUA\n");
	return 0;
}
