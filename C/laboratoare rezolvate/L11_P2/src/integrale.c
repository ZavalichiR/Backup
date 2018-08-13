/*
 * integrale.c
 *
 *  Created on: May 14, 2015
 *      Author: skynet
 */
#include <math.h>
#include "integrale.h"
double integralaTrapez(double a, double b, int n, double(*f)(double x))
{
	double val;
	double dx=(b-a)/n;
	double x;
	val=((*f)(a)+(*f)(b))/2;
	for (x=a+dx; x<b; x+=dx)
	{
		val+=(*f)(x);
	}
	val=val*dx;
	return val;
}
double f1(double x)
{
	double val_f1;
	val_f1=sin(x*x+3*x);
	return val_f1;
}
double f2(double x)
{
	double val_f2;
	val_f2=x*x+4*x+exp(x);
	return val_f2;
}
