/*
 * main.c
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "sir.h"
int main(void)
{
	int lung_int, lung_zec, i, zec=0;
	double x=0;
	char *sir=0;
	sir=(char*)xmalloc(66*sizeof(char));
	printf("Introduceti sirul de forma [ddd][.][ddd]: ");
	fgets(sir, 31, stdin);
	if (strchr(sir, '.'))
	{
		zec=1;
	}
	*(sir+strlen(sir)-1)='\0';
	char *p=0;
	p=strtok(sir, ".");
	lung_int=strlen(p);
	for (i=0; i<lung_int; ++i)
	{
		x+=(*(p+i)-'0')*pow(10, lung_int-i-1);
	}
	if (zec)
	{
		p=strtok(NULL, ".");
		lung_zec=strlen(p);
		for (i=0; i<lung_zec; ++i)
		{
			x+=(*(p+i)-'0')*pow(10, -(i+1));
		}
	}
	if (zec)
	{
		printf("Numarul real corespunzator este: %lf\n", x);
	}
	else {
		printf("Numarul real corespunzator este: %d\n", (int)x);
	}
	free(sir);
	sir=0;
	return 0;
}
