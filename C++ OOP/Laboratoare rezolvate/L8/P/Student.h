#pragma once
#include "Persoana.h"
class Student :public Persoana{
private:
	int grupa;
public:
	Student(char*nume, char*prenume, Data*d, int grupa);
	Student();
	~Student();
	void afisare();
	int GetGrupa();
};