/*
 * experiment.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <math.h>
#include "experiment.h"
int citesteVector(FILE *in, double a[]) //citeste vectorul a din fisierul de intrare "in"
{
	int n;
	n=0; //nu cunoastem numarul de elemente, asa incat il vom determina in functie de cate numere citim, pornind de la pozitia 0
	while (!feof(in)) //cat timp nu am atins sfarsitul de fisier
	{
		fscanf(in, "%lf", &a[n]); //citim cate un numar din fisier
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
double valMedie(double a[], int n) //calculeaza valoarea medie a elementelor din vectorul a
{
	double medie;
	double sum;
	int i;
	sum=0; //pornim cu suma de la 0
	for (i=0; i<n; ++i) //parcurgem vectorul
	{
		sum+=a[i]; //adunam toate elementele la suma
	}
	medie=sum/n; //impartim suma la numarul de elemente si obtinem media
	return medie;
}
double abatereMedie(double a[], int n, double medie) //calculeaza abaterea medie conform formulei
{
	double valAbatere;
	double sum;
	int i;
	sum=0;
	for (i=0; i<n; ++i)
	{
		sum+=(a[i]-medie)*(a[i]-medie);
	}
	valAbatere=sqrt(sum/(n*(n-1)));
	return valAbatere;
}
void afisareSubMedie(FILE *out, double a[], int n, double medie) //afiseaza in fisierul de iesire "out" valorile din vectorul a care sunt sub media calculata
{
	int i, nr;
	nr=0; //contorul numerelor sub medie porneste de la 0
	for (i=0; i<n; ++i) //parcurgem tot vectorul
	{
		if (a[i]<=medie) //daca am gasit un element sub medie sau egal cu aceasta
		{
			++nr; //incrementam contorul
		}
	}
	fprintf(out, "%d", nr); //afisam in fisier numarul de astfel de elemente
}
int creare_y(double a[], int n, double b[]) //creeaza un vector b, dat ca parametru, care contine elementele vectorului a mai mari decat media calculata
{
	int i, k;
	double medie;
	k=0; //k este indicele curent al elementului noului vector b
	medie=valMedie(a, n); //calculam media elementelor din a
	for (i=0; i<n; ++i) //parcurgem vectorul a
	{
		if (a[i]>medie) //daca gasim un element mai mare decat media
		{
			b[k]=a[i]; //depunem acel element pe pozitia k din vectorul b
			++k; //incrementam k pentru a trece la pozitia urmatoare din vectorul b
		}
	}
	return k;
}
void scrieVector_5_linie(FILE *out, double a[], int n) //afiseaza elementele unui vector a in fisierul de iesire "out", cate 5 pe o linie
{
	int i;
	for (i=0; i<n; ++i)
	{
		fprintf(out, "%lf;%c", a[i], ((i+1)%5==0 || i==n-1)?'\n':' ');
		//se foloseste operatorul ternar conditional pentru a verifica daca suntem pe o pozitie de tipul 4, 9, 14, ..., sau daca am ajuns la sfarsitul vectorului
		//daca suntem pe o astfel de pozitie afisam '\n' pentru a trece la linie noua, altfel, afisam spatiu
	}
}
