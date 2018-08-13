#include<iostream>
#include"Header.h"
using namespace std;

void creare(Stiva *&S)
{
	S = nullptr;

}

int isEmpty(Stiva *S)
{
	int r;
	if (S == 0)
		return r=-1;
	else
		return r=1;
}

void initS(Stiva *&S)
{
	S = nullptr;
}

void push(Stiva *&S, int val)
{
	Stiva *p = new Stiva;
	if (p == 0)
	{
		return;
	}
	p->data = val;
	p->succ = S;
	S = p;

}

int top(Stiva *S)
{

	if (S)
	{
		return S->data;
	}

	else
	{
		cout << "\nTOP-Stiva este goala" << endl;
		return 0;
	}
}

int pop(Stiva *&S)
{
	if (S == 0)
	{
		cout << "\nTOP-Stiva este goala" << endl;
		return 0;
	}
	else
	{
		int top = S->data;
		Stiva *p = S;
		S = S->succ;
		delete p;
		return top;
	}
}

void EvaluarePostfixata(char sir[])
{
	Stiva *S;
	int a1, a2;
	initS(S);
	creare(S);
	int i = 0;;
	while (sir[i])
	{
		if (sir[i] >= '0' && sir[i] <= '9')
		{
			push(S, sir[i] - '0');
		}
		else if (sir[i] == '+')
		{
			a1 = pop(S);
			a2 = pop(S);
			push(S, a1 + a2);
		}
		else if (sir[i] == '-')
		{
			a1 = pop(S);
			a2 = pop(S);
			push(S, a2 - a1);
		}
		else if (sir[i] == '*')
		{
			a1 = pop(S);
			a2 = pop(S);
			push(S, a2 * a1);
		}
		else if (sir[i] == '/')
		{
			a1 = pop(S);
			a2 = pop(S);
			push(S, a2 / a1);
		}

		i++;
	}
	cout << "\nRezultat: ";
	cout << pop(S) << endl;
}


void InfixataToPostafixata(char sir[])
{
	char sir2[40];
	int i = 0, k = 0;
	Stiva *S;
	initS(S);
	creare(S);
	while (sir[i]!='\0')
	{

		if (sir[i] >= '0' && sir[i] <= '9')
		{
			sir2[k] = sir[i];
			k++;
		}

		else if (sir[i] == '(')
		{
			push(S, sir[i]);
		}

		else if (sir[i] == ')')
		{
			while (top(S) != '(')
			{
				sir2[k] = pop(S);
				k++;
			}
			pop(S);
		}

		else if (sir[i] == '+' || sir[i] == '-')
		{
			
				while (S && top(S) != '(' && sir[i] != 0)
				{
					sir2[k] = pop(S);
					k++;
				}
			push(S, sir[i]);
		}

		else if (sir[i] == '*' || sir[i] == '/')
		{
				while (S && top(S) != '(' && sir[i] != 0 && top(S) != '+' && top(S) != '-')
				{
					sir2[k] = pop(S);
					k++;
				}
			push(S, sir[i]);
		}

		i++;
	}
	int r = isEmpty(S);
	while (S)
	{
		sir2[k] = pop(S);
		k++;
	}
	sir2[k] = '\0';
	cout << "\nForma postfixata este: " << sir2 << endl;

	EvaluarePostfixata(sir2);

}