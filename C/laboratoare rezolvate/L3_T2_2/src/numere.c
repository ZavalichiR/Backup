/*
 * numere.c
 *
 *  Created on: Apr 15, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "numere.h"
int citire(FILE *in, int a[]) //citeste din fisierul de intrare "in" (aici, tastatura, adica stdin) elementele vectorului a, pana la introducerea valorii 0
{
	int p, val; //val=valoarea introdusa curent, p=al catelea element se citeste
	p=1;
	do {
		printf("Introduceti sirul de numere:\n");
		printf("a[%d]=", p);
		fscanf(in, "%d", &val); //citim prima valoare
		if (val==0) //daca aceasta este nula
		{
			printf("Introduceti cel putin un numar nenul!\n"); //afisam eroare, deoarece avem nevoie de cel putin o valoare nenula
		}
	} while (val==0); //repetam citirea primei valori atat timp cat utilizatorul introduce 0
	while (val!=0) //dupa ce am citit prima valoare si stim sigur ca este nenula, continuam citirea cat timp nu se introduce 0
	{
		a[p-1]=val; //introducem valoarea citita in vectorul a, de indice p-1, deoarece indexarea porneste de la 0
		++p; //incrementam indexul
		printf("a[%d]=", p);
		fscanf(in, "%d", &val); //citim urmatoarea valoare
	}
	return p-1; //returnam p-1 deoarece inainte de a se citi valoarea 0, cand practic s-ar termina citirea, p-ul apuca sa mai creasca o data cu o unitate
}
void afisare(int a[], int n) //afiseaza elementele vectorului a in format (a1; a2; ... ; an)
{
	int i;
	printf("(");
	for (i=0; i<n-1; ++i)
	{
		printf("%d; ", a[i]);
	}
	printf("%d)\n", a[n-1]);
}

int distinct(int a[], int b[], int n) //introduce in vectorul b elementele distincte ale lui a, le numara, si returneaza numarul lor
{
	int i, j, p, ok;
	/*
	 * i=indicele de parcurs al lui a
	 * j=indicele de parcurs al lui b
	 * p=al catelea element s-a introdus in b
	 * ok=indica daca elementul curent care trebuie introdus in b a mai existat o data in a
	 */
	p=1; //pornim cu elementul 1 in vectorul b
	for (i=0; i<n; ++i) //parcurgem vectorul a
	{
		ok=1; //presupunem ca elementul care trebuie introdus in b este unic
		for (j=0; j<p-1; ++j) //parcurgem vectorul b incepand cu primul element pana la ultima pozitie unde mai exista elemente, adica p-1
		{
			if (a[i]==b[j]) //daca gasim vreun element in b care este egal cu cel care trebuie introdus acum
			{
				ok=0; //punem indicele ok pe 0
			}
		}
		if (ok) //daca ok a ramas setat pe 1, adica nu am gasit duplicat
		{
			b[p]=a[i]; //introducem in vectorul b elementul curent din a
			++p; //incrementam numarul de elemente din b
		}
	}
	return p-1; //returnam p-1, deoarece, inainte de a se termina de parcurs vectorul a, p apuca sa mai creasca cu o unitate
}
