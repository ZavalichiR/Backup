#pragma once
#include<iostream>
using namespace std;

enum tip{ evil, divine };
struct date{
	int zi, luna, an;
};

class Mamifer{
	tip x;
	date nastere;
public:
	Mamifer(tip a, date d);
	void mananca();
	void mergeLaBaie();
	void hranesteAnimalele();
	virtual void miauna() = 0;
};

class Bunica : public Mamifer{

public:
	Bunica(tip a, date d) :Mamifer(a, d){};
};

class PisicaDeCartier : public Mamifer{

public:
	PisicaDeCartier(tip a, date d) :Mamifer(a, d){};
	void miauna(){ cout << "Miau" << endl; };
};

class PisicaSiameza : public Mamifer{

public:
	PisicaSiameza(tip a, date d) :Mamifer(a, d){};
	void miauna(){ cout << "Miau" << endl; };
};

class PisicaEgipteana : public Mamifer{

public:
	PisicaEgipteana(tip a, date d) :Mamifer(a, d){};
	void miauna(){ cout << "Miau" << endl; };
};
