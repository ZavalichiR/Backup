#pragma once
#include<iostream>
#include<string>
using namespace std;
class Angajat
{
private:
	double m_dSalariu;
public:
	Angajat(double salariu) :m_dSalariu(salariu){}
	double getSalariu()
	{
		return m_dSalariu;
	}
};
