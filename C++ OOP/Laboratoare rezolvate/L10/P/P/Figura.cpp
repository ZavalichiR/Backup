#include"Figura.h"

Figura::Figura()
{
	culoare ="alb";
	nume = "Figura";
}
Figura::Figura(string a,string n)
{
	culoare = a;
	nume = n;
}
Figura::~Figura()
{
	cout << "~Figura()" << endl;
}
void Figura::afisare()
{
	cout << "\nNume: " << nume;
	cout << "\nCuloare: " << culoare;

}
double Figura::Arie()
{
	return 0;
}
double Figura::Perimetru()
{
	return 0;
}

