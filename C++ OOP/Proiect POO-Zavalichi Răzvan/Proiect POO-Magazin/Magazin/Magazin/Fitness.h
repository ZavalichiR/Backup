#pragma once
#include<iomanip>
class Garantie{
private:
	int ani;
	int luni;
public:
	Garantie() {}
	Garantie(int ani, int luni);
	~Garantie();
	int getAni();
	int getLuni(); 
};

class Fitness{
private:
	char *tip;
	char *cod;
	double pret;
	Garantie *garantie;
protected:
	void afisareFitness(); 
	void afisareFitnessF(); 
public:
	Fitness(){}
	Fitness(char *tip, double pret, char *cod, Garantie *garantie);
	virtual ~Fitness();
	Garantie *getGarantie();
	char *getTip();
	char *getCod(); 
	double getPret(); 
	virtual void afisare(); 
	virtual void afisareF(); 
};
Fitness *citesteFitness(char *c);  
Fitness *citesteFitness(); 


char *citesteSirF(); 
void deschideF(); 
void inchideF();
