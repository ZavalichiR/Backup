/*
 * suma.c
 *
 *  Created on: Apr 13, 2015
 *      Author: skynet
 */
#include <math.h>
#include "suma.h"
double suma(unsigned long int n) //calculeaza suma pentru un n dat ca parametru
{
	double valSuma;
	int k;
	valSuma=0;
	for (k=1; k<=n; ++k)
	{
		valSuma+=2/sqrt(4*n*n-k);
	}
	return valSuma;
}
