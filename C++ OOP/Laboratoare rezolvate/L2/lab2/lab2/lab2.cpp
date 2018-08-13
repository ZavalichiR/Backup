#include <iostream>
#include "lab2.h"

using namespace std;
void ReadData(student*st)
{
	cout << "Nr matricol:";
	cin >> st->nr_matricol;
	cout << "Nume student:";
	cin.ignore(100, '\n');
	cin.getline(st->nume,14);
	cout << "Gen:";
	cin >> st->gen;
	cout << "Nota:";
	cin >> st->nota;
}
void WriteData(student*st)
{
	cout << "Nr matricol:"<<st->nr_matricol<<endl;
	cout << "Nume student:"<<st->nume<<endl;
	cout << "Gen:"<<st->gen<<endl;
	cout << "Nota:"<<st->nota<<endl;	
}