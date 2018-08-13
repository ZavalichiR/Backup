#pragma once
#include<iostream>
using namespace std;

int cautareBinara(int a[5000], int n, int val,double &c);

struct Nod{
	int data;
	Nod *stg, *drt;
};

Nod *makeNod(int val);
void inserare(Nod *&rad, int val);
void inordine(Nod *rad);
Nod *cautArboreBinar(Nod *rad, int val,double &c);