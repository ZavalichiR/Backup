#ifndef _ARBORE_H
#define _ARBORE_H
#include<iostream>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
using namespace std;

struct Nod {
	char data;
	Nod *stanga, *dreapta;
};
struct Stiva{
	Nod *data;
	Stiva *leg;
};


void initS(Stiva *&S);
void creareS(Stiva *&S);
void push(Stiva *&S,Nod *val);
Nod* pop(Stiva *&S);

Nod *creare();
void adauga(Nod *&a,char valoare);

void postordineRecursiv(Nod *a);
void postordineIterativ(Nod *a);
void inordineRecursiv(Nod *a);
void inordineIterativ(Nod*a);
void preordineRecursiv(Nod *a);
void preordineIterativ(Nod *a);
#endif