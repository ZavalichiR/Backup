#include "Student.h"
Student::Student(char*nume, char*prenume, Data*d, int grupa) :Persoana(nume, prenume, d)
{
	cout << "S-a apelat constructorul cu parametri Student" << endl;
	this->grupa = grupa;
}
Student::Student()
{
	cout << "S-a apelat constructorul vid- STUDENT" << endl;
}
Student::~Student()
{
	cout << "S-a apelat destructorul Student" << endl;
}
void Student::afisare()
{
	cout << "Grupa: " << grupa << endl;
	Persoana::afisare();
	cout << endl;
}
int Student::GetGrupa()
{
	return grupa;
}