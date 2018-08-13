/*
 * main.c
 *
 *  Created on: Apr 13, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
#include "recurenta.h"
int main(void)
{
	double a, xn, xv, EPS, x0, limita, radical;
	unsigned int p, rel;
	/*
	 * xn=termenul curent al sirului, xv=termenul vechi al sirului
	 * EPS=precizia impusa (epsilon)
	 * x0=primul termen al sirului
	 */
	printf("EPSILON=");
	scanf("%lf", &EPS); //citim precizia EPSILON
	do {
		printf("p=");
		scanf("%u", &p); //citim p
		if (p%2==0) //daca p este numar par, trebuie sa avem in vedere faptul ca a sa fie pozitiv (altfel nu exista radicalul)
		{
			do { //repetam citirea lui a de la tastatura
				printf("a=");
				scanf("%lf", &a);
			} while (a<0); //cat timp este introdusa o valoare negativa
		}
		else { //daca p este impar, a poate fi orice numar real
			printf("a=");
			scanf("%lf", &a);
		}
		x0=a/(double)p; //calculam primul termen al sirului
		xv=x0; //primul termen "vechi" va fi chiar x0
		xn=calcul_termen_sir(xv, a, p); //termenul "nou" este calculat cu functia recurentei sirului
		while (fabs(xn-xv)>=EPS) //cat timp modulul diferentei dintre 2 termeni consecutivi inca nu este atat de mica (mai mare decat precizia impusa), deci inca nu ne-am apropiat de limita sirului
		{
			xv=xn; //"mutam" termenul curent ca si termen "vechi"
			xn=calcul_termen_sir(xv, a, p); //calculam termenul nou folosind recurenta data
		}
		//dupa iteratiile parcurse in while, diferenta dintre doi termeni consecutivi din sir este atat de mica, aproape insesizabila (sub precizia impusa)
		//deci, putem considera limita sirului ca fiind ultimul termen calculat, xn
		limita=xn;
		printf("Limita sirului xn este %lf.\n", limita);
		radical=pow(a, 1/(double)p); //calculam limita acestui sir ca radical de ordin p din a (adica a la puterea 1/p)
		printf("Limita calculata folosind functia radical: %lf.\n", radical);
		printf("Reluati programul? (DA=1 / NU=0) ");
		scanf("%u", &rel);
	} while (rel==1);
	return 0;
}
