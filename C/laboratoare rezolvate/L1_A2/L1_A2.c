/*
 * L1_A2.c
 *
 *  Created on: Feb 25, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "cat.h"
int main(void)
{
	int a, b, valid, cat;
	do { //citim cele 2 numere
		printf("a=");
		scanf("%d", &a);
		printf("b=");
		scanf("%d", &b);
		valid=validare(a, b); //apelam functia validare, rezultatul ei se pune in variabila valid
		if (valid==0) //daca validarea a returnat 0
		{
			printf("Impartitorul trebuie sa fie nenul! Reintroduceti numerele.\n"); //afisam eroare
		}
	} while (valid==0); //repetam citirea cat timp numerele sunt validate corect
	if (a>b) //calculam catul prin impartirea intreaga a numarului mai mare la cel mai mic
		{
		cat=a/b;
		}
	else {
		cat=b/a;
	}
	printf("Catul este %d\n", cat); //afisam catul
	return 0;
}
