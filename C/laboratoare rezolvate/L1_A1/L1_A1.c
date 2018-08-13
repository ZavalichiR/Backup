/*
 * L1_A1.c
 *
 *  Created on: Feb 25, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "arie.h"
int main(void)
{
	double a, b, c, A;
	int valid;
	do {
		printf("Dati laturile triunghiului:\n"); //citim dimensiunile
		printf("a=");
		scanf("%lf", &a);
		printf("b=");
		scanf("%lf", &b);
		printf("c=");
		scanf("%lf", &c);
		valid=validare(a, b, c); //validam dimensiunile citite
		if (valid==0) //daca a, b, c nu trec de validare, afisam eroare
		{
			printf("%.2lf, %.2lf si %.2lf nu pot reprezenta laturile unui trinunghi. Reintroduceti laturile.\n", a, b, c);
		}
	} while (valid==0); //repetam operatia de citire cat timp dimensiunile introduse corespund unui triunghi
	A=arie(a, b, c); //calculam aria
	printf("Aria este A=%lf\n", A); //afisam aria
	return 0;
}
