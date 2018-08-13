
#include<iostream>
#include"header.h"
#include "conio.h"
using namespace std;

int main() 
{
	int n;
	int metoda;
	catalog c;

	char** vsiruri;
	cout << "Introduceti numarul de siruri: ";
	cin >> n;
	c=creareCatalog(n);

	cout<<"\nIntroduceti sirurile de caractere:"<<endl;
	c.vsiruri=c.citire(c.nr);

	cout << "\nSirurile citite sunt: " << endl;
	afisareVSiruri(c.vsiruri,c.nr);

	cout << "\n\nCe tip de sortare doriti?" << endl;
	cout << "1--->Alfabetic" << endl << "2--->Dupa lungime" << endl;
	cout << "Raspuns: ";
	cin >> metoda;
	if (metoda==1)
	{
		c.sortare1(c.vsiruri,c.nr);
	}
	else
	{
		c.sortare2(c.vsiruri,c.nr);
	}

	cout<<"\n\n Sirurile dupa sortare: \n";
	afisareVSiruri(c.vsiruri,c.nr);
	 dealocareVSiruri(c.vsiruri,c.nr);

	 cout << "                     .....::::::::::END:::::::::........";
	 cout << "\n                                  Press any key  ";
	 _getch();
	return 0;
}