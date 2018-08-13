/*
 * recurenta.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include "recurenta.h"
double sn(unsigned int n, double a, double b, double c) //functia recursiva care calculeaza valoarea lui sn ca recurenta de gradul 2
{
	if (n==0) //pentru n=0, se obtine s0, care este 3, din relatiile lui Viete
	{
		return 3;
	}
	else if (n==1) //pentru n=1, se obtine s1, care este 0, din relatiile lui Viete
	{
		return 0;
	}
	else if (n==2) //pentru n=2, se obtine s2, care este -2b/a, din relatiile lui Viete
	{
		return -2*b/a;
	}
	else { //pentru n>=3 se apeleaza recursiv functia, pentru a ajunge la valoarea lui sn care depinde de s0, s1, s2
		return -b/a*sn(n-2, a, b, c)-c/a*sn(n-3, a, b, c);
	}
}
