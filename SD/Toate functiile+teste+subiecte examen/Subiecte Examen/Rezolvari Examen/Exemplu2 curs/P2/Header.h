#pragma once
#include<iostream>
using namespace std;
typedef int tip;
struct Nod{
	tip data;
	Nod *succ;
};

void inserare(Nod *&lista, tip val);
void afisare(Nod *lista);
Nod *schimbareLegaturi(Nod *&lista);
void sterge(Nod *&lista, int poz);
void ordonare(Nod *&lista);
