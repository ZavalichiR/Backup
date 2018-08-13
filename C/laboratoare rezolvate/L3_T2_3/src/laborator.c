/*
 * laborator.c
 *
 *  Created on: Apr 15, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "laborator.h"
int citesteVector(FILE *in, double a[]) //citeste vectorul a din fisierul de intrare "in"
{
	int n;
	double aux;
	n=0; //nu cunoastem numarul de elemente, asa incat il vom determina in functie de cate numere citim, pornind de la pozitia 0
	while (!feof(in)) //cat timp nu am atins sfarsitul de fisier
	{
		fscanf(in, "%lf", &aux); //citim cate un numar din fisier
		a[n]=aux; //numarul real este mai intai stocat intr-o variabila auxiliara, si apoi pus in vector, deoarece, la citirea din fisier a unui numar real, pot aparea erori daca se citeste direct in vector
		++n; //incrementam indicele acestuia in vectorul a
	}
	return n-1; //dupa ce terminam citirea elementelor, feof() returneaza 1 abia DUPA ce se incearca citirea cand fisierul s-a terminat de fapt.
	//de aceea, bucla while() se mai executa o data, in consecinta si n se mai incrementeaza o data, in plus.
}
void scrieVector(FILE *out, double a[], int n) //afiseaza elementele vectorului a in fisierul de iesire "out", in format (a1; a2; ... ; an)
{
	int i;
	fprintf(out, "(");
	for (i=0; i<n-1; ++i)
	{
		fprintf(out, "%lf; ", a[i]);
	}
	fprintf(out, "%lf)", a[n-1]);
}
int rezolvare_sistem(double a[6], double s[2]) //rezolva sistemul de 2 ecuatii cu 2 necunoscute, cu coeficientii stocati in vectorul a
{
	/*	Sistemul este urmatorul:
	 * | a11 a12 |	   | x1 |		| b1 |
	 * 				* 			=
	 * | a21 a22 |	   | x2 |		| b2 |
	 *
	 * a11 = a[0]
	 * a12 = a[1]
	 * a21 = a[2]
	 * a22 = a[3]
	 * b1 = a[4]
	 * b2 = a[5]
	 * x1 = s[0]
	 * x2 = s[1]
	 */
	int rezultat;
	double det, dc, d1, d2;
	det=a[0]*a[3]-a[1]*a[2]; //calculam determinantul matricii sistemului
	if (det==0) //daca determinantul matricii este nul, inseamna ca rangul ei este cel mult 1
	{
		//calculam minorul caracteristic, obtinut prin bordare
		dc=a[0]*a[5]-a[2]*a[4];
		if (dc==0) //daca minorul caracteristic este nul
		{
			rezultat=2; //sistemul este compatibil nedeterminat
		}
		else { //daca minorul caracteristic este nenul
			rezultat=3; //sistem este incompatibil
		}
	}
	else { //daca determinantul matricii este nenul
		rezultat=1; //sistemul este compatibil determinat
		//calculam determinantii obtinuti prin inlocuirea coloanelor 1 si 2 cu coloana termenilor liberi (regula lui Cramer)
		d1=a[4]*a[3]-a[5]*a[1];
		d2=a[0]*a[5]-a[2]*a[4];
		s[0]=d1/det; //aplicam formulele lui Cramer pentru a obtine solutiile x1 si x2
		s[1]=d2/det;
	}
	return rezultat;
}
double produs_scalar(double v1[], double v2[], int n) //calculeaza produsul scalar a doi vectori v1 si v2, fiecare de dimensiune n
{
	double valPS;
	int i;
	valPS=0;
	for (i=0; i<n; ++i)
	{
		valPS=valPS+v1[i]*v2[i];
	}
	return valPS;
}
