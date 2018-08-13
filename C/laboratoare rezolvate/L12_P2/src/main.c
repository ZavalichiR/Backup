/*
 * main.c
 *
 *  Created on: Jun 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char*argv[])
{
	if (argc<2)
	{
		fprintf(stderr, "Linia de comanda trebuie sa fie de forma:\n");
		fprintf(stderr, "%s *.c\n", *argv);
		exit(EXIT_FAILURE);
	}
	int c;
	FILE *in=0;
	FILE *out=0;
	out=fopen("final.c", "w");
	if (out==0)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului de iesire \"final.c\".\n");
		exit(EXIT_FAILURE);
	}
	int i;
	i=1;
	while (*(argv+i)!=0)
	{
		if (strcmp(*(argv+i), "final.c"))
		{
			in=fopen(*(argv+i), "r");
			if (in==0)
			{
				fprintf(stderr, "Eroare la deschiderea fisierului de intrare \"%s\".\n", *(argv+i));
				exit(EXIT_FAILURE);
			}
			fprintf(out, "-----------------%s-----------------\n", *(argv+i));
			while ((c=fgetc(in))!=EOF)
			{
				fputc(c, out);
			}
			fputc('\n', out);
			fclose(in);
		}
		++i;
	}
	fclose(out);
	return 0;
}
