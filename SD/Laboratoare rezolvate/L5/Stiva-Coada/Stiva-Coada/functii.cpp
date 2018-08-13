#include"Header.h"

void initS(stiva *&S)
{
	S = nullptr;
}
void creareS(stiva *&S)
{
	S = 0;
}
void push(stiva *&S, int val)
{
		stiva *p = new stiva;
		if (p == 0)
		{
			return;
		}
		p->data = val;
		p->leg = S;
		S = p;

}
int pop(stiva *&S)
{
	if (S == 0)
	{
		cout << "\nStiva este goala-POP" << endl;
		EXIT_FAILURE;
	}

	int rezultat = S->data;
	stiva *p = S;
	S = S->leg;
	delete p;

	return rezultat;
}
int top(stiva *S)
{
	if (S == 0)
	{
		cout << "\nStiva este goala-TOP" << endl;
		EXIT_FAILURE;
	}
	return S->data;
}

//--------------Coada----------------------//

void initC(coada *&C)
{
	C = new coada;
	C->head = 0;
	C->tail = 0;
}
void put(coada *&C,int val)
{
	elm *p = new elm;
	p->data = val;
	p->succ = 0;

	if (C->head == 0)
	{
		C->tail = p;
		C->head = C->tail;
		
	}
	else
	{
		C->tail->succ = p;
		C->tail = p;
	}
}

int get(coada *&C,bool &flag)
{
	if (C->head == 0)
	{
		cout << "\nCoada este goala" << endl;
		flag = 0;
		return 0;
	}
	int rezultat = C->head->data;
	elm *p = C->head;
	C->head = C->head->succ;
	delete p;
	flag = 1;
	return rezultat;

}
bool palindrom(char *sir)
{
	stiva *S;
	coada *C;
	bool f;
	bool ok = 1;
	initS(S);
	creareS(S);
	initC(C);
	for (unsigned int i = 0; i < strlen(sir); ++i)
	{
		push(S, (int)sir[i]);
		put(C, (int)sir[i]);
	}
	for (unsigned int j = 0; j < strlen(sir); ++j)
	{
		int r1 = pop(S);
		int r2 = get(C, f);
		if (r1 != r2)
			ok = 0;
	}

	return ok;
}