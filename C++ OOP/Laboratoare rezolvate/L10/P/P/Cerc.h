#pragma once
#include"Figura.h"
class Cerc :public Figura
{
	int x, y, r;
public:
	Cerc();
	Cerc(int x, int y, int r, string C,string n);
	~Cerc();
	void afisare();
	double Arie();
	double Perimetru();
};