/*
 * main.c
 *
 *  Created on: Apr 16, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "transpusa.h"
int main(void)
{
	double a[20][20], b[20][20], a_transpusa[20][20], b_transpusa[20][20], ab[20][20], ab_transpus[20][20]; //semnificatiile variabilelor sunt evidente
	int n;
	printf("n=");
	scanf("%d", &n); //citim dimensiunile matricilor A si B (patratice de ordin n)
	printf("Introduceti, pe rand, elementele matricii A: \n");
	citire(a, n, 'A'); //citim elementele lui A
	printf("\nMatricea A initiala:\n");
	afisare(a, n); //afisam matricea A citita, inainte de prelucrare
	printf("Matricea A transpusa: \n");
	transpunere(a, a_transpusa, n); //transpunem matricea A
	afisare(a_transpusa, n); //si o afisam
	printf("Introduceti, pe rand, elementele matricii B: \n");
	citire(b, n, 'B'); //citim matricea B
	printf("\nMatricea B initiala:\n");
	afisare(b, n); //afisam matricea B inainte de prelucrare
	printf("Matricea B transpusa: \n");
	transpunere(b, b_transpusa, n); //transpunem matricea B
	afisare(b_transpusa, n); //si o afisam
	printf("\n(A x B)t = \n");
	produs(a, b, ab, n); //calculam produsul matricelor A si B
	transpunere(ab, ab_transpus, n); //transpunem produsul calculat anterior
	afisare(ab_transpus, n); //afisam transpusa produsului
	printf("\nAt x Bt = \n");
	produs(b_transpusa, a_transpusa, ab_transpus, n); //calculam apoi produsul transpuselor
	afisare(ab_transpus, n); //si il afisam, si vom observa ca se verifica identitatea transpunerii produsului a doua matrice
	return 0;
}
