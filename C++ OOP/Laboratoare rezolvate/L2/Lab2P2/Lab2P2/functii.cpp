#include <iostream>
#include <conio.h>
#include"Header.h"
using namespace std;
 
void student::Read()
{
	cout<<"\n Nr.matr=";
	cin>>nrMatr;

	cin.ignore(100,'\n');   //scapa de enter
	cout<<"\n Nume: ";
	cin.getline(nume, 100);

	cout<<"\n Gen: ";
	cin>>gen;

	cout<<"\n Nota: ";
	cin>>nota;

}

void student::Write()
{
	cout<<"Numar matricol: ";
	cout<<nrMatr<<"\n " ;
	cout<<"Nume: ";
	cout<<nume<<"\n ";
	cout<<"Gen: ";
	cout<<gen<<"\n ";
	cout<<"Nota: ";
	cout<<nota<<"\n"<<endl;


}
