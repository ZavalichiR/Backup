#ifndef _HASH_H
#define _HASH_H
#include<iostream>
#include<stdlib.h>
using namespace std;
#define M 10 //dimensiunea tabelei
struct nod{
	char *cheie;
	nod *succ;
};
void initializare();
int f( char*cheie);
void inserare(char *cheie);
void afisare();
nod *cautare(char *cheie);
void stergere(char *cheie);
#endif