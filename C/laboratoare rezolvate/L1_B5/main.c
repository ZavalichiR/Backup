/*
 * main.c
 *
 *  Created on: Apr 13, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
#include "suma.h"
int main(void)
{
	double EPS, sn, sv;
	unsigned long int n;
	printf("EPSILON=");
	scanf("%lf", &EPS); //citim precizia EPSILON
	n=1; //pornim iteratiile cu n=1
	sv=suma(n); //calculam suma pentru n=1
	++n; //incrementam n cu 1, pentru a calcula a doua suma
	sn=suma(n); //calculam suma pentru n=2
	while (fabs(sn-sv)>=EPS) //cat timp diferenta dintre termenul suma calculat curent si suma veche este mai mare decat precizia impusa
	{
		++n; //incrementam n cu 1
		sv=sn; //suma veche devine cea noua, calculata la aceasta iteratie
		sn=suma(n); //calculam suma pentru noul n, si o atribuim variabilei care retine suma noua
	}
	//in urma iteratiilor din while vom obtine un n pentru care acea suma sn se apropie intr-atat de limita, adica PI/3, cat indica precizia EPSILON
	printf("n=%lu\n", n);
	return 0;
}
