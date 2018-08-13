/*
 * main.c
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "conversie.h"
int main(void)
{
	char *x=0, *x_conv=0, aux;
	int baza_1, baza_2, l, i, x_10, rest;
	x=(char*)xmalloc(32*sizeof(char));
	printf("Introduceti numarul de convertit: ");
	fgets(x, 31, stdin);
	printf("Introduceti baza de numeratie in care este reprezentat numarul introdus: ");
	scanf("%d", &baza_1);
	printf("Introduceti baza de numeratie in care sa fie convertit numarul introdus: ");
	scanf("%d", &baza_2);
	*(x+strlen(x)-1)='\0';
	l=strlen(x)-1;
	x_10=0;
	for (i=l; i>=0; --i)
	{
		if ('0'<=*(x+i) && *(x+i)<='9')
		{
			x_10+=(*(x+i)-'0')*pow(baza_1, l-i);
		}
		else
		{
			x_10+=(*(x+i)-'A'+10)*pow(baza_1, l-i);
		}
	}
	x_conv=(char*)xmalloc(32*sizeof(char));
	i=0;
	while (x_10)
	{
		rest=x_10%baza_2;
		if (rest<10)
		{
			*(x_conv+i)='0'+rest;
		}
		else {
			*(x_conv+i)='A'+rest-10;
		}
		x_10/=baza_2;
		++i;
	}
	l=strlen(x_conv)-1;
	for (i=0; i<(l+1)/2; ++i)
	{
		aux=*(x_conv+i);
		*(x_conv+i)=*(x_conv+l-i);
		*(x_conv+l-i)=aux;
	}
	printf("Numarul %s in baza %d este %s.\n", x, baza_2, x_conv);
	free(x);
	free(x_conv);
	x=0;
	x_conv=0;
	return 0;
}
