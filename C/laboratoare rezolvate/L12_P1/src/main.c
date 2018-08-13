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
	int c;
	if (argc!=2)
	{
		fprintf(stderr, "Forma liniei de comanda trebuie sa fie:\n");
		fprintf(stderr, "%s nume_fisier\n", *argv);
		exit(EXIT_FAILURE);
	}
	in=fopen(*(argv+1), "r");
	if (in==0)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"%s\".\n", *(argv+1));
		exit(EXIT_FAILURE);
	}
	printf("\nContinutul fisierului este:\n\n");
	while ((c=fgetc(in))!=EOF)
	{
		putchar(c);
	}
	printf("\n");
	fclose(in);
	return 0;
	return 0;
}
