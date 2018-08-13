/*
 * aparitii.c
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "aparitii.h"
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
int citireText(char *text[], int lmax)
{
	int nl, lungime;
	char temp[82];
	nl=0;
	while (fgets(temp, 81, stdin) && nl<lmax)
	{
		lungime=strlen(temp);
		*(temp+lungime-1)='\0';
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
		puts(*(text+i));
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
int nr_ap(char *sir, char*subsir)
{
	int numarAparitii;
	char *aparitie;
	numarAparitii=0;
	aparitie=strstr(sir, subsir);
	while (aparitie)
	{
		++numarAparitii;
		aparitie=aparitie+strlen(subsir)-1;
		aparitie=strstr(aparitie, subsir);
	}
	return numarAparitii;
}
