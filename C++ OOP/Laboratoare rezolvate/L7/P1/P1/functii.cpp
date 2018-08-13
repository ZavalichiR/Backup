#include"Header.h"
Matrice::Matrice()
{
	nrL = 1;
	nrC = 1;
	elem = new int*[nrL];
	for (int i = 0; i < nrL; i++)
	{
		elem[i] = new int[nrC];
	}
	elem[0][0] = 0;
}

Matrice::Matrice(int nl, int nc)
{
	nrL = nl;
	nrC = nc;
	elem = new int*[nrL];
	for (int i = 0; i < nrL; i++)
	{
		elem[i] = new int[nrC];
		for (int j = 0; j < nrC; j++)
			elem[i][j] = 0;
	}
}

Matrice::Matrice(const Matrice &m)
{
	nrL = m.nrL;
	nrC = m.nrC;
	elem = new int*[nrL];
	for (int i = 0; i < nrL; i++)
	{
		elem[i] = new int[nrC];
	}
	for (int i = 0; i < nrL; i++)
	{
		for (int j = 0; j < nrC; ++j)
		{
			elem[i][j] = m.elem[i][j];
		}
	}
	
}

Matrice::~Matrice()
{
	for (int i = 0; i < nrL; ++i)
	{
		delete[] elem[i];
	}
	delete[] elem;
	nrL = 0;
	nrC = 0;
}

void Matrice::citire()
{
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j < nrC; ++j)
		{
			cout << "E["<<i<<"]["<<j<<"]: ";
			cin >> elem[i][j];
		}
	}
}
void Matrice::afisare()
{
	cout << endl; 
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j < nrC; ++j)
		{
			cout << elem[i][j] << " ";;
		}
		cout << endl;
	}
	
}

Matrice Matrice::operator*(Matrice m)
{
	Matrice rez(nrL,nrC);
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j <m.nrC; ++j)
		{
			for (int k = 0; k < nrC; ++k)
			{
				rez.elem[i][j] +=elem[i][k]*m.elem[k][j];
			}
		}
	}
	return rez;
}
Matrice Matrice::operator+(Matrice m)
{
	Matrice rez(nrL, nrC);
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j <nrC; ++j)
		{
			rez.elem[i][j] = elem[i][j] + m.elem[i][j];
		}
	}
	return rez;
}
Matrice Matrice::operator-(Matrice m)
{
	Matrice rez(nrL, nrC);
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j <nrC; ++j)
		{
			rez.elem[i][j] = elem[i][j] - m.elem[i][j];
		}
	}
	return rez;
}
Matrice Matrice::operator=(Matrice m)
{
	Matrice rez(m.nrL, m.nrC);
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j < nrC; ++j)
		{
			rez.elem[i][j] = m.elem[i][j];
		}
	}
	return m;
}
Matrice Matrice::operator+(int k)
{
	Matrice rez(nrL, nrC);
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j < nrC; ++j)
		{
			rez.elem[i][j] = elem[i][j] + k;
		}
	}
	return rez;
}
Matrice operator+(int a, Matrice b)
{
	Matrice rez(b.nrL, b.nrC);
	for (int i = 0; i < b.nrL; ++i)
	{
		for (int j = 0; j < b.nrC; ++j)
		{
			rez.elem[i][j] = b.elem[i][j] + a;
		}
	}
	return rez;
}
int Matrice::operator==(Matrice m)
{
	int i=0;
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j < nrC; ++j)
		{
			if (m.elem[i][j] == elem[i][j])
			{
				i = 1;
			}
			else
			{
				return 0;
			}
		}
	}
	return i;
}
Matrice Matrice:: operator~()
{
	Matrice rez(nrL, nrC);
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j <nrC; ++j)
		{
			rez.elem[i][j] = elem[j][i];
		}
	}

	return rez;
}
double Matrice::operator[](int x)
{

	int rez=0;
	for (int i = 0; i < x/nrC; ++i)
	{
		for (int j = 0; j <x%nrC; ++j)
		{
			rez = elem[i][j];
		}
	}
	return rez;
}
Matrice Matrice::operator++()
{
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j < nrC; ++j)
		{
			if (i == j)
			{
				elem[i][j] = elem[i][j] + 1;
			}
		}
	}

	return *this;
}
Matrice Matrice::operator++(int)
{
	Matrice temp = *this;
	for (int i = 0; i < nrL; ++i)
	{
		for (int j = 0; j < nrC; ++j)
		{
			if (i == j)
			{
				elem[i][j] = elem[i][j] + 1;
			}
		}
	}
	return temp;
}
