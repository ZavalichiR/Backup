/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "max.h"
int main(void)
{
	int a, b, c, m;
	printf("a="); //citim cele 3 numere de la tastatura
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);
	printf("c=");
	scanf("%d", &c);
	m=max(a, b, c); //apelam functia max si rezultatul returnat il stocam in variabila m
	printf("Maximul este %d.\n", m); //afisam rezultatul
	return 0;
}
