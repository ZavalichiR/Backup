#pragma once

#include<string>
#include<iostream>
#include<Windows.h>
using namespace std;

struct Nod{
	char data;
	int frecventa;
	Nod *stg, *drt;
	string codificare;
};


void inord(Nod *v);
void insert(Nod *v[27], int &n, Nod *val);
Nod *remove(Nod *v[27], int &n);
void percolate(Nod *v[27], int n, int i);
void heap_min(Nod *v[27], int n);

void Huffman(Nod *varf, int V[27], int n);
void afisare(char* s, Nod* varf, int &i, Nod* rad);

void setColor(int i);
