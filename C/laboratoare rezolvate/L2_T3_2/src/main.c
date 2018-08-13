/*
 * main.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "numere.h"
int main(void)
{
	unsigned int x, y;
	int valid, ok, op;
	do {
		printf("Dati intervalul [x, y]:\n"); //citim intervalul
		printf("x=");
		scanf("%d", &x);
		printf("y=");
		scanf("%d", &y);
		valid=validare(x, y); //validam intervalul citit, folosind functia de validare creata, care returneaza 1 sau 0
		if (valid==0) //daca intervalul este invalid, afisam eroare si repetam citirea
		{
			printf("Intervalul introdus este eronat. Reintroduceti intervalul [x, y].\n");
		}
	} while (valid==0); //citirea se repeta cat timp utilizatorul introduce un interval invalid
	do {
		do { //afisam un meniu cu optiuni
			printf("\nAlegeti optiunea dorita:\n\n1.Afisare numere deficiente\n2.Afisare numere perfecte\n3.Afisare numere abundente\n");
			scanf("%d", &op); //cerem de la tastatura numarul optiunii dorite
			//in functie de aceasta, apelam functia corespunzatoare
			if (op==1)
			{
				printf("Numerele deficiente din intervalul [%d, %d] sunt: ", x, y);
				deficiente(x, y);
			}
			else if (op==2)
			{
				printf("Numerele perfecte din intervalul [%d, %d] sunt: ", x, y);
				perfecte(x, y);
			}
			else if (op==3)
			{
				printf("Numerele abundente din intervalul [%d, %d] sunt: ", x, y);
				abundente(x, y);
			}
			else {
				printf("Introduceti o optiune valida. \n");
			}
		} while (op!=1 && op!=2 && op!=3); //daca se introduce un numar de optiune invalid, citirea se reia
	printf("\nParasiti programul? (1=DA, 0=NU) ");
	scanf("%d", &ok); //cerem optiunea de a parasi sau relua programul
	} while (ok==0); //programul se repeta cat timp utilizatorul nu a cerut parasirea acestuia (adica nu a introdus 1)
	return 0;
}
