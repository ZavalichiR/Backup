#include"Cerc.h"
Cerc::Cerc()
{
	x = y = r = 0;
}
Cerc::Cerc(int xx, int yy, int rr, string culoare,string nume) :Figura(culoare,nume)
{
	x = xx;
	y = yy;
	r = rr;
}

Cerc::~Cerc()
{
	cout << "\n~Cerc()" << endl;
}
void Cerc::afisare()
{
	Figura::afisare();
	cout << "\n Centru: (" << x << "," << y<<")";
	cout << "\n Raza: " << r << endl;
	

}
double Cerc::Arie()
{
	return 3.14*r*r;
}
double Cerc::Perimetru()
{
	return 2 * 3.14*r;
}