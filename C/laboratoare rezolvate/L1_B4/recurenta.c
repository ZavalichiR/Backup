/*
 * recurenta.c
 *
 *  Created on: Apr 13, 2015
 *      Author: skynet
 */
#include <math.h>
#include "recurenta.h"
double calcul_termen_sir(double x, double a, unsigned int p) //calculeaza urmatorul termen al sirului (xn) pe baza unui termen anterior
{
	double val_termen_nou;
	val_termen_nou=1/(double)p*((p-1)*x+a/pow(x, p-1));
	return val_termen_nou;
}
