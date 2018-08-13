/*
 * main.c
 *
 *  Created on: Apr 17, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "conversie.h"
int main(void)
{
	unsigned long x;
	char s[102];
	printf("Introduceti numarul in baza 10: ");
	scanf("%lu", &x); //citim numarul natural x de la tastatura
	conversie(x, s); //convertim numarul citit in baza 16 si depunem rezultatul in sirul de caractere s
	puts(s); //afisam sirul de caractere obtinut pe ecran folosind functia puts()
	return 0;
}
