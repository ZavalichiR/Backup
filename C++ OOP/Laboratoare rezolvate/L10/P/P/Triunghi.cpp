#include"Triunghi.h"
Triunghi::Triunghi()
{
	x1 = y1 = x2 = y3 = 0;
}
Triunghi::Triunghi(int xx1, int yy1, int xx2, int yy2, int xx3, int yy3)
{
	x1 = xx1;
	y1 = yy1;
	x2 = xx2;
	y2 = yy2;
	x3 = xx3;
	y3 = yy3;
}
double Triunghi::Perimetru()
{
	double a, b, c;
	a= sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
	b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	return a + b + c;
}
void Triunghi::afisare()
{
	cout << "\n---Triunghi---";
	cout << "\n (x1,y1)=(" << x1 << "," << y1 << ")";
	cout << "\n (x2,y2)=(" << x2 << "," << y2 << ")";
	cout << "\n (x3,y3)=(" << x3 << "," << y3 << ")";
}

double Triunghi::SemiPerimetru()
{
	return Perimetru() / 2;
}
double Triunghi::Aria()
{
	double p = SemiPerimetru();
	double a, b, c;
	a = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	b = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2));
	c = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
	return sqrt(p*(p - a)*(p - b)*(p - c));
}
Triunghi::~Triunghi()
{
	cout << "Destructor triunghi" << endl;
}