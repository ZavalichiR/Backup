/*
 * linii.c
 *
 *  Created on: Jun 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linii.h"

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
int citireText(FILE *in, char *text[], int lmax)
{
	int nl, lung;
	nl=0;
	char temp[81];
	while (fgets(temp, 80, stdin) && nl<lmax)
	{
		lung=strlen(temp);
		*(text+nl)=(char*)xmalloc((lung+1)*sizeof(char));
		strcpy(*(text+nl), temp);
		++nl;
	}
	return nl;
}
void afisareText(char *text[], int start, int stop)
{
	int i;
	for (i=start-1; i<stop; ++i)
	{
		fputs(*(text+i), stdout);
	}
}
void eliberareMemorie(char *text[], int nl)
{
	int i;
	for (i=0; i<nl; ++i)
	{
		free(*(text+i));
		*(text+i)=0;
	}
}
