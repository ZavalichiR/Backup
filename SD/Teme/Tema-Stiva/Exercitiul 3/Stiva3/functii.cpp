#include"Header.h"

int Stiva::getN()
{
	return n;
}

Stiva::Stiva()
{
	n = -1;
	dim = 20;
	v = new char[dim];
}

Stiva::~Stiva()
{
	if (v)
	{
		delete[] v;
		v = NULL;
	}
}



void Stiva::push(char val)
{
	if (v == nullptr)
		v = new char[dim];

	if (n < dim)
	{
		v[++n] = val;
	}
	else
		exit(EXIT_FAILURE);
}

char Stiva::pop()
{
	if (n == -1)
		cout << "Stiva goala. " << endl;
	else
		return v[n--];
}

int verificare(char *sir)
{
	Stiva S;
	int i, j;
	//cout << strlen(sir) / 2 << endl;
	//cout << strlen(sir) << endl;
	for ( i = 0; i < strlen(sir)/ 2; ++i)
	{
		S.push(sir[i]);
	}
	if (strlen(sir) % 2 != 0)
	{
		i = i + 1;
	}
	for (j = i; j < strlen(sir); ++j)
	{
	
		if (S.pop()!=sir[j] )
		{
			return 0;
		}
		else
		{
			return 1;
		}

	}
	

	return 1;
}
