/*
 * triunghi.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include "triunghi.h"
int validare(unsigned int a, unsigned int b, unsigned int c) //valideaza existenta triunghiului de laturi a, b, c (numere pozitive + suma a oricaror 2 laturi sa o depaseasca pe a 3-a)
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
