#include<iostream>
#include"Header.h"
using namespace std;

int C[nmax][nmax]; //matrice cost 
int W[nmax][nmax]; //matrice ponderi 
int R[nmax][nmax]; //radacinile subarborilor optimali. Va contine 
//int q[nmax]; //frecventa de cautare intre chei=esec in ce 
//int p[nmax]; //frecventa de cautare a cheilor
int nr_keys = 6; //numarul de noduri (chei)

//indecsii cheilor din vectorul KEYS, 

//corespunzator radacinilor subarborilor 

//priveste cautarea
char KEYS[nmax] = { 0, 3, 7, 10, 15, 20, 25 };
int p[nmax] = { 0,10, 3, 9, 2, 0, 10 };
int q[nmax] = { 5,6, 4, 4, 3, 8, 0 };
void Matrix()
{

	int x, min; int i, j, k, h, m;

	//construiesc matricea de ponderi W 

	for (i = 0; i <= nr_keys; i++)
	{
		W[i][i] = q[i];
		for (j = i + 1; j<nr_keys; j++)
			W[i][j] = W[i][j - 1] + p[j] + q[j];
	}

	//Construesc matricea cost C si matricea R 

	for (i = 0; i <= nr_keys; i++)
	{
		C[i][i] = W[i][i];
	}
		for (i = 0; i<nr_keys - 1; i++)
		{
			j = i + 1;
		C[i][j] = C[i][i] + C[j][j] + W[i][j];

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

	}

	//afisez W 

	cout << "\nMatricea W\n";
	Afisare(W);

	//Afisez C

	cout << "\n Matricea cost" << endl;
	Afisare(C);

	//Afisez R 

	cout << "\n Matricea R:\n";
	Afisare(R);
}

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

void Afisare(int A[nmax][nmax])
{
	int i, j;
	for (i = 0; i < nr_keys; i++)
	{
		for (j = 0; j < nr_keys; j++)
		{
			printf(" %-4d ", A[i][j]);
			//cout << " "<<A[i][j]<<" ";
		}
		cout << endl;
	}
	
}

void Citire()
{
	/*cout << "Introduceti numarul total de chei:" << endl;
	cin >> nr_keys;
	cout << "Introduceti elementele vectorului KEYS:" << endl;

	for (int i = 0; i < nr_keys; i++)
	{
		cin >> KEYS[i];
	}*/

	cout << "introduceti ponderile p" << endl;  //citirea unui vector
	for (int j = 0; j < nr_keys; j++)
	{
		cin >> p[j];
	}

	cout << "introduceti ponderile q:" << endl;
	for (int k = 0; k < nr_keys; k++)
	{
		cin >> q[k];
	}

}
void afisareTree(OBST *rad,int nivel)
{
	for (int i = 0; i < nivel; ++i)
		cout << "\t";
	if (rad == 0)
		cout<<"_" << endl;
	else
	{
		cout << (int)rad->KEY << endl;
		afisareTree(rad->left, nivel + 1);
		afisareTree(rad->right, nivel + 1);
	}
}