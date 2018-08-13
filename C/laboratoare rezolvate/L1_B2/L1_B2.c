/*
 * L1_B2.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
int main(void)
{
	double b, a, val, dif;
	unsigned int poz, i;
	/*
	 * val=valoarea cea mai apropiata de b
	 * dif=diferenta la iteratia i dintre b si elementul citit curent al sirului
	 * poz=pozitia pe care se afla elementul din sir cel mai apropiat de b
	 */
	printf("b=");
	scanf("%lf", &b); //citim b
	do { //repetam citirea primului element cat timp nu am introdus un prim element negativ (care nu se ia in considerare, conform enuntului)
		//In acest caz nu ar avea sens sirul (un sir fara niciun element)
	printf("Introduceti sirul de elemente:\n");
	printf("a1=");
	scanf("%lf", &a); //citim primul element al sirului
	if (a<0) //daca este negativ, afisam eroare si citirea se repeta
	{
		printf("Introduceti cel putin o valoare pozitiva.");
	}
	} while (a<0);
	val=a; //presupunem ca cel mai apropiat element de b este chiar primul citit
	poz=1; //pozitia este, evident, 1
	i=1;
	dif=fabs(b-a); //calculam diferenta in modul dintre b si primul element al sirului
	do {
		printf("a%d=", i+1);
		scanf("%lf", &a); //citim un nou element din sir
		if (a<0) //daca este negativ, oprim citirea si afisam rezultatul
		{
			printf("Elementul cel mai apropiat de %.2lf este %.2lf, aflat pe pozitia %d.\n", b, val, poz);
		}
		else { //daca elementul citit este pozitiv
			i++; //crestem pozitia curenta cu 1
			if (fabs(b-a)<dif) //calculam noua diferenta, |b-a| si o comparam cu vechea diferenta, dif
			{
				dif=fabs(b-a); //daca este mai mica noua diferenta, atunci o pastram in variabila dif
				poz=i; //modificam si pozitia asa-zisului cel mai apropiat element de b
				val=a; //de asemenea atribuim lui val elementul curent, ca si presupus cel mai apropiat de b
			}
		}
	} while (a>=0); //repetam citirea si atribuirile cat timp nu am citit un element negativ
	return 0;
}
