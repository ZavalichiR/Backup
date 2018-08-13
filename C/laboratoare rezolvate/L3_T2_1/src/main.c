/*
 * main.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "experiment.h"
int main(void)
{
	FILE *in, *out; //declaram 2 variabile de tip fisier, unul de intrare si unul de iesire
	double x[100], y[100], medie, abatere;
	int n, k;
	in=fopen("inP21.dat", "r"); //deschidem de pe disc fisierul de intrare "inP21.dat", deci cu parametrul "r" ("read")
	if (in==0) //daca fopen() a returnat 0, adica nu a reusit sa deschida fisierul de intrare
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"inP21.dat\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //iesim din program, pentru ca nu putem citi niciun set de date de intrare
	}
	out=fopen("rezP21.dat", "w"); //deschidem de pe disc fisierul de iesire "rezP21.dat", deci cu parametrul "w" ("write")
	if (out==0) //daca fopen() a returnat 0, adica nu a reusit sa deschida fisierul de iesire
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"rezP21.dat\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //iesim din program, pentru ca nu putem scrie rezultatele prelucrarilor
	}
	n=citesteVector(in, x); //citim vectorul de elemente din fisier, numarul elementelor sale fiind depus in variabila n
	fprintf(out, "Elementele citite sunt: \n");
	scrieVector(out, x, n); //afisam vectorul citit pe prima linie a fisierului de iesire
	medie=valMedie(x, n); //calculam media valorilor din vectorul x
	fprintf(out, "\nValoarea medie: %lf\n", medie); //afisam media in fisierul de iesire
	abatere=abatereMedie(x, n, medie); //calculam abaterea medie
	fprintf(out, "Abaterea medie: %lf\n", abatere); //afisam abaterea medie in fisierul de iesire
	fprintf(out, "Numarul de componente ce nu depasesc valoarea medie: ");
	afisareSubMedie(out, x, n, medie); //afisam numarul de componente sub medie in fisierul de iesire
	fprintf(out, "\nElementele mai mari decat valoarea medie:\n");
	k=creare_y(x, n, y); //cream vectorul y, ce va contine elementele mai mari decat media, iar functia care il creeaza va returna numarul elementelor lui, depus in variabila k
	scrieVector_5_linie(out, y, k); //afisam elementele lui y, cate 5 pe o linie, in fisierul de iesire
	fclose(in); //inchidem fisierul de intrare
	fclose(out); //inchidem fisierul de iesire
	return 0;
}
