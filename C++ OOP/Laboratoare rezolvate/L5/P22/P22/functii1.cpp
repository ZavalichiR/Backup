#include"Header1.h"
Persoana::Persoana()
{
	varsta = 0;
	gen = '\0';
	//nume = new char[100];
	//prenume = new char[100];
	nume = nullptr;
	prenume = nullptr;
}
Persoana::Persoana(int v, char *n, char *p, char g)
{
	varsta = v;
	this->gen = g;
	int len;

	len = strlen(n) + 1;
	this->nume = new char[len];
	strcpy_s(nume, len, n);

	len = strlen(p) + 1;
	this->prenume = new char[len];
	strcpy_s(prenume, len, p);
	cout << "constr cu argumente" << endl;
}
Persoana::Persoana(const Persoana &p)
{
	varsta = p.varsta;
	gen = p.gen;
	int len;

	len = strlen(p.nume) + 1;
	nume = new char[len];
	strcpy_s(nume, len, p.nume);

	len = strlen(p.prenume) + 1;
	prenume = new char[len];
	strcpy_s(prenume, len, p.prenume);
	cout << "constructor de copiere" << endl;
}
void Persoana::citire()
{
	char buffer[100];
	int len;
	cout << "\nVarsta: ";
	cin >> varsta;

	cout << "Nume: ";
	cin.ignore(100, '\n');
	cin.getline(buffer, 100);
	/*if (nume)
	{
		delete[] nume;
		nume = nullptr;
	}*/
	len = strlen(buffer) + 1;
	nume = new char[len];
	strcpy_s(nume, len, buffer);

	cout << "Prenume: ";
	cin.getline(buffer, 100);
	/*if (prenume)
	{
		delete[] prenume;
		prenume = nullptr;
	}*/
	len = strlen(buffer) + 1;
	prenume = new char[len];
	strcpy_s(prenume, len, buffer);

	cout << "Gen: ";
	cin >> gen;
}
void Persoana::afisare()
{
	cout << endl;
	cout << "Nume: " << nume << endl;
	cout << "Prenume: " << prenume << endl;
	cout << "Varsta: " << varsta << endl;
	cout << "Gen: " << gen << endl;
}
Persoana::~Persoana()
{
	varsta = 0;
	gen = '\0';

	if (nume)
	{
		delete[] nume;
		nume = nullptr;
	}
	if (prenume)
	{
		delete[]prenume;
		prenume = nullptr;
	}
}
int Persoana::compara(Persoana &P)
{
	if (strcmp(nume, P.nume) == 0 && strcmp(prenume, P.prenume) == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Persoana::citire2()
{
	char buffer[100];
	cout << "Nume: ";
	cin.ignore(100, '\n');
	cin.getline(buffer, 100);
	int len = strlen(buffer) + 1;
	nume = new char[len];
	strcpy_s(nume, len, buffer);

	cout << "Prenume: ";
	cin.getline(buffer, 100);
	len = strlen(buffer) + 1;
	prenume = new char[len];
	strcpy_s(prenume, len, buffer);

}
void Persoana::operator=(Persoana &p)
{
	varsta = p.varsta;
	if (nume)
	{
		delete[] nume;
		nume = nullptr;
	}
	if (prenume)
	{
		delete[] prenume;
		prenume = nullptr;
	}
	nume = new char[strlen(p.nume) + 1];
	prenume = new char[strlen(p.prenume) + 1];
	strcpy_s(this->nume, strlen(p.nume) + 1, p.nume);
	strcpy_s(this->prenume, strlen(p.prenume) + 1, p.prenume);
	this->gen = p.gen;
}