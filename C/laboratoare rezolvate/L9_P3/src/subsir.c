/*
 * subsir.c
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subsir.h"
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
char *substr(char *sir, int start, int stop)
{
	char *subsir=0;
	subsir=(char*)xmalloc((stop-start+2)*sizeof(char));
	strncpy(subsir, sir+start, stop-start+1);
	return subsir;
}
char *str(char *sir, int start, int nr_car)
{
	char *subsir=0;
	subsir=(char*)xmalloc((nr_car+1)*sizeof(char));
	strncpy(subsir, sir+start, nr_car);
	return subsir;
}
int citireText(char *text[], int lmax)
{
	int nl=0;
	char temp[82];
	while (nl<lmax && fgets(temp, 81, stdin))
	{
		*(text+nl)=(char*)xmalloc((strlen(temp)+1)*sizeof(char));
		strcpy(*(text+nl), temp);
		++nl;
	}
	return nl;
}
void afisareText(char *text[], int nl)
{
	int i;
	for (i=0; i<nl; ++i)
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
