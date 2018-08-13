#include"Header.h"

Stiva::Stiva()
{
	n = -1;
	dim = 20;
	v = new int[dim];
}

Stiva::~Stiva()
{
	if (v)
	{
		delete[] v;
		v = NULL;
	}
}



void Stiva::push(int val)
{
	if (v == nullptr)
		v = new int[dim];

	if (n < dim)
	{
		v[++n] = val;
	}
	else
		exit(EXIT_FAILURE);
}

int Stiva::pop()
{
	if (n == -1)
		cout << "Stiva goala. " << endl;
	else
		return v[n--];
}

void citireV(int v[], int nr)
{
	for (int i = 0; i < nr; ++i)
	{
		cout << "v [ " << i << " ]= ";
		cin >> v[i];
	}
}
void afisareV(int v[], int nr)
{
	for (int i = 0; i < nr-1; ++i)
	{
		cout << v[i] << ", ";
	}
	cout << v[nr-1] << ". ";
	cout << endl;
}

void inversare(int v[], int nr)
{
	Stiva S;
	for (int i = 0; i < nr; ++i)
	{
		S.push(v[i]);
	}
	for (int i = 0; i < nr; i++)
	{
		v[i] = S.pop();
	}
}