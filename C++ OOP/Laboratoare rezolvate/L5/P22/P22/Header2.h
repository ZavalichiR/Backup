#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"Header1.h"
using namespace std;
struct MultimePersoana
{
	int n, dim;
	Persoana *p;
public:
	MultimePersoana();
	MultimePersoana(int d);
	~MultimePersoana();
	void introduce(Persoana P);
	void extrage(Persoana P);
	void afiseaza();

};