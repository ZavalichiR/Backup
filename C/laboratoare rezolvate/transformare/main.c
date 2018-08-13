/*
 * main.c
 *
 *  Created on: Jun 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char*argv[])
{
	FILE *in=0;
	int optiune='l';
	int c;
	if (argc<=1)
	{
		fprintf(stderr, "Linie de comanda incorecta. Prea putine argumente.\n");
		fprintf(stderr, "Forma corecta este: %s [-l | -L] nume_fisier\n", *argv);
		exit(EXIT_FAILURE);
	}
	else if (argc==2)
	{
		if (**(argv+1)=='-')
		{
			fprintf(stderr, "Linie de comanda incorecta.\n");
			fprintf(stderr, "Forma corecta este: %s [-l | -L] nume_fisier\n", *argv);
			exit(EXIT_FAILURE);
		}
		else
		{
			in=fopen(*(argv+1), "r");
			if (in==0)
			{
				fprintf(stderr, "Eroare la deschiderea fisierului \"%s\".\n", *(argv+1));
				exit(EXIT_FAILURE);
			}
		}
	}
	else if (argc==3)
	{
		if (**(argv+1)=='-')
		{
			optiune=*(*(argv+1)+1);
			if (optiune!='l' && optiune!='L')
			{
				fprintf(stderr, "Linie de comanda incorecta.\n");
				fprintf(stderr, "Forma corecta este: %s [-l | -L] nume_fisier\n", *argv);
				exit(EXIT_FAILURE);
			}
			in=fopen(*(argv+2), "r");
			if (in==0)
			{
				fprintf(stderr, "Eroare la deschiderea fisierului \"%s\".\n", *(argv+2));
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			fprintf(stderr, "Linie de comanda incorecta.\n");
			fprintf(stderr, "Forma corecta este: %s [-l | -L] nume_fisier\n", *argv);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "Linie de comanda incorecta. Prea multe argumente.\n");
		fprintf(stderr, "Forma corecta este: %s [-l | -L] nume_fisier\n", *argv);
		exit(EXIT_FAILURE);
	}
	printf("\nCaracterele transformate: \n\n");
	while ((c=fgetc(in))!=EOF)
	{
		switch(optiune)
		{
		case 'l':
			if (c<='Z' && c>='A')
			{
				c+='a'-'A';
			};
		break;
		case 'L':
			if (c<='z' && c>='a')
			{
				c-='a'-'A';
			};
		break;
		}
		fputc(c, stdout);
	}
	fclose(in);
	return 0;
}
