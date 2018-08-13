#ifndef _Recuperare_
#define _Recuperare_
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct Student {
	char *nume;
	int nota;
	void citire();
	void afisare();
};

void CitireVect(int v[10], int n);
void AfisareVect(int v[10], int n);
void BSort(int v[10], int b);
float factorial(int n);
float factorial2(int n);
int cmmdc(int n,int m);
float putere(float x, int n);
#endif
