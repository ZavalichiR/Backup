/*
 * main.c
 *
 *  Created on: Jun 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <string.h>
#include "nrcuvinte.h"
int main(int argc, char*argv[])
{
	int caractere=0;
	int cuvinte=0;
	int linii=0;
	int i, j;
	int ch;
	int in_word=NO;
	int cflag=YES;
	int wflag=YES;
	int lflag=YES;
	int li;
	if (argc>1)
	{
		cflag=NO;
		wflag=NO;
		lflag=NO;
		for (i=1; i<argc; ++i)
		{
			if (**(argv+i)!='-')
			{
				eroare(*argv, *(argv+i), "nu este o optiune valida.");
			}
			else
			{
				li=strlen(*(argv+i));
				for (j=1; j<li; ++j)
				{
					switch(*(*(argv+i)+j))
					{
					case 'l': lflag=YES;
					break;
					case 'w': wflag=YES;
					break;
					case 'c': cflag=YES;
					break;
					default: eroare(*argv, *(argv+i), "nu este o optiune valida.");
					}
				}
			}
		}
	}
	while ((ch=fgetc(stdin))!=EOF)
	{
		++caractere;
		switch(ch)
		{
		case '\n': ++linii;
		case '\t':
		case ' ':
			if (in_word==YES)
			{
				++cuvinte;
				in_word=NO;
			}
			break;
		default: in_word=YES;
		}
	}
	if (lflag)
	{
		printf("Numarul de linii este: %d\n", linii);
	}
	if (wflag)
	{
		printf("Numarul de cuvinte este: %d\n", cuvinte);
	}
	if (cflag)
	{
		printf("Numarul de caractere este: %d\n", caractere);
	}
	return 0;
}
