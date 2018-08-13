#pragma once
#include<iostream>
#include<string>
using namespace std;
class Persoana
{
private:
	string m_sNume;
	int m_iVarsta;
public:
	Persoana(string nume, int varsta) :m_sNume(nume), m_iVarsta(varsta){}
	int getVarsta()
	{
		return m_iVarsta;
	}

};
