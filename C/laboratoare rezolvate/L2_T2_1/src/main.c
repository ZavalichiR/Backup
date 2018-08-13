/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "ecuatie.h"
int main(void)
{
	double a, b, c;
	printf("Rezolvarea ecuatiei ax^2+bx+c=0\n");
	printf("a="); //citim coeficientii a, b, c
	scanf("%lf", &a);
	printf("b=");
	scanf("%lf", &b);
	printf("c=");
	scanf("%lf", &c);
	rezolvare(a, b, c); //apelam functia rezolvare(), care, pe baza coeficientilor a, b, c, decide numarul de radacini reale ale ecuatiei
	return 0;
}
