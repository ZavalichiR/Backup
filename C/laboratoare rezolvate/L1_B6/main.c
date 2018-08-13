/*
 * main.c
 *
 *  Created on: Apr 13, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
#include "functie.h"
int main(void)
{
	double EPS, x, J0, J1, valJN;
	unsigned int n;
	printf("EPSILON=");
	scanf("%lf", &EPS); //citim precizia impusa EPSILON
	printf("x=");
	scanf("%lf", &x); //citim x
	printf("n=");
	scanf("%u", &n); //citim n
	double sumJ0_v, sumJ0_n; //sumJ0_v este suma "anterioara", iar sumJ0_n este suma calculata curent
	unsigned int p; //p este numarul pana la care se calculeaza suma (adica indicele superior, pentru care suma satisface precizia impusa)
	p=1; //pornim cu indicele superior 1
	sumJ0_v=sumJ0(x, p); //calculam suma J0 de la k=0 pana la 1
	++p; //incrementam indicele cu 1
	sumJ0_n=sumJ0(x, p); //calculam suma J0 de la k=0 pana la 2
	while (fabs(sumJ0_n-sumJ0_v)>=EPS) //cat timp diferenta in modul dintre 2 sume succesiv calculate (adica pentru valori ale lui p succesive) este mai mare ca precizia impusa
	{
		++p; //incrementam p
		sumJ0_v=sumJ0_n; //suma veche devine cea curent calculata (pentru ca trebuie sa facem diferenta dintre 2 sume SUCCESIVE)
		sumJ0_n=sumJ0(x, p); //suma noua trebuie sa o calculam in continuare folosind functia creata
	}
	//cand se incheie iteratiile din while, vom obtine o suma J0 care va satisface precizia impusa (adica diferenta in modul dintre 2 sume calculate pentru p succesivi este enorm de mica)
	//deci valoarea lui J0 va fi ultima suma calculata in while, adica sumJ0_n
	J0=sumJ0_n;
	//procedam EXACT la fel pentru a calcula J1
	double sumJ1_v, sumJ1_n; //sumJ1_v este suma "anterioara", iar sumJ1_n este suma calculata curent
	p=1; //pornim cu indicele superior 1
	sumJ1_v=sumJ1(x, p); //calculam suma J1 de la k=0 pana la 1
	++p; //incrementam indicele cu 1
	sumJ1_n=sumJ1(x, p); //calculam suma J1 de la k=0 pana la 2
	while (fabs(sumJ1_n-sumJ1_v)>=EPS) //cat timp diferenta in modul dintre 2 sume succesiv calculate (adica pentru valori ale lui p succesive) este mai mare ca precizia impusa
	{
		++p; //incrementam p
		sumJ1_v=sumJ1_n; //suma veche devine cea curent calculata (pentru ca trebuie sa facem diferenta dintre 2 sume SUCCESIVE)
		sumJ1_n=sumJ1(x, p); //suma noua trebuie sa o calculam in continuare folosind functia creata
	}
	//cand se incheie iteratiile din while, vom obtine o suma J1 care va satisface precizia impusa (adica diferenta in modul dintre 2 sume calculate pentru p succesivi este enorm de mica)
	//deci valoarea lui J1 va fi ultima suma calculata in while, adica sumJ1_n
	J1=sumJ1_n;
	//avand J0 si J1 calculati, trecem la calculul lui JN, ca recurenta de gradul 2
	valJN=JN(x, n, J0, J1);
	printf("J0=%lf, J1=%lf, JN=%lf\n", J0, J1, valJN); //afisam rezultatele
	return 0;
}
