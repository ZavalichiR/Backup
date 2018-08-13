/*
 * subsiruri.c
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "subsiruri.h"
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
char *elim(char *a, const char *b)
{
	char *subsir, *aux, *aux2;
	int lungimeSubsir;
	aux=(char*)xmalloc(82*sizeof(char));
	aux2=(char*)xmalloc(82*sizeof(char));
	lungimeSubsir=strlen(b);
	subsir=strstr(a, b);
	while (subsir!=NULL)
	{
		strcpy(aux, subsir);
		puts(aux);
		strcpy(aux, aux+strlen(subsir));
		strncat(aux2, a, (strlen(a)-strlen(aux)-1));
		strcat(aux2, aux);
		subsir=strstr(subsir+lungimeSubsir, b);
	}
	free(aux);
	aux=0;
	free(aux2);
	aux2=0;
	return aux2;
}
