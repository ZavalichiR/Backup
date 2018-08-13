
#include<iostream>
#include"header.h"
#include "conio.h"
using namespace std;

int main() 
{
	int n;
	int metoda;
	cout << "n=";
	cin >> n;
	cout<<" metoda: ";
	cin>>metoda;
	catalog c;
	c.citire();

	cout<<"Ce tip de sortare doriti? \n Alfabetic--->1 \n Dupa lungime--->2";
	cin >> metoda;
	if (metoda==1)
	{
		c.sortare1();
	}
	else
	{
		c.sortare2();
	}

	c.afisare();

	c.dealocareVSiruri;

	 _getch();
	return 0;
}