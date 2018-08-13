/*
 * header.c
 *
 *  Created on: Jun 9, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "header.h"

void CitesteMatrice(double m[][11], int nrlin, int nrcol) //functie care citeste o matrice de la tastatura (cu maxim 11 coloane)
{
	int i, j; //indecsii cu care parcurgem matricea
	for (i=0; i<nrlin; i++) //pentru fiecare linie, incepand de la prima (linia 0) pana la ultima (linia nrlin-1)
	{
		for (j=0; j<nrcol; j++) //pentru fiecare coloana, incepand de la prima (coloana 0) pana la ultima (coloana nrcol-1)
		{
			printf("m[%d][%d]=", i, j); //afisam un mesaj explicativ de tipul "m[2][3]=", asteptand interventia utilizatorului
			scanf("%lf", &m[i][j]); //citim elementul de pe pozitia curenta (i, j), numar real (%lf = long float = double)
		}
	}
}

void AfiseazaMatrice(double m[][11], int nrlin, int nrcol) //functie care afiseaza o matrice pe ecran (de maxim 11 coloane)
{
	int i, j; //indecsii cu care parcurgem matricea
	for (i=0; i<nrlin; i++) //pentru fiecare linie, incepand de la prima (linia 0) pana la ultima (linia nrlin-1)
	{
		for (j=0; j<nrcol; j++) //pentru fiecare coloana, incepand de la prima (coloana 0) pana la ultima (coloana nrcol-1)
		{
			printf("%lf ", m[i][j]); //afisam fiecare element in parte (numar real, %lf = long float = double), cu un spatiu dupa el
		}
		printf("\n"); //dupa ce am terminat de afisat o linie (adica s-a terminat for-ul interior, cu index-ul j), trecem la rand nou ca sa putem afisa urmatoarea linie
	}
}

double MedieElementePrimaLinieMatrice(double m[][11], int nrlin, int nrcol) //functie care calculeaza media aritmetica a elementelor de pe prima linie
{
	double valMedie; //declaram variabila in care vom retine media calculata
	double sum; //declaram o variabila in care retinem suma elementelor de pe prima linie
	int j; //indexul care va parcurge prima linie a matricei
	sum=0; //pornim cu suma de la 0, pentru a avea "la ce aduna"
	for (j=0; j<nrcol; j++) //parcurgem prima linie a matricei (practic, coloanele de la 0 la nrcol-1, deoarece i-ul este FIXAT (pentru ca ni se cere DOAR prima linie)
	{
		sum=sum+m[0][j]; //adunam la suma elementul de pe pozitia (0, j) -> indexul i este FIXAT! Ni se cere doar prima linie de parcurs, deci i=0; DOAR j variaza intre 0 si nrcol-1
	}
	valMedie=sum/nrcol; //calculam media impartind suma elementelor la numarul lor, care este de fapt numarul coloanelor matricei (pentru ca, din nou, ni se cere doar prima linie de luat in considerare)
	return valMedie; //returnam media calculata
}

void CitesteMatriceFisier(FILE *fisier_citire, double m[][11], int nrlin, int nrcol) //citeste o matrice cu elemente reale dintr-un fisier specificat
{
	//fisierul este specificat ca primul parametru!
	//functia de citire este aceeasi ca cea de mai sus, tot ce se schimba este modul ce preluare a elementelor
	int i, j;
	for (i=0; i<nrlin; i++)
	{
		for (j=0; j<nrcol; j++)
		{
			fscanf(fisier_citire, "%lf", &m[i][j]);
			//functia fscanf() (=FILE scanf) citeste date dintr-un fisier de intrare specificat ca prim parametru
			//in rest, functioneaza exact la fel ca scanf(), ceilalti 2 parametri fiind tot formatul de citire si adresa variabilei care va fi citita
		}
	}
}

void AfisareRezultateFinale(FILE *fisier_rezultate, double matrice1[][11], int nrlin1, int nrcol1, double matrice2[][11], int nrlin2, int nrcol2)
{ //afiseaza rezultatele finale cerute la subpunctul e)
	//primul parametru este fisierul de iesire (adica cel in care se vor scrie rezultatele)
	int nrElemente1; //declaram numarul de elemente pentru prima matrice
	int i, j; //indecsii de parcurs pentru cele 2 matrici

	nrElemente1=nrlin1*nrcol1; //numarul de elemente ale matricii este numarul de linii inmultit cu numarul de coloane
	fprintf(fisier_rezultate, "Matricea citita de la tastatura are %d elemente:\n", nrElemente1);
	//afisam in fisier prima linie de text necesara (numarul de elemente ale primei matrici, adica cea citita de la tastatura)
	//functia fprintf() (=FILE printf) afiseaza intr-un fisier. Este ACEEASI ca si printf(), insa trebuie specificat parametrul in plus, si anume fisierul de scriere
	//in rest, parametrii sunt aceiasi. Al doilea parametru este textul de scris (cu tot cu eventualele variabile).
	//urmatorii parametri dupa text sunt eventualele variabile OBLIGATORIU IN ORDINEA IN CARE APAR IN TEXT!

	for (i=0; i<nrlin1; i++) //pentru fiecare linie, incepand de la prima (linia 0) pana la ultima (linia nrlin1-1)
	{
		for (j=0; j<nrcol1; j++) //pentru fiecare coloana, incepand de la prima (coloana 0) pana la ultima (coloana nrcol1-1)
		{
			fprintf(fisier_rezultate, "%04.0lf ", matrice1[i][j]); //afisam element cu element matricea, in formatul specificat
			/*
			 * EXPLICATIE FORMAT:
			 * 		%              	0              	 4             .           0              lf
			 * 		^			   	^				 ^			   ^		   ^			  ^
			 * 		|			   	|				 |			   |		   |			  |
			 * 		|			   	|				 |			   |		   |			  |
			 * 		|			   	|				 |			   |		   |			  |
			 * 		|			   	|				 |			   |		   |			  |
			 *  marcheaza		spatiul				numarul		marcheaza	semnifica		semnifica
			 *  inceputul		ramas				afisat are	inceputul	faptul ca		tipul numarului
			 *  unui format		liber se			rezervate	formatului	partea			de afisat
			 *  de variabila	completeaza			4 spatii	pentru		zecimala		lf = long float = double
			 *  				cu zerouri						partea		este formata
			 *  												zecimala	din 0 zecimale
			 *  												a numarului
			 */
		}
		fprintf(fisier_rezultate, "\n"); //cand se termina de afisat o linie, trecem la linie noua scriind caracterul '\n'
	}

	double medieElemente1; //declaram o variabila in care retinem media elementelor de pe prima linie a primei matrice
	medieElemente1=MedieElementePrimaLinieMatrice(matrice1, nrlin1, nrcol1); //calculam media folosind functia DEJA creata la subpunctul c)
	fprintf(fisier_rezultate, "Media elementelor este: %.3lf\n", medieElemente1); //afisam aceasta medie in urmatoarea linie din fisier

	int nrElemente2; //declaram numarul de elemente pentru prima matrice

	nrElemente2=nrlin2*nrcol2; //numarul de elemente ale matricii este numarul de linii inmultit cu numarul de coloane
	fprintf(fisier_rezultate, "Matricea citita din fisier are %d elemente:\n", nrElemente2);
	//afisam in fisier, pe urmatoarea linie, numarul de elemente ale celei de a doua matrici, adica cea citita din fisierul de intrare date.txt

	for (i=0; i<nrlin2; i++) //pentru fiecare linie, incepand de la prima (linia 0) pana la ultima (linia nrlin2-1)
	{
		for (j=0; j<nrcol2; j++) //pentru fiecare coloana, incepand de la prima (coloana 0) pana la ultima (coloana nrcol2-1)
		{
			fprintf(fisier_rezultate, "%+7.2lf ", matrice2[i][j]); //afisam element cu element matricea, in formatul specificat
			/*
			 * EXPLICATIE FORMAT:
			 * 		%              	+              	 7             .           2              lf
			 * 		^			   	^				 ^			   ^		   ^			  ^
			 * 		|			   	|				 |			   |		   |			  |
			 * 		|			   	|				 |			   |		   |			  |
			 * 		|			   	|				 |			   |		   |			  |
			 * 		|			   	|				 |			   |		   |			  |
			 *  marcheaza		inaintea			numarul		marcheaza	semnifica		semnifica
			 *  inceputul		numarului			afisat are	inceputul	faptul ca		tipul numarului
			 *  unui format		se afiseaza			rezervate	formatului	partea			de afisat
			 *  de variabila	si semnul sau		7 spatii	pentru		zecimala		lf = long float = double
			 *  				indiferent						partea		este formata
			 *  				daca este						zecimala	din 2 zecimale
			 *  				pozitiv sau nu					a numarului
			 */
		}
		fprintf(fisier_rezultate, "\n"); //cand se termina de afisat o linie, trecem la linie noua scriind caracterul '\n'
	}

	double medieElemente2; //declaram o variabila in care retinem media elementelor de pe prima linie a celei de a doua matrice
	medieElemente2=MedieElementePrimaLinieMatrice(matrice2, nrlin2, nrcol2); //calculam media folosind functia DEJA creata la subpunctul c)
	fprintf(fisier_rezultate, "Media elementelor este: %.2lf\n", medieElemente2); //afisam aceasta medie in urmatoarea linie din fisier
}
