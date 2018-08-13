#include"Dreptunghi.h"
Dreptunghi::Dreptunghi()
{
	x1 = y1 = x2 = y2 = 0;

}
Dreptunghi::Dreptunghi(int xx1, int yy1, int xx2, int yy2)
{
	this->x1 = xx1;
	this->y1 = yy1;
	this->x2 = xx2;
	this->y2 = yy2;
}
double Dreptunghi::Aria()
{
	double l = y2 - y1;
	double L = x2 - x1;
	return l*L;
}
void Dreptunghi::afisare()
{
	cout << "\n--Dreptunghi--";
	cout << "\nColt stanga jos (x1,y1)=(" << x1 << "," << y1 << ")";
	cout << "\nColt dreapta sus (x2,y2)=(" << x2 << "," << y2 << ")";
}
double Dreptunghi::Perimetru()
{
	return 2 * (y2 - y1 + x2 - x1);
}