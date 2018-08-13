#pragma once
#include<iostream>
using namespace std;

template <typename T>
class Multime
{
	T*      elem;
	int      nrElem;
public:
	Multime(int n)
	{
		nrElem = n;
		elem = new T[n];
	}
	Multime()
	{
		elem = nullptr;
	}
	~Multime()
	{
		if (elem)
			delete[]      elem;
	}
	Multime(const Multime &p)
	{
		this->nrElem = p.nrElem;
		this->elem = new T[this->nrElem];
		for (int i = 0; i < this->nrElem; ++i)
		{
			//this->elem[i] = new T;
			this->elem[i] = p.elem[i];
		}
	}
	T operator!()
	{
		T max = elem[0];
		for (int i = 0; i < nrElem; i++)
		{
			if (elem[i] > max)
				max = elem[i];
		}
		
		return max;
	}
	Multime operator+(Multime m)
	{
		Multime tmp(m.nrElem);
		for (int i = 0; i < m.nrElem; ++i)
		{
			tmp[i] = this->elem[i] + m.elem[i];
		}
		return tmp;
	}
	//supraincarcarea operatorului de indexare: 
	T& operator[](int index)
	{
		return      elem[index];
	}
	void afisare()
	{
		for (int i = 0; i < nrElem; i++)
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
	int getNrElem()
	{
		return nrElem;
	}
	T getElem()
	{
		return elem;
	}
};
template <typename T>
T Aduna(T a,T b)
{
	T sum;
	sum = a + b;
	return sum;
}
