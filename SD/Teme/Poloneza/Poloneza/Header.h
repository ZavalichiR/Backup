#ifndef _POLONEZA_H
#define _POLONEZA_H



struct Stiva
{
	int data;
	Stiva *succ;
	//Stiva() : data(0), succ(nullptr) {}
};

void creare(Stiva *&S);
int isEmpty(Stiva *S);
void initS(Stiva *&S);
void push(Stiva *&S, int data);
int pop(Stiva *&S);
int top(Stiva *S);

void InfixataToPostafixata(char sir[]);
void EvaluarePostfixata(char sir[]);

#endif