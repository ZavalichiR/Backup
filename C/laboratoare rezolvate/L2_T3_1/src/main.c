/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "prietene.h"
int main(void)
{
	unsigned int x, y;
	int i, j, valid, pr;
	do {
		printf("Dati intervalul [x, y]:\n"); //citim intervalul
		printf("x=");
		scanf("%d", &x);
		printf("y=");
		scanf("%d", &y);
		valid=validare(x, y); //validam intervalul, folosind functia validare creata, care returneaza 1 sau 0
		if (valid==0) //daca intervalul este invalid, afisam eroare si repetam citirea acestuia
		{
			printf("Intervalul introdus este eronat. Reintroduceti intervalul [x, y].\n");
		}
	} while (valid==0); //citirea se repeta cat timp intervalul citit este invalid
	//in continuare testam conditia ca 2 numere sa fie prietene pentru fiecare din numerele din intervalul [x, y], parcurgand pentru fiecare din acestea, toate numerele de dupa el
	for (i=x; i<y; i++) //pentru fiecare numar in parte din acest interval (nu se ajunge cu i la y, deoarece ultimul test va fi intre numarul y-1 si y
	{
		for (j=i+1; j<=y; j++) //pentru fiecare numar in parte de dupa un numar ales din interval
		{
			pr=prietene(i, j); //verificam daca cele 2 numere sunt prietene
			if (pr==1) //daca i si j sunt prietene, le afisam pe ecran
			{
				printf("%d si %d\n", i, j);
			}
		}
	}
	return 0;
}
