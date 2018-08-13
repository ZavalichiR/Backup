#include"Persoana.h"
PersoanaAC::PersoanaAC()
{
	cout << "Constr. afara arg. PersoanaAC" << endl;
	m_sCnp = string(13, '0');
	m_sNume = "";
	m_sAdresa = "";
}
PersoanaAC::PersoanaAC(string cnp, string nume, string adresa)
{
	cout << "Constr. cu arg. PErsoana AC" << endl;
	m_sCnp = cnp;
	m_sNume = nume;
	m_sAdresa = adresa;
}
PersoanaAC::~PersoanaAC()
{
	cout << "Destructor PersoanaAC" << endl;
}
void PersoanaAC::afisareProfil()
{
	cout << "Nume: "<< m_sNume << endl;
	cout << "CNP: " << m_sCnp << endl;
	cout << "Adresa: " << m_sAdresa << endl;
}
void PersoanaAC::schimbareAdresa(string adresaNoua)
{
	this->m_sAdresa = adresaNoua;
}