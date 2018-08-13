#pragma once
#include<iostream>
using namespace std;

struct Nod{
	int data;
	Nod *succ;
};

Nod *insertEnd();
void inserareCap(Nod *&head, int val);
void inserareCoada(Nod *&head, int val);
void inserareOrdine(Nod *&head, int val);
void afisareCapCoada(Nod *head);
void afisareCoadaCap(Nod *head);
void cautare(Nod *head, int val);
void sterge(Nod *&head, int val);
void stergePozitie1(Nod *&lista, int poz);// sterge dupa pozitie Coada-Cap
void stergePozitie12(Nod *&lista, int poz);// sterge dupa pozitie Coada-Cap
void stergePozitie2(Nod *&lista, int poz);// sterge dupa pozitie Cap-coada
void ordonare(Nod *&lista);
Nod *inversareLegaturi(Nod *&head);

//Aceste functii usureaza meniul
void inserareaInFata(Nod *&head);
void inserareInSpate(Nod *&head);
void Cauta(Nod *&head);
void Sterge(Nod *&head);
void Inverseaza(Nod *&head);

//Functii curs
void inserarePozitie(Nod *&head, int val, int pozitie);
void unireListe(Nod *&lista1, Nod *&lista2); 
Nod *interclasare(Nod *lista1, Nod *lista2);//instabila
void interclasare2(Nod *&lista1, Nod *&lista2);// 100% stabila
int count(Nod *lista);
void stergeElementePare(Nod *&lista);
Nod *mutaElementePare(Nod *&lista);
void palindrom(Nod *p, Nod *&q, int &ok);