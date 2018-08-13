/*
 * main.c
 *
 *  Created on: Apr 18, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "paritate.h"
int main(void)
{
	L_INT x;
	printf("x=");
	scanf("%lu", &x); //citim de la tastatura numarul intreg lung fara semn
	printf("Numarul initial: \n");
	afisareBinara(x); //afisam sirul initial de biti ai numarului
	x=paritate(x); //apelam functia paritate, care returneaza numarul, caruia i-a fost inlocuit bit-ul cel mai semnificativ cu bitul de paritate para
	printf("\nNumarul final, cu MSB inlocuit cu bitul de paritate para:\n");
	afisareBinara(x); //afisam sirul final de biti
	printf("\n");
	return 0;
}
