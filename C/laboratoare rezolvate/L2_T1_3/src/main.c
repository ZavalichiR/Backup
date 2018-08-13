/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "functie.h"
int main(void)
{
	double valf, x;
	printf("x=");
	scanf("%lf", &x); //citim x
	valf=f(x); //apelam functia f, care returneaza valoarea functiei pentru parametrul x dat, si il depune in variabila valf
	printf("f(%.2lf)=%.2lf\n", x, valf); //afisam valoarea functiei, numar real cu 2 zecimale
	return 0;
}
