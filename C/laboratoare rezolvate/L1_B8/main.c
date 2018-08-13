/*
 * L1_B8.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "recurenta.h"
int main(void)
{
	double a, b, c;
	unsigned int n;
	double valSN;
	printf("a="); //citim coeficientii a, b, c
	scanf("%lf", &a);
	printf("b=");
	scanf("%lf", &b);
	printf("c=");
	scanf("%lf", &c);
	printf("n=");
	scanf("%u", &n); //citim n
	valSN=sn(n, a, b, c); //calculam valoarea lui SN ca functie recursiva (sir recurent de grad 2)
	printf("x1^%d+x2^%d+x3^%d=%lf\n", n, n, n, valSN); //afisam rezultatul
	return 0;
}
