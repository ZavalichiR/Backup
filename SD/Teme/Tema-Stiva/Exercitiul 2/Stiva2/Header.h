#ifndef _STIVA2_H
#define _STIVA2_H
#include<iostream>
using namespace std;

class Stiva
{
	int n;
	int dim;
	int *v;
public:
	Stiva();
	~Stiva();
	void push(int val);
	int pop();
};

void citireV(int v[], int nr);
void afisareV(int v[], int nr);
void inversare(int v[], int nr);

#endif
