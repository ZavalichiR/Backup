#pragma once
#include "Persoana.h"
class Angajat :public Persoana{
private:
	int salarii;
	Data*dataAngajare;
public:
	Angajat(char*nume, char*prenume,Data *d, int salarii, Data*ang);
	Angajat(){ cout << "S-a apelat constructorul vid ANGAJAT" << endl; }
	~Angajat();
	Data *GetDataAngajare();
	int GetSalariu();
	Data getVarstaAngajare();
	void afisare(); 
	void Angajat::afisarePerioadaMuncita(Data &dataCurenta);
};