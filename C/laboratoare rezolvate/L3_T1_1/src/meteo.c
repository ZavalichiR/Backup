/*
 * meteo.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "meteo.h"
void citireVector(int a[], int n) //citeste un vector de intregi, de dimensiune n de la tastatura
{
    int i;
    for (i=0; i<n; ++i)
    {
        printf("Temperatura %d: ", i+1);
        scanf("%d", &a[i]);
    }
}
void afisareVector(FILE *out, int a[], int n) //afiseaza un vector de intregi in fisierul de iesire "out"
{
    int i;
    for (i=0; i<n-1; ++i)
    {
        fprintf(out, "%d, ", a[i]);
    }
    fprintf(out, "%d.\n", a[n-1]);
}
int maxVector(int a[], int n) //determina maximul dintre toate elementele vectorului a
{
    int i, maxim;
    maxim=a[0]; //presupunem maximul ca fiind primul element
    for (i=1; i<n; ++i) //parcurgem toate celelalte elemente, incepand cu al doilea
    {
        if (a[i]>maxim) //daca gasim unul mai mare decat maximul curent
        {
            maxim=a[i]; //maximul nou devine acel element
        }
    }
    return maxim;
}
int minVector(int a[], int n) //determina minimul dintre toate elementele vectorului a
{
    int i, minim;
    minim=a[0]; //presupunem minimul ca fiind primul element
    for (i=1; i<n; ++i) //parcurgem toate celelalte elemente, incepand cu al doilea
    {
        if (a[i]<minim) //daca gasim unul mai mic decat minimul curent
        {
            minim=a[i]; //minimul nou devine acel element
        }
    }
    return minim;
}
double medieAritmVector(int a[], int n) //calculeaza media aritmetica a elementelor vectorului a
{
    double medie;
    int i, suma;
    suma=0; //pornim cu suma de la 0
    for (i=0; i<n; ++i) //parcurgem toate elementele
    {
        suma+=a[i]; //le adunam pe toate la suma
    }
    medie=(double)suma/n; //impartim suma obtinuta la numarul elementelor, pentru a obtine media
    return medie;
}
double medieGeomVector(int a[], int n) //calculeaza media geometrica a elementelor vectorului a
{
    double medie;
    int i, produs;
    produs=1; //pornim cu produsul de la 1, pentru ca vom face operatii de inmultire
    for (i=0; i<n; ++i) //parcurgem toate elementele
    {
        produs*=abs(a[i]); //le inmultim pe toate in variabila produs (in modul, deoarece trebuie luate in considerare valorile absolute pentru media geometrica)
    }
    medie=pow(produs, (double)1/n); //ridicam produsul obtinut la puterea 1/n, pentru a obtine radical de ordin n din acel produs, adica media geometrica
    return medie;
}
