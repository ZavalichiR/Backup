#pragma once
#include<iostream>
#include<stdio.h>

using namespace std;

#define plusInf 999999
void FloydWarshall(int **L, int **P, int n);
int** aloca2D(int n);
void dealoca2D(int **&A, int n);
void afisareDrumuri(int** L, int** P, int n, int i, int j);
void init_L(int **L);
