#pragma once
#include"Fitness.h"

class Greutati :public Fitness{ 
private:
	double greutate;
protected:
	void afisareGreutati();
	void afisareGreutatiF();
public:
	Greutati(){}
	Greutati(Fitness *fit,double greutate);
	~Greutati();
	double getGreutate(); 
	void afisare(); 
	void afisareF(); 
};
Fitness *citesteGreutati(char *c); 
Fitness *citesteGreutatiF(); 