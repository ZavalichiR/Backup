/*
 * main.c
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aparitii.h"
int main(void)
{
	int nl, numarAparitii, i;
	char *text[L], *sirCautat=0;
	printf("Introduceti textul linie cu linie:\n");
	nl=citireText(text, L);
	printf("\nTextul introdus este:\n");
	afisareText(text, nl);
	printf("\nIntroduceti sirul de caractere de cautat: ");
	sirCautat=(char*)xmalloc(32*sizeof(char));
	fgets(sirCautat, 31, stdin);
	*(sirCautat+strlen(sirCautat)-1)='\0';
	for (i=0; i<nl; ++i)
	{
		numarAparitii=nr_ap(*(text+i), sirCautat);
		printf("\tIn linia %d, sirul \"%s\" apare de %d ori.\n", i+1, sirCautat, numarAparitii);
	}
	eliberareMemorie(text, nl);
	return 0;
}
