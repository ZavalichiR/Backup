/*
 * main.c
 *
 *  Created on: Apr 15, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "laborator.h"
int main(void)
{
	FILE *in_t, *in_x, *out; //declaram 2 variabile de tip fisier, unul de intrare si unul de iesire
	double t[100], x[100], coef[6], sol[2], unitate[100];
	int n, i, rezultat_sistem;
	//folosim 2 fisiere de intrare, laborator_in_t.dat in care se gasesc momentele de timp, si laborator_in_x.dat, in care se gasesc concentratiile
	in_t=fopen("laborator_in_t.dat", "r"); //deschidem de pe disc fisierul de intrare "laborator_in_t.dat", deci cu parametrul "r" ("read")
	if (in_t==0) //daca fopen() a returnat 0, adica nu a reusit sa deschida fisierul de intrare
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"laborator_in_t.dat\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //iesim din program, pentru ca nu putem citi momentele de timp
	}
	in_x=fopen("laborator_in_x.dat", "r"); //deschidem de pe disc fisierul de intrare "laborator_in_x.dat", deci cu parametrul "r" ("read")
	if (in_x==0) //daca fopen() a returnat 0, adica nu a reusit sa deschida fisierul de intrare
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"laborator_in_x.dat\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //iesim din program, pentru ca nu putem citi concentratiile
	}
	out=fopen("laborator_out.dat", "w"); //deschidem de pe disc fisierul de iesire "laborator_out.dat", deci cu parametrul "w" ("write")
	if (out==0) //daca fopen() a returnat 0, adica nu a reusit sa deschida fisierul de iesire
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"laborator_out.dat\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //iesim din program, pentru ca nu putem scrie rezultatele prelucrarilor
	}
	n=citesteVector(in_t, t); //citim vectorul cu momentele de timp din fisier, numarul elementelor sale fiind depus in variabila n
	n=citesteVector(in_x, x); //citim vectorul cu valorile concentratiilor din fisier, numarul elementelor sale fiind de asemenea n
	//determinam coeficientii sistemului de ecuatii
	for (i=0; i<n; ++i) //cream vectorul unitate de ordin n pentru a putea face suma elementelor unui vector folosind produsul scalar
	{
		unitate[i]=1;
	}
	coef[0]=n; //a11 = n
	coef[1]=produs_scalar(unitate, t, n); //a12 = suma elementelor lui t
	coef[2]=coef[1]; //a21 = suma elementelor lui t, calculata mai sus, egala cu coef[1]
	coef[3]=produs_scalar(t, t, n); //a22 = produsul scalar dintre t si el insusi
	coef[4]=produs_scalar(unitate, x, n); //b1 = suma elementelor lui x
	coef[5]=produs_scalar(t, x, n); //b2 = produsul scalar dintre vectorii t si x
	rezultat_sistem=rezolvare_sistem(coef, sol); //rezolvam sistemul de ecuatii liniare folosind functia creata
	if (rezultat_sistem==1) //daca sistemul este compatibil determinat
	{
		fprintf(out, "Coeficientii dreptei de regresie sunt: \n");
		fprintf(out, "a=%lf; b=%lf", sol[0], sol[1]); //afisam coeficientii dreptei de regresie
	}
	else if (rezultat_sistem==2) //daca sistemul este compatibil nedeterminat
	{
		//sistemul va avea o infinitate de solutii, deci nu putem calcula coeficientii ca numere fixate
		fprintf(out, "Coeficientii dreptei de regresie nu pot fi calculati. Sistemul de ecuatii este compatibil nedeterminat.");
	}
	else //daca sistemul este incompatibil
	{
		//coeficientii nu pot fi calculati pentru ca sistemul nu are solutie
		fprintf(out, "Coeficientii dreptei de regresie nu pot fi calculati. Sistemul de ecuatii este incompatibil.");
	}
	fclose(in_x); //inchidem cele 3 fisiere
	fclose(in_t);
	fclose(out);
	return 0;
}
