#pragma once
#include"Data.h"
class Persoana {
private:
	char *nume, *prenume;
	Data *dataNastere;
protected:
	void afisarePersoana();
public:
	Persoana();//nu am nevoie de el
	Persoana(char *nume, char *prenume, Data*dataNastere);
	~Persoana();
	//Intrebare.....
	char *getNume();
	char *getPrenume();
	Data *getDataNastere();
	void afisare();
};
