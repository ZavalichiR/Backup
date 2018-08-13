/*
 * L1_B1_a.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
int main(void)
{
	int t;
	double c;
	t=0; //t este temperatura in grade Kelvin
	while (t<=300) //de la 0 K la 300 K
	{
		c=5*(t-32)/9; //calculam temperatura in Celsius dupa formula data
		printf("%3d F | %5.2lf C \n", t, c); //afisam cate o linie a tabelului, ce contine cele 2 temperaturi, separate de o bara verticala
		t+=10; //marim pasul cu 10 grade Kelvin
	}
	return 0;
}
