/*
 * main.c
 *
 *  Created on: Apr 15, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
int main(void)
{
	double A[20][20], B[20][20]; //A, B = cele 2 matrici citite, de maxim 20 de linii si 20 de coloane
	int rel, op, A1, A2, B1, B2;
	/*
	 * rel=variabila care retine daca utilizatorul doreste reluarea programului sau nu
	 * op=optiunea aleasa de utilizator din meniu (2 optiuni: suma (1), produs(2))
	 * A1=numarul de linii ale matricii A
	 * A2=numarul de coloane ale matricii A
	 * B1=numarul de linii ale matricii B
	 * B2=numarul de coloane ale matricii B
	 */
	rel=0;
	do {
		FILE *fisier; //declaram o variabila de tip fisier
		fisier=fopen("matrice.in", "r"); //deschidem fisierul "matrice.in" pentru citire
		if(fisier == 0) //daca fisierul nu s-a putut deschide
		{
			printf("Eroare la citirea fisierului \"matrice.in\"!\n"); //afisam eroare
			exit(EXIT_FAILURE); //inchidem programul pentru ca nu putem citi datele de intrare
		}
		fscanf(fisier, "%d %d", &A1, &A2); //citim dimensiunile primei matrici, de pe prima linie (sunt 2 numere intregi cu spatiu intre ele)
		citire(fisier, A, A1, A2); //citim din fisier elementele matricei A, de dimensiuni A1 x A2
		fscanf(fisier, "%d %d", &B1, &B2); //citim dimensiunile celei de a doua matrici (sunt 2 numere intregi cu spatiu intre ele)
		citire(fisier, B, B1, B2); //citim din fisier elementele matricei B, de dimensiuni B1 x B2
		do {
			printf("Operatii cu matrici\n\n");
			afisare(A, A1, A2); //afisam pe ecran cele 2 matrici
			afisare(B, B1, B2);
			printf("Alegeti operatia dorita:\n1.SUMA\n2.PRODUS\n"); //afisam meniul cu cele 2 operatii
			scanf("%d", &op); //citim de la tastatura ce operatie doreste utilizatorul
			if (op!=1 && op!=2) //daca nu este una din cele 2 disponibile
				printf("Alegeti o operatie valida!\n"); //afisam eroare
		} while (op!=1 && op!=2); //repetam aceasta citire cat timp a introdus o operatie gresita
		if (op==1) //daca a ales SUMA
			{
			suma(A, B, A1, A2, B1, B2); //calculam si afisam suma matricilor A si B, daca aceasta se poate efectua
			}
		else { //daca a ales PRODUS
			produs(A, B, A1, A2, B1, B2); //calculam si afisam produsul matricilor A si B, daca acesta se poate efectua
		}
		printf("Reluati programul? (1=DA, 0=NU) ");
		scanf("%d", &rel); //citim optiunea utilizatorului de a relua sau nu programul
		fclose(fisier); //inchidem fisierul deschis pentru citire
	} while (rel==1); //repetam executia programului cat timp utilizatorul doreste reluarea acestuia (a introdus 1)

	return 0;
}
