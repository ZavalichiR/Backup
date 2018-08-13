#ifndef _STIVA_H
#define _STIVA_H
#include<iostream>
using namespace std;

//Memoria stivei a fost alocata static

#define dim 80
struct Stiva
{
	int sp;
	char vect[dim];

};

void InitS(Stiva &S);
char Pop(Stiva &S);
int EmptyS(Stiva S); //returneaza 1 pentru multimea vida
void Push(Stiva &S, char val); 
char Top(Stiva S);
int Verificare(char vect[]);

#endif