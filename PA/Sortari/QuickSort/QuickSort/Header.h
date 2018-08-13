#pragma once
#include<iostream>
using namespace std;
void partitioneaza(int a[], int p, int q, int &k);
void partitioneaza2(int a[], int p, int q, int &k);
void QuickSort2(int a[], int p, int q);
void QuickSort1(int a[], int p, int q);
int compare(const void *a, const void *b);

int partition1(int *a, int start, int end);
void quicksort(int *a, int start, int end);
int partition(int *a, int start, int end);