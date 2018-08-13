#pragma once
#include"Fitness.h"

class MingeFitness : public Fitness{ 
private:
	double greutate;
public:
	MingeFitness(){}
	MingeFitness(Fitness *fit, double greutate);
	~MingeFitness();
	double getGreutate(); 
	void afisare(); 
	void afisareF();
};
Fitness *citesteMinge(char *c); 
Fitness *citesteMingeF(); 
