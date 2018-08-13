#pragma once
#include<iostream>
using namespace std;

void insert(int *h, int val, int &n);
int sterge(int *h, int &n);
void percolate(int *h, int i, int n);
void creareMaxHeap(int *h, int n);
void creareMaxHeap2(int *h, int n);
void sortareHeap(int *h, int n);
void inordine(int *v, int i, int n);
void postordine(int *v, int i, int n);
int max(int *h, int i, int n);
bool isCauare(int *h, int i, int n);
bool isHeap(int *h, int i, int n);