/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "heron.h"
int main(void)
{
	double a, b, c, A; //A=aria
	int valid;
	do {
		printf("Dati laturile triunghiului:\n"); //citim cele 3 laturi
		printf("a=");
		scanf("%lf", &a);
		printf("b=");
		scanf("%lf", &b);
		printf("c=");
		scanf("%lf", &c);
		valid=validare(a, b, c); //validam dimensiunile laturilor; rezultatul validarii (1 sau 0) este depus in variabila valid
		if (valid==0) //daca validarea a esuat, adica a returnat 0, afisam eroare
		{
			printf("%.2lf, %.2lf si %.2lf nu pot reprezenta laturile unui trinunghi. Reintroduceti laturile.\n", a, b, c);
		}
	} while (valid==0); //citirea laturilor se repeta cat timp utilizatorul introduce dimensiuni invalide
	A=heron(a, b, c); //calculam aria triunghiului folosind functia heron creata si depunem rezultatul in variabila A
	printf("Aria este A=%lf\n", A); //afisam aria
	return 0;
}
