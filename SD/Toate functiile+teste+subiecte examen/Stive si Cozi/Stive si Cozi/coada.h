#pragma once
#include"stiva.h"
#define dim 10

//    Alocare Statica
struct coada1{
	int vect[dim];
	int head, tail;
};
void initt(coada1 &c);
int nezPoz(int x);
void put(coada1 &c, int val);
int get(coada1 &c);
void front(coada1 &c);
void coada1Main();


//    Alocare Dinamica
struct element
{
	int data;
	element *succ;
};
struct coada2{
	element *tail, *head;
};
void inittC(coada2 *&c);
void putC(coada2 *&c, int val);
int getC(coada2 *&c);
void frontC(coada2 *&c);
void coada2Main();