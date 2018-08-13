#include <iostream>
#include <conio.h>
#include "Header.h"
using namespace std;
void ReadData(student*st)
{
	cout<<"\n Nr.matr=";
	cin>>st->nrMatr;

	cin.ignore(100,'\n');   //scapa de enter
	cout<<"\n Nume: ";
	cin.getline(st->nume, 100);

	cout<<"\n Gen: ";
	cin>>st->gen;

	cout<<"\n Nota: ";
	cin>>st->nota;

}

void WriteData(student*st)
{
	cout<<"Numar matricol: ";
	cout<<st->nrMatr<<"\n " ;
	cout<<"Nume: ";
	cout<<st->nume<<"\n ";
	cout<<"Gen: ";
	cout<<st->gen<<"\n ";
	cout<<"Nota: ";
	cout<<st->nota<<"\n"<<endl;


}
