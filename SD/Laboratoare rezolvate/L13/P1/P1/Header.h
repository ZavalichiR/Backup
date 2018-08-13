#pragma once
#include<iostream>
using namespace std;

#include <iostream>
#include <stdlib.h>
using namespace std;

#define nmax 20

struct OBST
{
	char KEY;
	OBST *left, *right;

};
void Matrix();
OBST *Build_OBST(int i, int j);
void Afisare(int A[nmax][nmax]);
void Citire();
void afisareTree(OBST *rad, int nivel);
