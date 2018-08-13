#pragma once
#include<iostream>
using namespace std; 
class Matrice
{
	int nrL, nrC;
	int **elem;
public:
	Matrice();
	Matrice(int nl, int nc);
	Matrice(const Matrice &m);
	~Matrice();
	void citire();
	void afisare();
	Matrice operator*(Matrice m);
	Matrice operator=(Matrice m);
	Matrice operator+(int k);
	Matrice operator+(Matrice m);
	Matrice operator-(Matrice m);
	int operator==(Matrice m);
	Matrice operator~();
	double operator[](int x);
	Matrice operator++();
	Matrice operator++(int);
	friend Matrice operator+(int a, Matrice b);
};
