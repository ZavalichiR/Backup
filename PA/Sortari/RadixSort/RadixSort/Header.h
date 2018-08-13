#include <iostream>
using namespace std;

#define k 10

struct Nod{
	Nod *next;
	int data;
};

void InsereazaLista(Nod *&Head, int element);
void afisareLista(Nod *Head);
void StergereNod(Nod *&Head);
void radixSort(Nod *&Head, int m);

void afisareVector(int a[k]);
void concatenare(Nod *&Nead1, Nod *Head2);