#pragma once
#include<iostream>
#include<vector>
using namespace std;

struct Punct{
	int x, y;
};

struct Obiect{
	int in;
	int greutate;
	int valoare;
};

vector<Obiect>init();
vector<Punct> interclasare(vector<Punct>s, vector<Punct>t);
vector<vector<Punct>> Rucsac(vector<Obiect>&obj);
void Afisare(vector<vector<Punct>>Sfinal);
Punct startFind(vector<vector<Punct>> Sfinal, int M);
bool apartine(Punct a, vector<Punct>S);
vector<Obiect>InRucsac(vector<vector<Punct>> Sfinal, int M, vector<Obiect> &obj);
void rucsacAfisareTotala(vector<Obiect>a);