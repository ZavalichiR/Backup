/*
 * main.c
 *
 *  Created on: Apr 18, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "rotire.h"
int main(void)
{
	L_INT x; //x va fi intregul lung fara semn citit de la tastatura
	int op, n; //op este variabila care determina optiunea aleasa de utilizator din meniu, iar n reprezinta numarul de biti cu care x va fi rotit
	do {
		printf("Alegeti optiunea dorita:\n1.ROTIRE LA DREAPTA\n2.ROTIRE LA STANGA\n"); //afisam meniul
		scanf("%d", &op); //cerem optiunea de la tastatura
		switch(op) //facem switch dupa valoarea optiunii
		{
		case 1: printf("x="); //daca s-a ales ROTIRE LA DREAPTA
				scanf("%lu", &x); //citim numarul x, intreg lung fara semn
				printf("Numarul de biti: ");
				scanf("%d", &n); //citim numarul de biti cu care x va fi rotit
				printf("Numarul initial: \n");
				afisareBinara(x); //afisam sirul de biti initial al numarului
				x=rotireDreapta(x, n); //rotim numarul la dreapta cu n biti
				printf("\nNumarul rotit la dreapta cu %d biti:\n", n);
				afisareBinara(x); //afisam numarul rotit
				break;
		case 2: printf("x="); //daca s-a ales ROTIRE LA STANGA
				scanf("%lu", &x); //citim numarul x, intreg lung fara semn
				printf("Numarul de biti: ");
				scanf("%d", &n); //citim numarul de biti cu care x va fi rotit
				printf("Numarul initial: \n");
				afisareBinara(x); //afisam sirul de biti initial al numarului
				x=rotireStanga(x, n); //rotim numarul la stanga cu n biti
				printf("\nNumarul rotit la stanga cu %d biti:\n", n);
				afisareBinara(x); //afisam numarul rotit
				break;
		default: printf("Introduceti o optiune valida!\n"); //daca nu s-a introdus una din cele 2 optiuni, afisam eroare
		break;
		}
	} while (op!=1 && op!=2); //codul se executa in bucla cat timp nu s-a introdus o optiune valida
	printf("\n");
	return 0;
}
