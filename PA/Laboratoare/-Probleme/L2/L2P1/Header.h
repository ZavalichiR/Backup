#pragma once
#include<iostream>
using namespace std;
struct Nod
{
	int data;
	Nod *succ;
};
void inserarePopescu(Nod *&Head, int val,int &c);
Nod *returnLast(Nod *head);
void inserareIonescu(Nod *&Head,int val,int &c);
void afisare(Nod *lista);
void inserare(Nod *&lista, int val, int &c);
