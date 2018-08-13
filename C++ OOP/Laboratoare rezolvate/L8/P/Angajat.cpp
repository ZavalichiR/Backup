#include "Angajat.h"
Angajat::Angajat(char*nume, char*prenume,Data *d, int salarii, Data*ang) :Persoana(nume, prenume, d)
{
	cout << "S-a apelat constructorul cu parametri ----Angajat" << endl;
	this->salarii = salarii;
	this->dataAngajare = new Data(*ang);
}
Angajat::~Angajat()
{
	cout << "S-a apelat destructorul ----Angajat" << endl;
	delete dataAngajare;

}
Data *Angajat::GetDataAngajare()
{
	return dataAngajare;
}
int Angajat::GetSalariu()
{
	return salarii;
}
Data Angajat::getVarstaAngajare()
{
	int zi, luna, an;
	an = this->dataAngajare->getAn() - this->getDataNastere()->getAn();

	luna = this->dataAngajare->getLuna() - this->getDataNastere()->getLuna();
	if (luna < 0)
	{
		luna = 12-abs(luna);
		an = an - 1;
		if (an < 0)
			cout << "Date eronate" << endl;
	}
	zi = this->dataAngajare->getZi()- this->getDataNastere()->getZi();
	if (zi < 0)
	{
		zi = 30-abs(zi);
		luna = luna - 1;
		if (luna < 0)
		{
			luna = 12 - abs(luna);
			an = an - 1;
		}
	}
	Data rez(an, luna, zi);
	return rez;
}
void Angajat::afisare()
{
	Persoana::afisare();
	cout << "Data de angajare: "<< dataAngajare->getAn() << "." << dataAngajare->getLuna() <<"." << dataAngajare->getZi() << endl;
	cout << "Salariu: " << salarii << endl;
	

}
void Angajat::afisarePerioadaMuncita(Data &dataCurenta)
{
	int aa, la, za, z, l, a;
	aa = this->dataAngajare->getAn();
	la = this->dataAngajare->getLuna();
	za = this->dataAngajare->getZi();
	a = dataCurenta.getAn() - aa;
	l = dataCurenta.getLuna() - la;
	z = dataCurenta.getZi() - za;
	if (a < 0)
		cout << "Date eronate" << endl;
	else
	{
		if (z < 0)
		{
			l = l - 1;
			z = z + 30;
		}
		if (l < 0)
		{
			a = a - 1;
			l = l + 12;
		}
		cout << a << '.' << l << '.' << z << endl;
	}
}