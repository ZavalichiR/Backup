/*
 * arie.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include "heron.h"
#include <math.h>

double sp(double a, double b, double c) //calculeaza semiperimetrul unui triunghi de laturi a, b, c
{
	double p;
	p=(a+b+c)/2;
	return p;
}

double heron(double a, double b, double c) //calculeaza aria triunghiului folosind formula lui Heron
{
	double A;
	double p;
	p=sp(a, b, c);
	A=sqrt(p*(p-a)*(p-b)*(p-c));
	return A;
}

int validare(double a, double b, double c) //valideaza laturile a, b, c al unui triunghi (numere pozitive + suma oricaror 2 din ele sa o depaseasca pe a 3-a)
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
