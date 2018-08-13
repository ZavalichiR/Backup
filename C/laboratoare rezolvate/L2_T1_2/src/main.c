/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "ma.h"
int main(void)
{
	double m;
	m=ma(); //apelam functia ma() care calculeaza media aritmetica, valoarea returnata fiind stocata in variabila m
	//citirea celor 5 numere este facuta in functia ma()! Daca am fi facut citirea in main, numerele trebuiau trimise functiei drept parametri
	printf("Media este %.2lf.\n", m); //afisam rezultatul, numar real cu 2 zecimale
	return 0;
}
