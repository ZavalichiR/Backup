/*
 * main.c
 *
 *  Created on: Mar 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "sir.h"
int main()
{
	int n;
	printf("Introduceti termenii sirului:\n");
	n=tip_sir(); //apelam functia tip_sir() care citeste si analizeaza sirul primit de la tastatura; returneaza tipul sirului analizat (un numar de la 1 la 6)
	afisare_tip(n); //dupa ce s-a stabilit tipul sirului, apelam functia afisare_tip(), care, cu ajutorul parametrului n (tipul sirului) afiseaza pe ecran mesajul corespunzator tipului respectiv
	return 0;
}
