#pragma once
#include"Fitness.h"

class Protectie : public Fitness{
private:
	char *denumire;
	char *material;
public:
	Protectie(){}
	Protectie(Fitness *fit, char *denumire, char *material);
	~Protectie();
	char *getMaterial();
	char *getDenumire();
	void afisare(); 
	void afisareF(); 
};
Fitness *citesteProtectie(char *c); 
Fitness *citesteProtectieF(); 