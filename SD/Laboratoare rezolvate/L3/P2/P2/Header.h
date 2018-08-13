#ifndef _P2_
#define _P2_

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string>
using namespace std;


 struct persoana
 {

	int nrt;
	char nume[100];
	void citireAgenda();

};


struct Nod
{
	Nod *leg;
	persoana data;
};

void inserare(Nod *&cap, persoana val);
void afisare(Nod *lista);
void afisareAgenda(persoana data);
void stergere(Nod *&lista, char nume[100]);
void insertOrder(Nod *&lista, persoana val);
void cautare(Nod *&lista, int nrt);
#endif