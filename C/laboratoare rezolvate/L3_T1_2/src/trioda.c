/*
 * trioda.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "trioda.h"
void citireVector_intregi(FILE *in, int a[], unsigned int n) //citeste un vector cu elemente intregi din fisierul "in"
{
	int i;
	for (i=0; i<n; ++i)
	{
		fscanf(in, "%d", &a[i]);
	}
}
void citireVector_reali(FILE *in, double a[], unsigned int n) //citeste un vector cu elemente reale din fisierul "in"
{
	int i;
	double aux;
	for (i=0; i<n; ++i)
	{
		fscanf(in, "%lf", &aux);
		a[i]=aux; //numarul real este mai intai stocat intr-o variabila auxiliara, si apoi pus in vector, deoarece, la citirea din fisier a unui numar real, pot aparea erori daca se citeste direct in vector
	}
}
void afisareVector_intregi(int a[], unsigned int n) //afiseaza un vector cu elemente intregi pe ecran
{
    int i;
    printf("(");
    for (i=0; i<n-1; ++i)
    {
        printf("%d, ", a[i]);
    }
    printf("%d)\n", a[n-1]);
}
void afisareVector_reali(double a[], unsigned int n) //afiseaza un vector cu elemente reale pe ecran
{
    int i;
    printf("(");
    for (i=0; i<n-1; ++i)
    {
        printf("%.2lf, ", a[i]);
    }
    printf("%.2lf)\n", a[n-1]);
}
void sumaVectori(int v1[], int v2[], int suma[], unsigned int n) //calculeaza suma pe componente a 2 vectori cu elemente intregi v1 si v2, rezultatul fiind depus in vectorul suma
{
	int i;
	for (i=0; i<n; ++i)
	{
		suma[i]=v1[i]+v2[i];
	}
}
void sumaVectori_reali(double v1[], double v2[], double suma[], unsigned int n) //calculeaza suma pe componente a 2 vectori cu elemente reale v1 si v2, rezultatul fiind depus in vectorul suma
{
	int i;
	for (i=0; i<n; ++i)
	{
		suma[i]=v1[i]+v2[i];
	}
}
void inmultireVectori(int v1[], double v2[], double inmultire[], unsigned int n) //inmulteste, pe componente, un vector v1 cu elemente intregi cu vectorul v2 cu elemente reale, rezultatul fiind depus in vectorul inmultire
{
	int i;
	for (i=0; i<n; ++i)
	{
		inmultire[i]=v1[i]*v2[i];
	}
}
void vectorScalar(double a[], double v_scalar[], unsigned int n, double scalar) //inmulteste vectorul a, cu elemente reale, cu scalarul real "scalar", rezultatul fiind depus in vectorul v_scalar
{
	int i;
	for (i=0; i<n; ++i)
	{
		v_scalar[i]=scalar*a[i];
	}
}
double suma2Vectori(double v1[], double v2[], unsigned int n) //calculeaza suma tuturor componentelor a 2 vectori v1 si v2, cu elemente reale
{
	double valSuma;
	int i;
	valSuma=0;
	for (i=0; i<n; ++i)
	{
		valSuma=valSuma+v1[i]+v2[i];
	}
	return valSuma;
}
