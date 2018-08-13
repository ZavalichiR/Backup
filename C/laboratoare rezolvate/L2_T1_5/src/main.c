/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "cmmdc.h"
int main(void)
{
	unsigned int a, b, c;
	printf("a="); //citim cele 2 numere
	scanf("%d", &a);
	printf("b=");
	scanf("%d", &b);
	c=cmmdc(a,b); //apelam functia recursiva cmmdc, care returneaza CMMDC(a, b) si depunde rezultatul in variabila c
	printf("cmmdc(%d, %d)=%d\n", a, b, c); //afisam cmmdc-ul
	return 0;
}
