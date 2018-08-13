/*
 * main.c
 *
 *  Created on: Apr 3, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include "punct.h"
int main(void)
{
	int n; //n=numarul de puncte din plan
	double perim, arie;
	PUNCT p[30]; //declaram un vector de puncte "p"
	FILE *fisier; //declaram o variabila de tip fisier
	fisier=fopen("poligon.in", "r"); //deschidem fisierul "poligon.in" pentru citire ("r" = "read")
	if (fisier==0) //daca fisierul nu a putut fi deschis
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"poligon.in\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //iesim din program pentru ca nu putem citi coordonatele punctelor din plan
	}
	fscanf(fisier, "%d", &n); //citim din fisier numarul de puncte din plan
	citire(n, p, fisier); //apelam functia citire() creata, pentru a citi din fisier, de pe urmatoarele n linii, coordonatele fiecarui punct in parte
	//coordonatele vor fi stocate int-un vector de puncte, care arata asemanator:
	/*
	 * 		 _________________  _________________  _________________		    _________________
	 * 	 -->|        |		  ||        |		 ||        |		|          |        |		 |
	 * 	p|  | p[0].x | p[0].y || p[1].x | p[1].y || p[2].x | p[2].y | .........| p[29].x| p[29].y|
	 * 	 -->|________|________||________|________||________|________|          |________|________|
	 * 	 			p[0]			  p[1]				  p[2]						  p[29]
	 *
	*/
	afisare(n, p); //afisam pe ecran punctele citite
	perim=perimetru(n, p); //calculam perimetrul poligonului
	arie=ariaTotala(n, p); //calculam aria poligonului
	printf("Aria = %.3lf\n", arie); //afisam aria, numar real cu 3 zecimale
	printf("Perimetrul = %.3lf\n", perim); //afisam perimetrul, numar real cu 3 zecimale
	fclose(fisier); //inchidem fisierul de citire
	return 0;
}
