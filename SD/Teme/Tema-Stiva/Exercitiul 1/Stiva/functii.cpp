#include"Header.h"

void InitS(Stiva &S)
{
	S.sp = -1;
}

int EmptyS(Stiva S)
{

	if (S.sp == -1)
	{
		return 1;
	}
	else
		return 0;
}

char Pop(Stiva &S)
{
	if (EmptyS(S)!=1)
	{
		return (S.vect[S.sp--]);
	}
	else
	{
		cout << "\nStiva este vida." << endl;
		return 0;
	}
}

void Push(Stiva &S, char val)
{
	if (S.sp < dim - 1)
	{
		S.vect[++S.sp] = val;
	}
	else
	{
		cout << "\nStiva este plina." << endl;

	}
}

char Top(Stiva S)
{
	if (EmptyS(S) == 1)
	{
		return 0;
	}
	else
	{
		return S.vect[S.sp];

	}
}

int Verificare(char vect[])
{
	Stiva S;
	int i;
	int ok = 1;
	InitS(S);


	for (i = 0; i < strlen(vect); ++i)
	{

		if (vect[i] == '{' || vect[i] == '[' || vect[i] == '<' || vect[i] == '(')
		{
			Push(S, vect[i]);
		}

		if (vect[i] == '}' || vect[i] == ']' || vect[i] == '>' || vect[i] == ')')
		{
			char aux;
			if (vect[i] == '}')
				aux = '{';
			if (vect[i] == ']')
				aux = '[';
			if (vect[i] == '>')
				aux = '<';
			if (vect[i] == ')')
				aux = '(';

			if (aux != Pop(S))
			{
				return 0;
			}

		}
	}

	if (EmptyS(S) == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}

	return 1;

}