/*
 * main.c
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "subsiruri.h"
int main(void)
{
	char *a=0, *b=0;
	a=(char*)xmalloc(82*sizeof(char));
	b=(char*)xmalloc(42*sizeof(char));
	printf("Introduceti sirul de caractere: ");
	fgets(a, 81, stdin);
	*(a+strlen(a)-1)='\0';
	printf("Introduceti subsirul ce va fi eliminat: ");
	fgets(b, 41, stdin);
	*(b+strlen(b)-1)='\0';
	a=elim(a, b);
	printf("Sirul de caractere dupa eliminarea subsirului:\n");
	puts(a);
	free(a);
	a=0;
	free(b);
	b=0;
	return 0;
}
