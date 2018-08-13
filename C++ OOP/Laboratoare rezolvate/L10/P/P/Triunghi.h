#pragma once
#include"Figura2.h"
class Triunghi:public Figura2
{
	int x1, y1, x2, y2, x3, y3;
public:
	Triunghi();
	Triunghi(int xx1, int yy1, int xx2, int yy2, int xx3, int yy3);
	~Triunghi();
	void afisare();
	double Perimetru();
	double Aria();
	double SemiPerimetru();
};