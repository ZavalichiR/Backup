/*
 * functie.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <math.h>
#include "functie.h"
double f(double x)
{
	double valf;
	if (x<=2) //daca x<=2, atunci calculam valoarea functiei folosind prima ramura
	{
		valf=x*x+3*x+5;
	}
	else if (x<8) //daca x<8, atunci calculam valoarea functiei folosind a doua ramura
	//nu am mai testat ca x sa fie >=2, pentru ca acest test a fost deja facut mai sus. Suntem pe ramura else de la primul if, deci x este deja >2
	{
		valf=3*x;
	}
	else { //daca x nu este in primele 2 intervale, calculam valoarea functiei folosind ultima ramura
		valf=exp(x)+2;
	}
	return valf;
}
