/*
 * main.c
 *
 *  Created on: Jun 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	long int x;
	FILE *pare=0, *impare=0;
	if (argc<3)
	{
		fprintf(stderr, "Linie de comanda incorecta. Prea putine argumente.\n");
		fprintf(stderr, "Forma liniei de comanda este: %s fisier_numere_pare fisier_numere_impare\n", *argv);
		exit(EXIT_FAILURE);
	}
	else if (argc==3)
	{
		pare=fopen(*(argv+1), "w");
		if (pare==0)
		{
			fprintf(stderr, "Eroare la deschiderea fisierului de iesire \"%s\".\n", *(argv+1));
			exit(EXIT_FAILURE);
		}
		impare=fopen(*(argv+2), "w");
		if (impare==0)
		{
			fprintf(stderr, "Eroare la deschiderea fisierului de iesire \"%s\".\n", *(argv+2));
			exit(EXIT_FAILURE);
		}
		printf("Introduceti sirul de numere:\n");
		while (scanf("%ld", &x)!=EOF)
		{
			if ((x&1u)==0)
			{
				fprintf(pare, "%ld; ", x);
			}
			else
			{
				fprintf(impare, "%ld; ", x);
			}
		}
	}
	else
	{
		fprintf(stderr, "Linie de comanda incorecta. Prea multe argumente.\n");
		fprintf(stderr, "Forma liniei de comanda este: %s fisier_numere_pare fisier_numere_impare\n", *argv);
		exit(EXIT_FAILURE);
	}
	fclose(pare);
	fclose(impare);
	return 0;
}
