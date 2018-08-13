#pragma once
#include"Fitness.h"
#include"Greutati.h"

class Gantere :public Greutati{ 
private:
	int nrDiscuri;
protected:
	void afisareGantere(); 
	void afisareGantereF(); 
public:
	Gantere(){}
	Gantere(Fitness *fit,double greutate, int nrDiscuri);
	~Gantere();
	int getNrDiscuri(); 
	void afisare(); 
	void afisareF(); 
};

Fitness *citesteGantere(char *c); 
Fitness *citesteGantereF(); 