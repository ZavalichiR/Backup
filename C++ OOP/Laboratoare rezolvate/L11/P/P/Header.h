#pragma once
#include<iostream>
using namespace std;

template <typename T>
class MyVector
{
	T*      elem;
	int      nrElem;
public:
	MyVector(int      n)
	{
		nrElem = n;
		elem = new T[n];
	}
	~MyVector()
	{
		if (elem)
			delete[]      elem;
	}
	//supraincarcarea operatorului de indexare: 
	T& operator[](int index)
	{
		return      elem[index];
	}
	void afisare()
	{
		for (int i = 0; i < nrElem;i++)
		{
			cout << elem[i] << " ";
		}
	}
	void citire()
	{
		for (int i = 0; i < nrElem; ++i)
		{
			cout << "Element " << i + 1 << ":";
			cin >> elem[i];
		}
	}
	void sortare()
	{
		int ok = 1;
		while (ok)
		{
			ok = 0;
			for (int i = 0; i < nrElem - 1; ++i)
			{
				if (elem[i] > elem[i + 1])
				{
					T aux;
					aux = elem[i];
					elem[i] = elem[i + 1];
					elem[i + 1] = aux;
					ok = 1;
				}
			}
		}
	}
};

