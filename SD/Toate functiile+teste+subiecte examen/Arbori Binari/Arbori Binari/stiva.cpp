#include"stiva.h"
void initS(stiva *&S)
{
	S = nullptr;
}
void push(stiva *&S, Nod* val)
{
	stiva *p = new stiva;
	if (p == 0)
		return;
	p->data = val;
	p->leg = S;
	S = p;
}
Nod *pop(stiva *&S)
{
	if (!S)
	{
		cout << "\nStiva este goala";
		return 0;
	}
	Nod *aux = S->data;
	stiva *p = S;
	S = S->leg;
	delete p;
	return aux;
}