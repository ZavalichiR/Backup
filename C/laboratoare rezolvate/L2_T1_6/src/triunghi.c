/*
 * triunghi.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include "triunghi.h"
int validare(unsigned int a, unsigned int b, unsigned int c) //valideaza dimensiunile unui triunghi de laturi a, b, c (numere pozitive + suma a oricaror 2 sa o depaseasca pe a 3-a)
{
	int ok;
	if (a>0 && b>0 && c>0 && a+b>c && a+c>b && b+c>a)
	{
		ok=1;
	}
	else {
		ok=0;
	}
	return ok;
}
int isoscel(unsigned int a, unsigned int b, unsigned int c) //verifica daca triunghiul este isoscel
{
	if (a==b || a==c || b==c)
	{
		return 1;
	}
	else {
		return 0;
	}
}
int echilateral(unsigned int a, unsigned int b, unsigned int c) //verifica daca triunghiul este echilateral
{
	if (a==b && b==c)
	{
		return 1;
	}
	else {
		return 0;
	}
}
int dreptunghic(unsigned int a, unsigned int b, unsigned int c) //verifica daca triunghiul este dreptunghic folosind teorema lui Pitagora
{
	if (a*a==b*b+c*c || b*b==a*a+c*c || c*c==a*a+b*b)
	{
		return 1;
	}
	else {
		return 0;
	}
}
