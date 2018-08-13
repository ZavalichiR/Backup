/*
 * cat.c
 *
 *  Created on: Feb 25, 2015
 *      Author: skynet
 */
#include "cat.h"
int validare(unsigned int a, unsigned int b) //valideaza cele 2 numere a si b (impartitorul sa fie nenul in ambele cazuri (a>b si a<=b)
{
	int ok;
	if ((a>b && b==0) || (a<b && a==0))
	{
		ok=0;
	}
	else ok=1;
	return ok;
}
