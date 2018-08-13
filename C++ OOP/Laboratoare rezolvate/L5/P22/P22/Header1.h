#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
class Persoana
{
	int varsta;
	char *nume;
	char *prenume;
	char gen;
public:
	Persoana();
	Persoana(int, char*, char*, char);
	Persoana(const Persoana& p);
	~Persoana();
	void citire();
	void citire2();
	void afisare();
	int compara(Persoana &P);
	void operator=(Persoana &p);

};