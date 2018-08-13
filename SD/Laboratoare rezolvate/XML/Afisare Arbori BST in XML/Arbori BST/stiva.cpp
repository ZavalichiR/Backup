#include"stiva.h"
void initS(stiva *&S)
{
	S = nullptr;
}
void push(stiva *&S, Nod2 *val)
{
	stiva *p = new stiva;
	p->data = val;
	p->leg = S;
	S = p;
}
Nod2 *pop(stiva *&S)
{
	if (S)
	{
		Nod2 *aux = S->data;
		stiva *p = S;
		S = S->leg;
		delete p;
		return aux;
	}
	else
	{
		cout << "\nStiva este goala\n" << endl;
		return 0;
	}
}