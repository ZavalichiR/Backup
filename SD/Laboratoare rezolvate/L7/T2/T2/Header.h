#pragma once
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

#define M 20
struct Nod{
	char *key;
	Nod *leg;
};
void init();
void inserare(char *key);
void sterge(char *key);
Nod *cautare(char *key);
int f(char *key);
void afisare();
void sortare();
void afisareFrecv(int fr[128]);
void calculareFrecventa(char *text, int fr[128]);