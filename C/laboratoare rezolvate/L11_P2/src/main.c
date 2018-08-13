/*
 * main.c
 *
 *  Created on: May 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "integrale.h"
int main(void)
{
	double a, b, I1, I2;
	int n;
	printf("Integrala din sin(x^2+3x) dx\n");
	printf("Introduceti capetele de integrare: \n");
	printf("a=");
	scanf("%lf", &a);
	printf("b=");
	scanf("%lf", &b);
	printf("Introduceti numarul de puncte intermediare: ");
	scanf("%d", &n);
	I1=integralaTrapez(a, b, n, f1);
	printf("Integrala de la %.2lf la %.2lf din sin(x^2+3x) dx este: %lf\n", a, b, I1);
	printf("\nIntegrala din x^2+4x+e^x dx\n");
	printf("Introduceti capetele de integrare: \n");
	printf("a=");
	scanf("%lf", &a);
	printf("b=");
	scanf("%lf", &b);
	printf("Introduceti numarul de puncte intermediare: ");
	scanf("%d", &n);
	I2=integralaTrapez(a, b, n, f2);
	printf("Integrala de la %.2lf la %.2lf din x^2+4x+e^x dx este: %lf\n", a, b, I2);
	return 0;
}
