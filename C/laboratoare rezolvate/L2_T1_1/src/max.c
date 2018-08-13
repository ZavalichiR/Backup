/*
 * max.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include "max.h"
int max(int a, int b, int c) //calculeaza maximul dintre cele 3 numere primite ca parametri
{
	int m;
	if (a>=b && a>=c)
	{
		m=a;
	}
	else if (b>=a && b>=c)
	{
		m=b;
	}
	else {
		m=c;
	}
	return m;
}
