#ifndef _HASH_H
#define _HASH_H
#include<iostream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
using namespace std;


#define M 40  //dimensiunea tabelului de dispersie

struct Student {
	char *nume;
};

typedef struct Student Atom;

struct _NOD {
	Atom student;
	struct _NOD *succ;
};

// Se scriu sinonime :

typedef struct _NOD  NOD;
typedef NOD* PNOD;


// Se declara functiile pentru structura Student :

Atom CitesteStud(void);
void AfisareStud(PNOD Data, int index);

// Se declara functii de dispersie :

int ASCII(char *n);
int Knuth(char *n);
int Bernstein(char *n);
int SDBM(char *n);

// Se declara functiile pentru structura NOD :

void Initializare_HT(PNOD HT[]);
void Afisare_HT(PNOD HT[]);
PNOD Cautare_HT(PNOD HT[], char *n, int(*Functie)(char*));
int Inserare_HT(PNOD HT[], int(*Functie)(char *));

#endif;