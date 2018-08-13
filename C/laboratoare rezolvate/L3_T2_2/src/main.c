/*
 * main.c
 *
 *  Created on: Apr 15, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "numere.h"
int main(void)
{
	int a[100], b[100], n, m; //n=numarul de elemente ale lui a, m=numarul de elemente ale lui b
	n=citire(stdin, a); //apelam functia citire, care preia de la tastatura (stdin) elementele vectorului a, si returneaza numarul acestora in variabila n
	printf("Elementele distincte sunt:\n");
	m=distinct(a, b, n); //introducem in vectorul b doar elementele care sunt distincte, si le numaram, apoi rezultatul il depunem in variabila m
	afisare(b, m); //afisam vectorul b rezultat, cu m elemente
	return 0;
}
