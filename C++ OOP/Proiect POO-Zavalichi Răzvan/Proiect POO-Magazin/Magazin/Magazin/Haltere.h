#pragma once
#include"Fitness.h"
#include"Gantere.h"
class Haltere :public Gantere{ 
private:
	double dimensiune;
public:
	Haltere(){}
	Haltere(Fitness *fit, double greutate, int nrDiscuri, double dimensiune);
	~Haltere();
	double getDimensiune(); 
	void afisare();  
	void afisareF(); 
};
Fitness *citesteHaltere(char *c); 
Fitness *citesteHaltereF(); 