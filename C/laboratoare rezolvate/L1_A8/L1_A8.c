/*
 * L1_A8.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
int main(void)
{
	double x, f;
	printf("x=");
	scanf("%lf", &x); //citim x
	if (x<=2) //daca x<=2 calculam functia folosind prima ramura
	{
		f=x*x+3*x+5;
	}
	else if (x<8) //daca x este in intervalul (2, 8) calculam functia folosind a doua ramura
	//nu am mai pus testul x>2, deoarece nu este necesar; mai sus, am verificat deja x<=2. Daca nu se intampla acest lucru (suntem pe else), atunci e clar ca x>2.
	{
		f=3*x;
	} //daca nu suntem in cele 2 cazuri de mai sus, folosim a 3-a ramura pentru a calcula functia
	else {
		f=exp(x)+2;
	}
	printf("f(%.2lf)=%.2lf\n", x, f); //afisam rezultatul (numar real cu 2 zecimale)
	return 0;
}
