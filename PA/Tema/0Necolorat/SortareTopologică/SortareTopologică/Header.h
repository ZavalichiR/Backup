#pragma once
#include <iostream>
#include<Windows.h>
using namespace std;

struct Elem {
	int data;
	Elem* succ;
};

struct Digraf {
	int *a;
	Elem **l;
};

void initDigraf(Digraf &D, int nrVf);
void insert(Elem *&cap, int val);
void citireDigraf(Digraf &D, int nr);
int* sortareTopologicaBFS(Digraf D, int nrVf);