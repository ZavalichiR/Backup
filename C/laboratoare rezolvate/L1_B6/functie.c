/*
 * functie.c
 *
 *  Created on: Apr 13, 2015
 *      Author: skynet
 */
#include <math.h>
#include "functie.h"
unsigned int factorial(unsigned int x) //calculeaza factorialul unui numar dat ca parametru
{
	unsigned int valFact;
	int i;
	valFact=1;
	for (i=1; i<=x; ++i)
		valFact*=i;
	return valFact;
}
double sumJ0(double x, unsigned int p) //calculeaza suma J0 pentru un p dat ca parametru
{
	double valSumJ0;
	int k;
	valSumJ0=0;
	for (k=0; k<=p; ++k)
	{
		valSumJ0+=pow(-1, k)*pow(x/2, 2*k)/pow(factorial(k), 2);
	}
	return valSumJ0;
}
double sumJ1(double x, unsigned int p) //calculeaza suma J1 pentru un p dat ca parametru
{
	double valSumJ1;
	int k;
	valSumJ1=0;
	for (k=0; k<=p; ++k)
	{
		valSumJ1+=pow(-1, k)*pow(x/2, 2*k+1)/(factorial(k)*factorial(k+1));
	}
	return valSumJ1;
}
double JN(double x, unsigned int n, double J0, double J1) //calculeaza recurenta de gradul 2 JN(x) ca o functie recursiva
{
	if (n==0)
	{
		return J0;
	}
	else if (n==1)
	{
		return J1;
	}
	else {
		return (2*n-2)/x*JN(x, n-1, J0, J1)-JN(x, n-2, J0, J1);
	}
}
