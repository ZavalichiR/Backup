#include <iostream>
#include "Header.h"

using namespace std;


void student::Read(void)
{
	cout << "Nr matricol:";
	cin >> nr_matricol;
	cout << "Nume student:";
	cin.ignore(100, '\n');
	cin.getline(nume,14);
	cout << "Gen:";
	cin >> gen;
	cout << "Nota:";
	cin >> nota;
}

void student::Write(void)
{
	cout << "Nr matricol:"<<nr_matricol<<endl;
	cout << "Nume student:"<<nume<<endl;
	cout << "Gen:"<<gen<<endl;
	cout << "Nota:"<<nota<<endl;
}