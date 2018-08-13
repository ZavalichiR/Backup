/*
 * main.c
 *
 *  Created on: Apr 30, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "cuvinte.h"
int main(void)
{
	char *text[L];
	int nl, linie;
	printf("Introduceti textul, linie cu linie: \n");
	nl=citireText(text, L);
	printf("\nTextul introdus este:\n");
	afisareText(text, nl);
	printf("\nNumarul de cuvinte de pe fiecare linie:\n");
	nrCuvinte(text, nl);
	printf("Introduceti numarul liniei de pe care sa fie afisate cuvintele: ");
	scanf("%d", &linie);
	afisareCuvinte(text, nl, linie);
	return 0;
}
