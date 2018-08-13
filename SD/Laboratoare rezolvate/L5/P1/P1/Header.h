#ifndef _P1_H
#define _P1_H
#include<iostream>
using namespace std;

#define dim 20
typedef int Atom;

struct StivaOrdonata{
	int sp;
	Atom vect[dim];
};
//Gestionare adrese mici->adrese mari
/*void crearestiva(StivaOrdonata &S);
int isEmpty(StivaOrdonata S);
void push(StivaOrdonata &S, Atom val);
Atom pop(StivaOrdonata &S);
Atom top(StivaOrdonata S);
void testStiva(StivaOrdonata &S);
*/

//Gestionare adrese mari->mici
void crearestiva(StivaOrdonata &S);
int isEmpty(StivaOrdonata S);
void push(StivaOrdonata &S, Atom val);
Atom pop(StivaOrdonata &S);
Atom top(StivaOrdonata S);
void testStiva(StivaOrdonata &S);

struct StivaInalntuita{
	Atom data;
	StivaInalntuita *leg;
};

void Creare(StivaInalntuita *&S);
void Initializare(StivaInalntuita *&S);
void Push(StivaInalntuita *&S, Atom data);
Atom Pop(StivaInalntuita *&S);
bool IsEmpty2(StivaInalntuita *S);
Atom Top(StivaInalntuita *S);
void Testare();

void EvaluareFormaPostafixata(char s[]);

#endif