#include"Figura2.h"
class Dreptunghi :public Figura2
{
	int x1, y1, x2, y2;//stanga jos-dreapta sus;
public:
	Dreptunghi();
	Dreptunghi(int xx1, int yy1, int xx2, int yy2);
	void afisare();
	double Aria();
	double Perimetru();
};