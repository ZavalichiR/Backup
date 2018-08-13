#pragma once
#include<iostream>
#include<conio.h>
using namespace std;

struct Nod {
	int data;
	Nod *succ;
};

void creare(Nod *&lista, int val,int i);
void afisare(Nod *lista);
void inversareLegaturi(Nod *&head);