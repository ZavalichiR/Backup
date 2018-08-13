/*
 * cuvinte.c
 *
 *  Created on: Apr 30, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cuvinte.h"
void *xmalloc(int nrOcteti)
{
	void *p=0;
	p=(char*)malloc(nrOcteti*sizeof(char));
	if (p==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei!\n");
		exit(EXIT_FAILURE);
	}
	return p;
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
int citireText(char *text[], int lMax)
{
	int nl=0;
	char temp[82];
	int lungime;
	while (nl<lMax && fgets(temp, 81, stdin))
	{
		lungime=strlen(temp);
		temp[lungime-1]='\0';
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
void nrCuvinte(char *text[], int nl)
{
	int i, nr_cuv;
	char sep[]="\n\t\r.!?, ";
	printf("\n");
	char *p;
	for (i=0; i<nl; ++i)
	{
		nr_cuv=0;
		p=strtok(text[i], sep);
		do {
			nr_cuv++;
			p=strtok(NULL, sep);
		} while (p!=NULL);
		printf("Linia %d are %d cuvinte.\n", i+1, nr_cuv);
	}
	printf("\n");
}
void afisareCuvinte(char *text[], int nl, int nr_linie)
{
	char sep[]="\n\t\r.!?, ";
	char *p;
	printf("\n");
	printf("Cuvintele de pe linia %d sunt:\n", nr_linie);
	p=strtok(text[nr_linie-1], sep);
	while (p!=NULL)
	{
		printf("\t%s\n", p);
		p=strtok(NULL, sep);
	}
	printf("\n");
}
