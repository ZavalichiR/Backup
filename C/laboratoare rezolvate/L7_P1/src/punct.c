/*
 * punct.c
 *
 *  Created on: Apr 3, 2015
 *      Author: student
 */
#include <stdio.h>
#include <math.h>
#include "punct.h"
void citire(int n, PUNCT v[], FILE *f) //citeste din fisierul "f" elementele vectorului de puncte v, avand in total n puncte
{
	int i;
	double aux; //folosim o auxiliara pentru a citi valori reale in structuri, pentru a nu aparea erori
	for (i=0; i<n; ++i)
	{
		fscanf(f, "%lf", &aux);
		v[i].x=aux;
		fscanf(f, "%lf", &aux);
		v[i].y=aux;
	}
}
void afisare(int n, PUNCT v[]) //afiseaza pe ecran toate varfurile poligonului citit din fisier
{
	int i;
	printf("Pentru poligonul ");
	for (i=0; i<n; ++i) //se parcurge vectorul de puncte (varfuri ale poligonului)
	{
		printf("%c(%.2lf, %.2lf)\t%c", 'A'+i, v[i].x, v[i].y, (i%5==4 || i==n-1)?'\n':'\0');
		//printf-ul de mai sus afiseaza puncte de forma A(2.5, 6.7)	B(4.5, 8.93) ... (cate 5 puncte pe o linie)
		//se foloseste operatorul ternar, conditional, pentru a scrie "TAB", respectiv "\n", dupa caz: TAB intre 2 puncte consecutive, \n cand am afisat 5 puncte si trebuie sa trecem la rand nou
	}
	printf("\n");
}
double distanta(PUNCT a, PUNCT b) //calculeaza distanta intre 2 puncte din plan
{
	double valDistanta;
	valDistanta=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); //formula distantei dintre 2 puncte: √((xA-xB)^2+(yA-yB)^2)
	return valDistanta;
}
double semiperimetru(PUNCT a, PUNCT b, PUNCT c) //calculeaza semiperimetrul unui triunghi determinat de 3 puncte a, b, c
{
	double valSp;
	valSp=(distanta(a, b)+distanta(b, c)+distanta(a, c))/2; //sp=(AB+BC+AC)/2
	return valSp;
}
double ariaTriunghi(PUNCT a, PUNCT b, PUNCT c) //calculeaza aria unui triunghi determinat de 3 puncte a, b, c
{
	double valAria;
	double p;
	p=semiperimetru(a, b, c);
	valAria=sqrt(p*(p-distanta(a, b))*(p-distanta(a, c))*(p-distanta(b, c))); //formula lui Heron: A = √p*(p-a)*(p-b)*(p-c)
	return valAria;
}
double perimetru(int n, PUNCT v[]) //calculeaza perimetrul poligonului determinat de punctele citite din fisier
{
	double valPerimetru;
	int i;
	valPerimetru=0;
	for (i=0; i<n-1; ++i) //parcurgem varfurile poligonului, incepand cu primul, pana la ultimul EXCLUSIV
	{
		valPerimetru+=distanta(v[i], v[i+1]); //adaugam distanta dintre 2 puncte consecutive
		//am parcurs pana la ultimul varf, EXCLUSIV, pentru ca vom adauga distanta dintre penultimul si ultimul punct ca distanta intre elementul n-2 si n-1 din vector, deci i-ul nu ajunge decat la n-2
	}
	valPerimetru+=distanta(v[0], v[n-1]); //nu uitam sa adaugam distanta dintre ultimul punct si primul, pentru a "inchide" perimetrul
	return valPerimetru;
}
double ariaTotala(int n, PUNCT v[]) //calculeaza aria totala a poligonului determinat de punctele citite din fisier
{
	double valAria;
	valAria=0;
	int i;
	//pentru a calcula aria, luam primul punct (A) ca si punct de referinta, si apoi impartim tot poligonul in triunghiuri, cu primul varf in A
	//celelalte 2 varfuri vor fi luate 2 cate 2, incepand cu B, C, apoi C, D, pana la ultimele 2 varfuri.
	//deci, aria poligonului va fi suma ariilor triunghiurilor de forma ABC, ACD, ADE, etc...
	for (i=1; i<n-1; ++i) //parcurgem punctele incepand cu al doilea
	{
		valAria+=ariaTriunghi(v[0], v[i], v[i+1]); //adunam la arie aria triunghiurilor formate de varful A (punctul v[0]) si 2 varfuri consecutive (v[i] si v[i+1])
	}
	//parcurgerea nu ajunge decat cu i-ul la n-1, pentru ca in final, vom aduna aria determinata de punctele v[0], v[n-2] si v[n-1], deci i-ul nu ajunge decat la n-2
	return valAria;
}
