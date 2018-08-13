#include"Header.h"

void Student::citire()
{
	cout << "Nota: ";
	cin >> nota;
	cout << "Nume: ";
	nume = new char;
	cin.ignore(100, '\n');
	cin.getline(nume, 100);
}

void Student::afisare()
{
	cout << "Nume: " << nume << "  " << "Nota: " << nota;
}

void CitireVect(int v[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout <<"Element ["<<i<< "] :";
		cin >> v[i];
	}
}

void AfisareVect(int v[], int n)
{
	int i;
	cout << "Vectorul: " << endl;
	for (i = 0; i < n-1; ++i)
	{
		cout << v[i] << ",";
		
	}
	cout << v[n-1] << "." << endl;
}

void BSort(int v[], int b)
{
	int ok = 1;
	//int j = 0;
	while (ok)
	{
		ok = 0;
		//j = j + 1;
		for (int i = 1; i <b-1; ++i)
		{
			if (v[i] > v[i + 1])
			{
				int aux = v[i];
				v[i] = v[i + 1];
				v[i + 1] = aux;
				ok = 1;
			}
		}
	}
}

float factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	return n*factorial(n - 1);
}

float factorial2(int n)
{
	int i;
	float p=1;
	for (i = 0; i < n; ++i)
	{
		p = p*i;
	}

	return p;
}

int cmmdc(int n, int m)
{
	if (!n)
	{
		return m;
	}

	return cmmdc(n, m%n);
}

float putere(float x, int n)
{
	if (n == 0)
		return 1;
	return x*putere(x, n - 1);
}
