#include"Header.h"
struct elm{
	Nod *data;
	elm *succ;
};
struct coada{
	elm*head, *tail;
};
void initC(coada *&C);
void put(coada *&C, Nod*val);
Nod *get(coada *&C);
