#ifndef _OPERATORI_H
#define _OPERATORI_H
#include<iostream>
#include"Header.h"
using namespace std;

class complex
{
	int re;
	int im;
public:
	complex();
	complex(int x, int y);
	complex(complex &c);
	//~complex();
	void afisare();

	//complex& operator=(complex &c);//operatorul egal
	//void operator=(complex &c);
	complex operator=(complex c);
	complex operator+(complex &c);//operatorul plus
	complex operator-(complex &c);//operatorul minus
	complex operator*(complex &c);//operatorul produs

	//friend complex& operator=(complex &c1, complex &c2);
	//friend complex operator+(complex &c1, complex &c2);
	//friend complex operator-(complex &c1, complex &c2);
	//friend complex operator*(complex &c1, complex &c2);


	complex &operator++();//operatorul prefixat
	complex operator++(int);//operatorul postfixat
	complex &operator--();//operatorul prefixat
	complex operator--(int);//operatorul postfixat
	

	//friend complex& operator++(complex &c);  //prefixat
	//friend complex operator++(complex &c, int);//postfixat
	//friend complex& operator--(complex &c);  //prefixat
	//friend complex operator--(complex &c, int);//postfixat

	friend std::istream& operator>>(std::istream& input, complex &c);
	friend std::ostream& operator<<(std::ostream& output, complex &c);
};



#endif