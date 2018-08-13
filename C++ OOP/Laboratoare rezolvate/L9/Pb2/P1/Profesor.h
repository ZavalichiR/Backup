#include"Persoana.h"
#include"Angajat.h"
class Profesor :public Persoana, public Angajat
{
private:
	int m_iGradDirector;
public:
	Profesor(string nume, int varsta, double salariu, int gradDidactic) :Persoana(nume, varsta), Angajat(salariu), m_iGradDirector(gradDidactic){}

};