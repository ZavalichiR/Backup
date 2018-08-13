/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "triunghi.h"
int main(void)
{
	unsigned int a, b, c;
	int valid;
	printf("Dati laturile triunghiului:\n"); //citim laturile triunghiului
	printf("a=");
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);
	printf("c=");
	scanf("%d", &c);
	valid=validare(a, b, c); //validam dimensiunile citite, rezultatul se stocheaza in variabila valid (1 sau 0)
	if (valid==1) //daca dimensiunile sunt valide verificam tipul triunghiului folosind functiile create
	{
		if (echilateral(a, b, c))//am testat intai daca triunghiul este echilateral, si apoi isoscel, deoarece in cazul unui triunghi echilateral, functia isoscel() ar fi returnat un rezultat pozitiv!
		{
			printf("Triunghiul este echilateral.\n");
		}
		else if (isoscel(a, b, c))
		{
			printf("Triunghiul este isoscel.\n");
		}
		else if (dreptunghic(a, b, c))
		{
			printf("Triunghiul este dreptunghic.\n");
		}
		else { //daca triunghiul nu se incadreaza in niciun tip de mai sus, atunci el este oarecare (scalen)
			printf("Triunghiul este scalen.\n");
		}
	}
	else { //daca dimensiunile nu sunt valide, afisam un mesaj in acest sens
		printf("%d, %d si %d nu pot reprezenta laturile unui triunghi.\n", a, b, c);
	}
	return 0;
}
