/*
 * L1_B3.c
 *
 *  Created on: Apr 13, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
int main(void)
{
	int x, i;
	double pp;
	i=1;
	do {
		printf("Dati sirul de numere intregi: \n");
		printf("x1=");
		scanf("%d", &x); //citim primul element al sirului
		if (x==0) //daca este nul afisam eroare si reluam citirea
		{
			printf("Introduceti cel putin o valoare nenula!\n");
		}
	} while (x==0); //citim primul element al sirului cat timp nu se introduce 0 de la inceput (sirul cu niciun element nu are sens, pentru ca 0 nu se ia in considerare ca element al sirului)
	++i; //crestem cu 1 indicele elementului
	pp=floor(sqrt(x))*floor(sqrt(x)); //calculam cel mai mare patrat perfect mai mic sau egal decat primul element
	printf("Cel mai mare numar patrat perfect mai mic sau egal decat %d este %d.\n", x, (int)pp);
	while (x) //continuam citirea cat timp nu s-a introdus un element nul
	{
		printf("x%d=", i);
		scanf("%d", &x); //citim elementul i
		if (x==0) //daca s-a introdus 0, iesim din while, adica oprim citirea
		{
			break;
		}
		else { //daca s-a introdus un element nenul, continuam cu calculul
			pp=floor(sqrt(x))*floor(sqrt(x)); //calculam cel mai mare patrat perfect mai mic sau egal decat elementul i
			printf("Cel mai mare numar patrat perfect mai mic sau egal decat %d este %d.\n", x, (int)pp);
		}
		++i; //crestem indicele elementului din sir cu 1
	}
	return 0;
}
