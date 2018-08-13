#include"Header.h"
struct stiva{
	Nod2 *data;
	stiva *leg;
};
void initS(stiva *&S);
void push(stiva *&S, Nod2 *val);
Nod2 *pop(stiva *&S);
