#pragma once
#include"publicitate.h"
class revista :public publicatie
{
	string editura;
	unsigned int tiraj;
public:
	revista() :publicatie()
	{
		editura = "";
		tiraj = 0;
	}
	revista(string nume, unsigned int nr, string ed, unsigned int t) :publicatie(nume, nr)
	{
		editura = ed;
		tiraj = t;
	}
	~revista()
	{
		cout << "apel destr. revista\n";
	}
	void afisare()
	{
		publicatie::afisare();
		cout << "editura" << editura << endl;
		cout << "tiraj" << tiraj << endl;
	}
	string operator+()
	{
		string c;
		c = publicatie::gettitlu();
		c += editura;
		return c;

	}
	unsigned int gett()
	{
		return tiraj;
	}
};