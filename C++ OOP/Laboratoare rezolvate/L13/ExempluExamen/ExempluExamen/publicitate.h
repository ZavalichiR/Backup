#pragma once
#include<iostream>
#include<string>
using namespace std;
class publicatie
{
	string titlu;
	unsigned int nrpag;
public:
	publicatie()
	{
		titlu = "0";
		nrpag = 0;
	}
	publicatie(string t, unsigned int nr) :titlu(t), nrpag(nr) {}
	~publicatie()
	{
		cout << "apel destructor publicatie\n";
	}
	virtual void afisare()
	{
		cout << "titlu:" << titlu << endl;
		cout << "numar pagini:" << nrpag << endl;
	}
	string gettitlu()
	{
		return titlu;
	}
	int getpag()
	{
		return nrpag;
	}
};