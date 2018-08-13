#ifndef _P1_
#define _P1_
#include<iostream>
#include<conio.h>
using namespace std;

class Dreptunghi {
private:
	int lungime;
	int latime;

public:
	void SetLungime(int lungime);
	void SetLatime(int latime);
	int Aria();
	int Perimetru();

	Dreptunghi();
	Dreptunghi(int lung, int lat);
	Dreptunghi(Dreptunghi &d);
	~Dreptunghi();
};
class Patrat {
private:
	int latura;

public:
	void SetLatura(int lat);
	int Aria();
	int Perimetru();
	Patrat();
	Patrat(int lat);
	Patrat(Patrat &d);
	~Patrat();
};
class Cerc {
private:
	int pi;
	int raza;

public:
	void SetRaza(int raza);
	int Aria();
	int Perimetru();
	Cerc();
	Cerc(int raza);
	Cerc(Patrat &d);
	~Cerc();
};


class Multime {
	private:
		int *date;
		int dim;
		int n;
	public:
		Multime();
		Multime(int d);
		~Multime();
		Multime(Multime &s);

		void Adauga(int val);
		void Afisare();
		void Extrage(int val);
	};


class Stiva
{
	int n;
	int dim;
	int *v;
public:
	Stiva();
	~Stiva();
	void push(int val);
	int pop();
	int top();
	void print();
};




#endif