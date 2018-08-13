/*
 * main.c
 *
 *  Created on: Jun 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "linii.h"
int main(int argc, char*argv[])
{
	if (argc>2)
	{
		fprintf(stderr, "Linie de comanda incorecta. Prea multe argumente.\n");
		fprintf(stderr, "Forma liniei de comanda este: %s [linie_inceput-linie_sfarsit | linie_inceput- | -linie_sfarsit]\n", *argv);
		exit(EXIT_FAILURE);
	}
	int start, stop;
	char *text[L];
	int nl;
	int a, b, n;
	int flag_toate=NO;
	int flag_incepand=NO;
	int flag_panaLa=NO;
	int flag_intre=NO;
	if (argc==1)
	{
		flag_toate=YES;
	}
	else
	{
		n=sscanf(*(argv+1), "%d-%d", &a, &b);
		if (n==1 && a>0)
		{
			flag_incepand=YES;
		}
		else if (n==1 && a<0)
		{
			flag_panaLa=YES;
		}
		else if (n==2 && a>0 && b>0)
		{
			flag_intre=YES;
		}
		else
		{
			fprintf(stderr, "Linie de comanda incorecta.\n");
			fprintf(stderr, "Forma liniei de comanda este: %s [linie_inceput-linie_sfarsit | linie_inceput- | -linie_sfarsit]\n", *argv);
			exit(EXIT_FAILURE);
		}
	}
	printf("Introduceti textul linie cu linie:\n");
	nl=citireText(stdin, text, L);
	if (flag_toate)
	{
		start=1;
		stop=nl;
		printf("\nSe afiseaza toate liniile:\n");
	}
	if (flag_incepand)
	{
		start=a;
		stop=nl;
		printf("\nSe afiseaza incepand de la linia %d:\n", start);
	}
	if (flag_panaLa)
	{
		start=1;
		stop=abs(a);
		printf("\nSe afiseaza pana la linia %d:\n", stop);
	}
	if (flag_intre)
	{
		start=a;
		stop=b;
		printf("\nSe afiseaza intre liniile %d si %d:\n", start, stop);
	}

	printf("\n");
	afisareText(text, start, stop);
	printf("\n");
	return 0;
}
