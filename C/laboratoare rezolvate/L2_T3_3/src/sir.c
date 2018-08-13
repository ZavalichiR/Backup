/*
 * sir.c
 *
 *  Created on: Mar 3, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "sir.h"
int tip_sir()
{
	int i, x1, x2, citire;
	/*
	 * x1=elementul "anterior" al sirului
	 * x2=elementul "curent" al sirului
	 * citire=variabila care retine cate numere a citit corect scanf()
	 */
	unsigned int mai_mic, mai_mare, egal; //variabile care retin numarul de relatii de ordine corespunzatoare
	mai_mic=0;
	mai_mare=0;
	egal=0;
	i=1; //pornim cu indicele elementului citit de la 1
	do {
		printf("x%d=", i);
		citire=scanf("%d", &x1); //citim primul element din sir
		if (citire!=1) //daca scanf() a returnat altceva in afara de 1 (adica nu a citit un numar corect = s-a apasat CTRL+D)
		{
			printf("\nIntroduceti cel putin doua numere!\n"); //afisam eroare, deoarece avem nevoie de cel putin un numar (sirul cu niciun element nu are sens)
		}
	} while (citire!=1); //repetam citirea primului element cat timp se apasa CTRL+D
	++i; //trecem mai departe, la al doilea element
	do {
		printf("x%d=", i);
		citire=scanf("%d", &x2); //citim urmatorul element
		if (citire!=1) //daca scanf() a returnat altceva in afara de 1
		{
			if (i==2) //verificam daca citirea a fost facuta pentru al doilea element
			{
				printf("\nIntroduceti cel putin doua numere!\n"); //in acest caz, afisam eroare, deoarece avem nevoie de cel putin 2 numere pentru a forma o relatie de ordine
			}
		}
		else { //daca citirea a fost efectuata cu succes (scanf nu a intalnit caracterul CTRL+D), contorizam relatiile de ordine si trecem la urmatorul element
			if (x1==x2)
			{
				++egal;
			}
			else if (x1>x2)
			{
				++mai_mare;
			}
			else if (x1<x2)
			{
				++mai_mic;
			}
			x1=x2; //elementul vechi devine cel citit, curent
			++i; //incrementam indicele elementului
		}
	} while (citire==1 || (i==2 && citire!=1)); //citirea elementelor si contorizarea relatiilor de ordine se repeta cat timp nu se apasa CTRL+D (adica scanf returneaza 1) sau cat timp citim al doilea element si utilizatorul intrerupe citirea
	//urmeaza testele referitoare la toate relatiile de ordine
	//testele sunt efectuate pentru indicele i-2, deoarece, pentru n numere citite, exista n-1 relatii de ordine intre ele, iar inainte de apasarea tastei CTRL+D, i-ul se mai mareste cu o unitate
	if (egal==i-2) //daca exista numai relatii de egalitate
	{
		return 4; //sirul este constant
	}
	else if (mai_mare==i-2) //daca exista numai relatii mai mare
	{
		return 2; //sirul este strict descrescator
	}
	else if (mai_mic==i-2) //daca exista numai relatii mai mic
	{
		return 6; //sirul este strict crescator
	}
	else if (mai_mare==0) //daca nu exista relatii mai mare, dar exista celelalte 2 tipuri (NU NUMAI de un singur tip, am testat deja mai sus!)
	{
		return 5; //sirul este monoton crescator
	}
	else if (mai_mic==0) //daca nu exista relatii mai mic, dar exista celelalte 2 tipuri (NU NUMAI de un singur tip, am testat deja mai sus!)
	{
		return 3; //sirul este monoton descrescator
	}
	else { //daca nu se incadreaza in niciun tip de mai sus
		return 1; //sirul este oarecare
	}
}
void afisare_tip(int k) //afiseaza pe ecran tipul sirului citit in functie de ce a returnat functia care analizeaza sirul
{
	switch (k)
	{
	case 1: printf("\nSirul este oarecare.\n");
	break;
	case 2: printf("\nSirul este strict descrescator.\n");
	break;
	case 3: printf("\nSirul este monoton descrescator.\n");
	break;
	case 4: printf("\nSirul este constant.\n");
	break;
	case 5: printf("\nSirul este monoton crescator.\n");
	break;
	case 6: printf("\nSirul este strict crescator.\n");
	break;
	}
}
