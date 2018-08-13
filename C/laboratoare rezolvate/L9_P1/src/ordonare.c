/*
 * ordonare.c
 *
 *  Created on: Apr 30, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ordonare.h"
void *xmalloc(int nrOcteti)
{
	void *p=0;
	p=malloc(nrOcteti*sizeof(char));
	if (p==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei!\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
int citireText(FILE *in, char *text[], int lMax)
{
	int nl;
	char temp[81];
	nl=0;
	while (fgets(temp, 80, in) && nl<lMax)
	{
		text[nl]=(char*)xmalloc((strlen(temp)+1)*sizeof(char));
		strcpy(text[nl], temp);
		++nl;
	}
	return nl;
}
void afisareText(char *text[], int nl)
{
	int i;
	for (i=0; i<nl; ++i)
	{
		puts(text[i]);
	}
}
void schimbaP(char **p1, char **p2)
{
	char *aux;
	aux=*p1;
	*p1=*p2;
	*p2=aux;
}
void eliberareMemorie(char *text[], int nl)
{
	int i;
	for (i=0; i<nl; ++i)
	{
		free(text[i]);
		text[i]=0;
	}
}
void sortareLungime(char *text[], int nl)
{
	int i, ok, k;
	k=nl-1;
	do {
		ok=0;
		for (i=0; i<k; ++i)
		{
			if (strlen(text[i])>strlen(text[i+1]))
			{
				schimbaP(&text[i], &text[i+1]);
				ok=1;
			}
		}
	} while (ok==1);
}
void sortareAlfabetica(char *text[], int nl)
{
	int i, ok, k;
	k=nl-1;
	do {
		ok=0;
		for (i=0; i<k; ++i)
		{
			if (strcmp(text[i], text[i+1])>0)
			{
				schimbaP(&text[i], &text[i+1]);
				ok=1;
			}
		}
	} while (ok==1);
}
