#include"Patrat.h"
Patrat::Patrat()
{
	x = 0; y = 0; l = 0;
}
Patrat::Patrat(int xx, int yy, double ll, string culoare,string nume) :Figura(culoare,nume)
{
	x = xx;
	y = yy;
	l = ll;
}
Patrat::~Patrat()
{
	cout << "\n~Patrat()" << endl;
}
void Patrat::afisare()
{
	Figura::afisare();
	cout << " x=" << x << " y=" << y << " l=" << l << endl;
	
}
double Patrat::Arie()
{
	return l*l;
}
double Patrat::Perimetru()
{
	return 4 * l;
}