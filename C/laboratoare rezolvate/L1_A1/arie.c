/*
 * arie.c
 *
 *  Created on: Feb 25, 2015
 *      Author: skynet
 */
#include <math.h>
#include "arie.h"

double sp(double a, double b, double c) //calculeaza semiperimetrul
{
	double p;
	p=(a+b+c)/2;
	return p;
}

double arie(double a, double b, double c) //calculeaza aria
{
	double A;
	double p;
	p=sp(a, b, c);
	A=sqrt(p*(p-a)*(p-b)*(p-c));
	return A;
}

int validare(double a, double b, double c) //valideaza dimensiunile triunghiului (numere pozitive + suma a oricaror 2 sa o depaseasca pe a 3-a)
{
	int ok;
	if (a>0 && b>0 && c>0 && (a+b)>c && (a+c)>b && (b+c)>a)
		{
		ok=1;
		}
	else {
		ok=0;
	}
	return ok;
}
