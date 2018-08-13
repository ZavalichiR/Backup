/*
 * main.c
 *
 *  Created on: Jun 1, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "transformare.h"
int main(void)
{
	long int x;
	char *sirCaractere;
	printf("x=");
	scanf("%ld", &x);
	sirCaractere=transformareToAscii(x);
	printf("Numarul transformat in sir de caractere este:\n");
	puts(sirCaractere);
	return 0;
}
