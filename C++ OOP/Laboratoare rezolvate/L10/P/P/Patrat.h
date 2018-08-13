#pragma once
#include"Figura.h"
class Patrat :public Figura
{
	int x, y; //coordonate colt stanga jos
	double l;
public:
	Patrat();
	Patrat(int xx, int yy, double ll, string culoare,string nume);
	~Patrat();
	void afisare();
	double Arie();
	double Perimetru();
};