#include <iostream>
#define nmax 20 //nr max de noduri (chei)

using namespace std;

//structura arborelui optimal
struct OBST
{
	char KEY;
	OBST *left, *right;
};

int C[nmax][nmax]; //matrice cost

int W[nmax][nmax]; //matrice ponderi

int R[nmax][nmax]; //radacinile subarborilor optimali. Va contine
				   //indecsii cheilor din vectorul KEYS,
				   //corespunzator radacinilor subarborilor

int q[nmax]; //frecventa de cautare intre chei=esec in ce
			 //priveste cautarea

int p[nmax]; //frecventa de cautare a cheilor

int nr_keys; //numarul de noduri (chei)

char KEYS[nmax]; 

//Functia pentru calculul matricelor W, C si R
void Matrix()
{
	int x, min;
	int i, j, k, h, m;

	//construiesc matricea de ponderi W
	for (i = 0; i <= nr_keys; i++)
	{
		for (j = i; j <= nr_keys; j++)
		{
			W[i][j] = 0;
			for (k = i + 1; k <= j; k++)
			{
				W[i][j] += p[k];
			}
			for (k = i; k <= j; k++)
			{
				W[i][j] += q[k];
			}
		}
	}

	//Construesc matricea cost C si matricea R
	for (i = 0; i <= nr_keys; i++)
		//relatia pentru diagonala principala din C;
		C[i][i] = W[i][i];

	for (i = 0; i <= nr_keys - 1; i++)
	{
		j = i + 1;
		//relatia pentru a doua diagonală din C (deasupra celei cunoscute)
		C[i][j] = W[i][j] + C[i][i] + C[j][j];

		//relatia pentru diagonala matricei R
		R[i][j] = j;

	}
	//completez matricele C si R
	for (h = 2; h <= nr_keys; h++)
		for (i = 0; i <= nr_keys - h; i++)
		{
			j = i + h; m = R[i][j - 1]; min = C[i][m - 1] + C[m][j];
			for (k = m + 1; k <= R[i + 1][j]; k++)
			{ //caut minim si index pentru minim (m)
				x = C[i][k - 1] + C[k][j];
				if (x < min)
				{
					m = k;
					min = x;
				}
			}
			C[i][j] = W[i][j] + min;
			R[i][j] = m; //indexul lui k pentru care s-a obtinut
						 //minimum se pune in R
		}
	//afisez W
	cout << "\nMatricea W\n";
	for (i = 0; i <= nr_keys; i++)
	{
		for (j = 0; j <= nr_keys; j++)
		{
			cout << W[i][j] << "\t";
		}
		cout << endl;
	}

	//Afisez C	
	cout << "\n Matricea cost" << endl;
	for (i = 0; i <= nr_keys; i++)
	{
		for (j = 0; j <= nr_keys; j++)
		{
			cout << C[i][j] << "\t";
		}
		cout << endl;
	}

	//Afisez R
	cout << "\n Matricea R:\n";
	for (i = 0; i <= nr_keys; i++)
	{
		for (j = 0; j <= nr_keys; j++)
		{
			cout << R[i][j] << "\t";
		}
		cout << endl;
	}
}

//Construiesc BST optimal
OBST *Build_OBST(int i, int j)
{
	OBST *p;
	if (i == j) p = NULL;
	else
	{
		p = new OBST; //se aloca memorie
		p->KEY = KEYS[R[i][j]]; //pun valoarea cheii
		p->left = Build_OBST(i, R[i][j] - 1); //subarbore sting
		p->right = Build_OBST(R[i][j], j); //subarbore drept
	}
	return p;
}

void AfisareInordine(OBST *t)
{
	if (t)
	{
		AfisareInordine(t->left);
		cout << (int)t->KEY << " ";
		AfisareInordine(t->right);
	}
}

void AfisareParanteze(OBST *t)
{
	cout << (int)t->KEY;
	if (t->left || t->right)
	{
		cout << "(";
		if (t->left)
		{
			AfisareParanteze(t->left);
		}
		else
		{
			cout << "-";
		}
		cout << ",";
		if (t->right)
		{
			AfisareParanteze(t->right);
		}
		else
		{
			cout << "-";
		}
		cout << ")";
	}
}

int main()
{
	int i, j;
	nr_keys = 6;

	KEYS[0] = 0;
	KEYS[1] = 3;
	KEYS[2] = 7;
	KEYS[3] = 10;
	KEYS[4] = 15;
	KEYS[5] = 20;
	KEYS[6] = 25;

	p[0] = 0;
	p[1] = 10;
	p[2] = 3;
	p[3] = 9;
	p[4] = 2;
	p[5] = 100;
	p[6] = 10;

	q[0] = 5;
	q[1] = 6;
	q[2] = 4;
	q[3] = 4;
	q[4] = 3;
	q[5] = 8;
	q[6] = 0;
	
	Matrix();
	OBST *arbore = Build_OBST(0, nr_keys);
	cout << endl;
	AfisareInordine(arbore);
	cout << endl;
	AfisareParanteze(arbore);

	return 0;
}
