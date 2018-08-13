#include <iostream>
#include "Header.h"

using namespace std;

PUNCT::PUNCT()
{
	x = y = 0;
}
PUNCT::PUNCT(int x, int y)
{
	this->x = x;
	this->y = y;
}
PUNCT::~PUNCT() {}
int PUNCT::getX()
{
	return x;
}
void PUNCT::setX(int val)
{
	x = val;
}
int PUNCT::getY()
{
	return y;
}
void PUNCT::setY(int val)
{
	y = val;
}
bool PUNCT::operator==(const PUNCT& p)
{
	return x == p.x && y == p.y;
}
PUNCT& PUNCT::operator=(const PUNCT& p)
{
	x = p.x;
	y = p.y;
	return *this;
}

MULTIME::MULTIME()
{
	nrElem = 0;
	puncte = NULL;
}
MULTIME::~MULTIME()
{
	if (puncte)
	{
		delete[] puncte;
	}
}
MULTIME::MULTIME(const MULTIME& m)
{
	nrElem = m.nrElem;
	puncte = new PUNCT[nrElem];
	for (int i = 0; i<nrElem; ++i)
	{
		puncte[i] = m.puncte[i];
	}
}
int MULTIME::getNrElem()
{
	return nrElem;
}
PUNCT& MULTIME::operator[](int i)
{
	return puncte[i];
}
MULTIME& MULTIME::operator=(const MULTIME& m)
{
	if (this != &m)
	{
		if (puncte)
		{
			delete[] puncte;
		}
		nrElem = m.nrElem;
		puncte = new PUNCT[nrElem];
		for (int i = 0; i<nrElem; ++i)
		{
			puncte[i] = m.puncte[i];
		}
	}
	return *this;
}
void MULTIME::adauga(PUNCT p)
{
	PUNCT* aux = new PUNCT[++nrElem];
	for (int i = 0; i<nrElem - 1; ++i)
	{
		aux[i] = puncte[i];
	}
	aux[nrElem - 1] = p;
	if (puncte)
	{
		delete[] puncte;
	}
	puncte = aux;
}


MULTIME interclasareGrafice(MULTIME S, MULTIME T)
{
	MULTIME S_i;
	int L, j, k;

	L = 1; j = 1; k = 0;
	S_i.adauga(PUNCT(0, 0)); //(0, 0) apartine graficului rezultat

	while ((j<S.getNrElem() || L == 1) && (k<T.getNrElem() || L == 2))
	{
		if (L == 1)
		{
			if (j >= S.getNrElem() || S[j].getX()>T[k].getX())
			{
				if (S[j - 1].getY() >= T[k].getY())
				{
					++k;
				}
				else
				{
					L = 2;
				}
			}
			else if (S[j].getX()<T[k].getX())
			{
				S_i.adauga(S[j]);
				++j;
			}
			else if (S[j].getX() == T[k].getX())
			{
				if (S[j].getY() >= T[k].getY())
				{
					S_i.adauga(S[j]);
					++j;
					++k;
				}
				else
				{
					S_i.adauga(T[k]);
					L = 2;
					++j;
					++k;
				}
			}
		}
		else if (L == 2)
		{
			if (k >= T.getNrElem() || T[k].getX()>S[j].getX())
			{
				if (T[k - 1].getY() >= S[j].getY())
				{
					++j;
				}
				else
				{
					L = 1;
				}
			}
			else if (T[k].getX()<S[j].getX())
			{
				S_i.adauga(T[k]);
				++k;
			}
			else if (T[k].getX() == S[j].getX())
			{
				if (T[k].getY() >= S[j].getY())
				{
					S_i.adauga(T[k]);
					++j;
					++k;
				}
				else
				{
					S_i.adauga(S[j]);
					L = 1;
					++j;
					++k;
				}
			}
		}
	}

	if (j<S.getNrElem()) //s-a terminat Ti
	{
		for (int l = j; l<S.getNrElem(); ++l)
		{
			S_i.adauga(S[l]);
		}
	}

	if (k<T.getNrElem()) //s-a terminat Si
	{
		for (int l = k; l<T.getNrElem(); ++l)
		{
			S_i.adauga(T[l]);
		}
	}

	return S_i;
}

void rucsac(int M, int n, int* w, int* p, int*& x)
{
	x = new int[n]; //vectorul solutie

	MULTIME *S, *T; //tablouri de multimi de puncte
	S = new MULTIME[n + 1];
	T = new MULTIME[n + 1];

	//multimile initiale S0 si T0
	S[0].adauga(PUNCT(0, 0));
	T[0].adauga(PUNCT(w[0], p[0]));

	for (int i = 1; i <= n; ++i) //interclasare grafice
	{
		S[i] = interclasareGrafice(S[i - 1], T[i - 1]);
		for (int j = 0; j<S[i].getNrElem(); ++j)
		{
			T[i].adauga(PUNCT(S[i][j].getX() + w[i], S[i][j].getY() + p[i]));
		}
	}

	cout << endl << "Multimile S:" << endl;
	for (int i = n; i >= 0; i--)
	{
		cout << "S" << i << "={";
		for (int j = 0; j<S[i].getNrElem(); ++j)
		{
			if (j == S[i].getNrElem() - 1)
			{
				cout << "(" << S[i][j].getX() << ", " << S[i][j].getY() << ")}.";
			}
			else {
				cout << "(" << S[i][j].getX() << ", " << S[i][j].getY() << ");";
			}

		}

		cout << endl;
	}

	/*cout << endl << "Multimile T:" << endl;
	for (int i = 0; i<n; ++i)
	{
	for (int j = 0; j<T[i].getNrElem(); ++j)
	{
	cout << "(" << T[i][j].getX() << ", " << T[i][j].getY() << "); ";
	}
	cout << endl;
	}*/

	//determinare punct (Xj, Yj) cu Xj=max{Xi | (Xi, Yi) apartine lui Sn, Xi<=M}
	int xj, yj;
	xj = S[n][0].getX();
	yj = S[n][0].getY();
	for (int i = 1; i <= S[n].getNrElem(); ++i)
	{
		if (S[n][i].getX()>xj && S[n][i].getX() <= M)
		{
			xj = S[n][i].getX();
			yj = S[n][i].getY();
		}
	}
	cout << endl << "Punct maxim: (" << xj << ", " << yj << ")" << endl;

	//construire solutie
	for (int i = n - 1; i >= 0; --i)
	{
		bool apartineSi = false;
		for (int j = 0; j<S[i].getNrElem(); ++j)
		{
			if (S[i][j].getX() == xj && S[i][j].getY() == yj)
			{
				apartineSi = true;
			}
		}

		if (apartineSi)
		{
			x[i] = 0;
		}
		else
		{
			x[i] = 1;
			xj -= w[i];
			yj -= p[i];
		}
	}
}
