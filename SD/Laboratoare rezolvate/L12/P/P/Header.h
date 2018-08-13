#pragma once

#include<iostream>
using namespace std;

void insert(int *&h, int val, int n);
void inordine(int *v, int i, int n);
void inordine0(int *v, int i, int n);
void max_heap(int *a, int i, int n);
void build_maxheap(int *a, int n);
void heapsort(int* a, int n);