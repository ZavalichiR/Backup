/*
 * transformare.c
 *
 *  Created on: Jun 1, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "transformare.h"
void *xmalloc(size_t nrOcteti)
{
	void *p=0;
	p=malloc(nrOcteti);
	if (p==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei.\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
char *transformareToAscii(long int x)
{
	char *caractere=0;
	int numarCifre;
	numarCifre=floor(log10(abs(x)))+1;
	if (x<0)
	{
		++numarCifre;
	}
	caractere=(char*)xmalloc((numarCifre+1)*sizeof(char));
	int i, k;
	i=0;
	k=1;
	if (x<0)
	{
		*(caractere+i)='-';
		i=i+1;
		k=0;
	}
	x=abs(x);
	while (x)
	{
		*(caractere+numarCifre-k-i)='0'+x%10;
		x/=10;
		++i;
	}
	*(caractere+i)='\0';
	return caractere;
}
