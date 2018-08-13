# pragma once
# include<iostream>
# include<conio.h>

using namespace std;

class Figura{
public:
	virtual void citire() = 0;
};


class Patrat :public Figura{
	int x, y, l;
public:
	Patrat()
	{
		x = 0;
		y = 0;
		l = 0;
	}
	void citire()
	{
		cout << "pp";
	}
	void paint();
	int read(char *readBuff);
};

class Dreptunghi :public Figura{
	int x, y, l, L;
public:
	Dreptunghi()
	{
		x = 0;
		y = 0;
		l = 0;
		L = 0;
	}
	void citire()
	{
		cout << "pp";
	}
	int read(char *readBuff);
	void paint();
};

class Line:public Figura{
private:
	int x1, y1, x2, y2;
public:
	Line()
	{
		x1 = x2 = y1 = y2 = 0;
	}
	void citire()
	{
		cout << "pp";
	}
	int read(char *readBuff);
	void paint();

};
class Triunghi :public Figura{
private:
	int x0, y0,x1,y1, x2, y2;
public:
	Triunghi()
	{
		x0=y0=x1 = x2 = y1 = y2 = 0;
	}
	void citire()
	{
		cout << "pp";
	}
	int read(char *readBuff);
	void paint();

};

class Cerc :public Figura
{
	int a, b, r;
public:
	Cerc()
	{
		a = b = r = 0;
	}
	void citire()
	{
		cout << "pp";
	}
	void paint();
	int read(char *readBuff);
};