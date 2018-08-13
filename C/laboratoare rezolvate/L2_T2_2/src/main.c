/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "punct.h"
int main(void)
{
	double x, y;
	printf("Dati coordonatele punctului:\n"); //citim cele 2 coordonate ale punctului
	printf("x=");
	scanf("%lf", &x);
	printf("y=");
	scanf("%lf", &y);
	pozitie(x, y); //apelam functia pozitie() care, in functie de coordonatele x si y date, afiseaza pozitia punctului din plan
	return 0;
}
