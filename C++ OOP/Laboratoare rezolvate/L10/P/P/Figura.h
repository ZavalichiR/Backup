#pragma once
#include<iostream>
#include<string>
using namespace std;
class Figura
{
	string culoare;
	string nume;
public:
	Figura();
	Figura(string a,string n);
	string GetNume()
	{
		return nume;
	}
	Figura::~Figura();
	virtual void afisare();
	virtual double Arie();
	virtual double Perimetru();
};


