#pragma once
#include<iostream>
using namespace std;
typedef double tip;
void citireM(int **a, int n);
//void afisareM(tip **a, int n);
//tip** inmultireM(tip **a, tip **b, int n);

int** aloca2D(int n);
void dealoca2D(int **&A, int n);
void generareMatrice(int **A, int n);
void afisareMatrice(int **A, int n);
int** adunareMatrice(int** A, int** B, int n);
int** sfert(int** A, int n, int nrSfert);
int** concatenareMatrice(int** A, int** B, int** C, int** D, int dim);
int** inmultireMatrice(int** A, int** B, int n);