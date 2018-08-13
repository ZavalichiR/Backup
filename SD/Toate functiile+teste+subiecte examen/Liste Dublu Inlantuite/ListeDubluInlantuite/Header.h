#pragma once
#include<iostream>
using namespace std;
struct Nod{
	int data;
	Nod *succ, *prev;
};

void inserareFata(Nod *&head, int val);
void inserareCoada(Nod *&head, int val);
void afisare(Nod *head);
void cautare(Nod *head, int val);
void stergere(Nod *&head, int val);
void inserarePozitie(Nod *&head, int val, int poz);