/*
 * magazine.c
 *
 *  Created on: May 28, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "magazine.h"

void* xmalloc(size_t nrOcteti) //functia xmalloc() din curs, care aloca dinamic memorie si returneaza pointer generic la zona de memorie alocata
{
	void *p=0;
	p=malloc(nrOcteti);
	if (p==0)
	{
		fprintf(stderr, "Eroare la alocarea memoriei.\n");
		exit(EXIT_FAILURE);
	}
	return p;
}
FIRMA* citire(FILE *in) //citeste din fisierul de intrare "in" informatiile despre firma
{
	FIRMA *f=0; //declaram un pointer catre o structura de tip FIRMA, pe care il initializam cu 0 (generic)
	f=(FIRMA*)xmalloc(sizeof(FIRMA)); //alocam dinamic memorie suficienta pentru a stoca o astfel de structura in RAM
	f->numeFirma=(char*)xmalloc(21*sizeof(char)); //de asemenea, alocam memorie pentru numele firmei (de exemplu, maxim 20 de caractere efectiv = 21 - '\0')
	fgets(f->numeFirma, 10, in); //citim din fisierul de intrare "in" numele firmei
	fscanf(in, "%u", &(f->nrMagazine)); //citim numarul magazinelor (numarul de linii ale matricei)
	fscanf(in, "%u", &(f->nrCategoriiProduse)); //citim numarul tipurilor de produse (numarul de coloane ale matricei)
	f->stoc=citireMatrice(in, f->nrMagazine, f->nrCategoriiProduse); //citim matricea cu informatii din fisier, pointerul la aceasta fiind stocat in variabila "stoc" din structura "f"
	f->pret=citireVector(in, f->nrCategoriiProduse); //citim vectorul de preturi din fisier, pointerul catre acesta fiind stocat in variabila "pret" din structura "f"
	return f; //returneaza pointer la structura creata dinamic dupa citire
}
int **aloca2d(int n, int m) //functia care aloca memorie pentru o matrice de n x m
{
	int **a=0;
	int i;
	a=(int**)xmalloc(n*sizeof(int*));
	for (i=0; i<n; ++i)
	{
		*(a+i)=(int*)xmalloc(m*sizeof(int));
	}
	return a;
}
void dealoca2d(int **a, int n) //functia care elibereaza memoria alocata dinamic pentru o matrice cu n linii
{
	int i;
	for (i=0; i<n; ++i)
	{
		free(*(a+i));
		*(a+i)=0;
	}
	free(a);
}
int** citireMatrice(FILE *in, int n, int m) //citeste o matrice din fisierul de intrare "in" si returneaza pointer la aceasta
{
	int **a;
	int i, j;
	a=aloca2d(n, m);
	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; ++j)
		{
			fscanf(in, "%d", *(a+i)+j);
		}
	}
	return a;
}
void afisareMatrice(int **a, int n, int m) //afiseaza o matrice alocata dinamic de dimensiuni n x m
{
	int i, j;
	for (i=0; i<n; ++i)
	{
		for (j=0; j<m; ++j)
		{
			printf("%d ", *(*(a+i)+j));
		}
		printf("\n");
	}
}
float* citireVector(FILE *in, int n) //citeste un vector de elemente reale din fisierul de intrare "in" si returneaza pointer la acesta
{
	float *v=0;
	v=(float*)xmalloc(n*sizeof(float));
	int i;
	for (i=0; i<n; ++i)
	{
		fscanf(in, "%f", v+i);
	}
	return v;
}
void afisareInformatii(FIRMA *frm) //afiseaza informatiile incarcate din fisier
{
	printf("Datele firmei sunt:\n\n");
	printf("Nume: %s\n", frm->numeFirma);
	printf("Numar de magazine: %d\n", frm->nrMagazine);
	printf("Numar de categorii de produse: %d\n\n", frm->nrCategoriiProduse);
	printf("Stocurile firmei sunt:\n");
	int i, j;
	for (i=0; i<frm->nrMagazine; ++i)
	{
		printf("Magazinul %d are:\n", i+1);
		for (j=0; j<frm->nrCategoriiProduse; ++j)
		{
			printf("\t%d produse din categoria %d\n", *(*(frm->stoc+i)+j), j+1);
		}
		printf("\n");
	}
	printf("Preturile produselor sunt:\n");
	for (i=0; i<frm->nrCategoriiProduse; ++i)
	{
		printf("Produsul din categoria %d are pretul %.2f\n", i+1, *(frm->pret+i));
	}
}
double valoareTotala(FIRMA *frm) //calculeaza valoarea totala a produselor firmei
{
	double val_t;
	int i, j;
	val_t=0;
	for (i=0; i<frm->nrMagazine; ++i) //pentru fiecare magazin in parte
	{
		for (j=0; j<frm->nrCategoriiProduse; ++j) //pentru fiecare tip de produs in parte
		{
			val_t+=*(*(frm->stoc+i)+j)**(frm->pret+j); //inmultim pretul produsului respectiv cu numarul produselor de acel tip aflate pe stoc in magazinul i, si adunam la valoarea totala
		}
	}
	return val_t;
}
int stocTotal(int *vectorStoc, int n) //calculeaza stocul total al magazinelor
{
	int valStocTotal, i;
	valStocTotal=0;
	for (i=0; i<n; ++i)
	{
		valStocTotal+=*(vectorStoc+i);
	}
	return valStocTotal;
}
void swap(int **pp1, int **pp2) //interschimba 2 pointeri (folosita pentru ordonarea matricei)
{
	int *aux;
	aux=*pp1;
	*pp1=*pp2;
	*pp2=aux;
}
void ordonareMatrice(FIRMA *frm) //ordoneaza matricea de stocuri conform numarului de produse aflate pe stoc la fiecare magazin
{
	int i, ok;
	int k=frm->nrMagazine-1; //numarul pana la care se executa bubblesort la o iteratie
	do {
		ok=0;
		for (i=0; i<k; ++i) //pentru fiecare magazin in parte
		{
			if (stocTotal(*(frm->stoc+i), frm->nrCategoriiProduse)>stocTotal(*(frm->stoc+i+1), frm->nrCategoriiProduse)) //daca stocul total al magazinului curent este mai mare decat cel al magazinului urmator
			{
				swap(frm->stoc+i, frm->stoc+i+1); //interschimbam locurile celor 2 pointeri (inversam ordinea celor 2 magazine in memorie)
				ok=1; //marcam ca am facut o schimbare
			}
		}
		--k; //scadem cu o unitate numarul maxim de parcurs pentru bubblesort, pentru ca dupa un set de iteratii complete bubblesort, ultimul element setat are mereu pozitia corecta (cel mai mare)
	} while(ok); //executam bubblesort cat timp mai exista modificari facute in ordinea elementelor
}
