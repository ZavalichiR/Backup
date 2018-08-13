/*
 * main.c
 *
 *  Created on: May 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
int main(void)
{
	double (*pf[])(double x)={sin, cos, tan};
	int i;
	double x;
	double dx=M_PI/20;
	int nf=sizeof(pf)/sizeof(*(pf+0));
	printf("\tsin(x)\tcos(x)\ttan(x)\n");
	for (x=0; x<=M_PI; x+=dx)
	{
		printf("x=%.2lf\t", x);
		for (i=0; i<nf; ++i)
		{
			printf("%.2lf\t", (**(pf+i))(x));
		}
		printf("\n");
	}
	return 0;
}
