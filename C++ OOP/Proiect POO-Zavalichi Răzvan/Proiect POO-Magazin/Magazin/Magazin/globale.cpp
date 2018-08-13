#include<iostream>
#include<conio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>
#include "globale.h"
using namespace std;

//Functii globale ce vor fi folosite in toate modulele

void pauza() {
	cout << "\n\n  Apasati orice tasta ... ";
	_getch();
}

void clrscr() {
	system("cls");
}

char *citesteSir()
{
	char sir[50];
	char *s = 0;
	int a;
	fflush(stdin);
	cin >> sir;
	a = strlen(sir) + 1;
	s = new char[a];
	assert(s);
	strcpy(s, sir);
	return s;
}

bool insideTree(int x, int y, const int width, const int height)
{
	x -= width / 2;
	return  (y <= 0.25 * height && abs(x) <= y)
		|| (0.2 * height <= y && y <= 0.6 * height && abs(x) <= y - 0.2 * height)
		|| (0.5 * height <= y && y <= height && abs(x) <= y - 0.5 * height)
		|| (height * 0.5 <= y && abs(x) < 0.1 * width);
}

void mesaj()
{
	const int width = 15;
	const int height = 12;
	for (int y = 0; y < width; ++y) 
	{
		for (int x = 0; x < width; ++x) 
			std::cout << (insideTree(x, y, width, height) ? '*' : ' ');
		if (y == 6)
			cout << "\t\t\t        -=Fitness Store=-";
		if (y == 7)
			cout << "\t\t\tVa multumim pentru alegerea facuta!";	
		std::cout << "\n";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
}
