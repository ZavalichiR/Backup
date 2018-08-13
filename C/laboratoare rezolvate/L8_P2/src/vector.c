/*
 * vector.c
 *
 *  Created on: Apr 10, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
UI *xmalloc(UI n)
{
	UI *p=0;
	p=(UI*)malloc(sizeof(UI)*n);
	if (!p)
	{
		fprintf(stderr, "Eroare la alocarea memoriei!\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
UI *citireVector(UI n)
{
	UI *v=0;
	v=xmalloc(n);
	int i;
	for (i=0; i<n; ++i)
	{
		printf("Elementul %u: ", i+1);
		scanf("%u", v+i);
	}
	return v;
}
void afisareVector(UI *v, UI n)
{
	int i;
	printf("(");
	for (i=0; i<n; ++i)
	{
		printf("%u%c%c", *(v+i), (i==n-1)?')':',', (i==n-1)?'\n':' ');
	}
}
UI sumaCifre(UI x)
{
	UI s;
	s=0;
	while (x)
	{
		s+=x%10;
		x/=10;
	}
	return s;
}
UI *vectorSumaCifre(UI *v, UI n)
{
	UI *vsc=0;
	vsc=xmalloc(n);
	int i;
	for (i=0; i<n; ++i)
	{
		*(vsc+i)=sumaCifre(*(v+i));
	}
	return vsc;
}
UI maxim(UI *v, UI n)
{
	UI poz, max;
	max=*(v);
	poz=0;
	int i;
	for (i=1; i<n; ++i)
	{
		if (*(v+i)>max)
		{
			max=*(v+i);
			poz=i;
		}
	}
	return poz;
}
