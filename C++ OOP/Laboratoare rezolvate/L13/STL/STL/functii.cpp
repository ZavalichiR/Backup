#include"Header.h"
masina::masina()
{
	marca = nullptr;
	culoare = nullptr;
	pret = 0;
	viteza = 0;
}
masina::masina(char *m, char *c, int p, double vi)
{
	marca = new char[strlen(m) + 1];
	strcpy_s(marca, strlen(m) + 1, m);
	culoare = new char[strlen(c) + 1];
	strcpy_s(culoare, strlen(c) + 1, c);
	pret = p;
	viteza = vi;
}
void masina::afisare()
{
	cout <<"Marca: " <<marca << endl;
	cout <<"Culoarea: "<<culoare << endl;
	cout <<"Pretul: "<< pret<<" euro" << endl;
	cout <<"Viteza: "<< viteza <<" km/h"<< endl;
}
bool masina::operator<(masina* m)
{
	bool ok = 0;
	if (this->viteza < m->viteza)
	{
		ok = 0;
	}
	else
	{
		if (this->viteza > m->viteza)
		{
			ok = 1;
		}
		else
		{
			if (this->pret > m->pret)
				ok = 1;
			else
				ok = 0;
		}
	}
	return ok;
}