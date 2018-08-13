/*
 * main.c
 *
 *  Created on: Apr 30, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "ordonare.h"
int main(void)
{
	FILE *in;
	char *text[L];
	int nl=0;
	int opt;
	in=fopen("text.in", "r");
	if (in==0)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului de intrare \"text.in\".\n");
		exit(EXIT_FAILURE);
	}
	nl=citireText(in, text, L);
	if (nl>0)
	{
		printf("Textul citit este:\n");
		afisareText(text, nl);
		do {
			printf("\nAlegeti optiunea dorita:\n1.ORDONARE DUPA LUNGIMEA LINIILOR\n2.ORDONARE ALFABETICA\n");
			scanf("%d", &opt);
			switch (opt)
			{
			case 1:
				sortareLungime(text, nl);
				printf("Textul sortat dupa lungimea liniilor:\n");
				afisareText(text, nl);
				break;
			case 2:
				sortareAlfabetica(text, nl);
				printf("Textul sortat in ordine alfabetica:\n");
				afisareText(text, nl);
				break;
			default: printf("Alegeti o optiune valida!\n");
			break;
			}
		} while (opt!=1 && opt!=2);
		eliberareMemorie(text, nl);
	}
	else {
		printf("Nu exista text in fisier!\n");
	}
	return 0;
}

