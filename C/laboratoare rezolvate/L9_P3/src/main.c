/*
 * main.c
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "subsir.h"
int main(void)
{
	char *text[L], *subsir1=0, *subsir2=0;
	int nl, opt, i, start, stop, numarCaractere;
	printf("Introduceti textul (de cel mult 50 de linii):\n");
	nl=citireText(text, L);
	printf("\nTextul citit este:\n");
	afisareText(text, nl);
	do {
		printf("\nAlegeti o optiune:\n1.SUBSIR FUNCTIE 1\n2.SUBSIR FUNCTIE 2\n");
		scanf("%d", &opt);
		switch(opt)
		{
		case 1:
			printf("Introduceti pozitia de start: ");
			scanf("%d", &start);
			printf("Introduceti pozitia de stop: ");
			scanf("%d", &stop);
			for (i=0; i<nl; ++i)
			{
				subsir1=substr(*(text+i), start, stop);
				puts(subsir1);
				free(subsir1);
				subsir1=0;
			}
			;
		break;
		case 2:
			printf("Introduceti pozitia de start: ");
			scanf("%d", &start);
			printf("Introduceti numarul de caractere: ");
			scanf("%d", &numarCaractere);
			for (i=0; i<nl; ++i)
			{
				subsir2=str(*(text+i), start, numarCaractere);
				puts(subsir2);
				free(subsir2);
				subsir2=0;
			}
			;
		break;
		default: printf("Optiunea introdusa este invalida.\n");
		break;
		}
	} while (opt!=1 && opt!=2);
	eliberareMemorie(text, nl);
	return 0;
}
