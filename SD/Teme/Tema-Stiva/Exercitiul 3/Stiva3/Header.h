#ifndef _STIVA3_H
#define _STIVA3_H
#include<iostream>
using namespace std;

class Stiva
{
	int n;
	int dim;
	char *v;
public:
	Stiva();
	~Stiva();
	int getN();
	void push(char val);
	char pop();
};

int verificare(char *sir);

#endif
