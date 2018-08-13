#include<iostream>
#include<Windows.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
//Hannoi

void muta(int n, int sursa, int destinatie, int intermediar)
{
	if (n == 1)
	{
		cout << sursa<<"-->" << destinatie << endl;
		return;
	}
	muta(n - 1, sursa, intermediar, destinatie);
	cout << sursa << "-->" << destinatie << endl;
	muta(n - 1, intermediar, destinatie, sursa);
}

//citire matrice recursiv
void citire(int A[][101], int n, int m, int i, int j)
{
	if (i <= n)
	{

		cin >> A[i][j];
		if (j<m) citire(A, n, m, i, j + 1);
		else citire(A, n, m, i + 1, 1);
	}
}

//afisare matrice recursiv
void afisare(int A[][101], int n, int m, int i, int j)
{
	if (i <= n)
	{
		cout << A[i][j] << " ";
		if (j<m) afisare(A, n, m, i, j + 1);
		else
		{
			cout << endl;
			afisare(A, n, m, i + 1, 1);
		}
	}
}
//eliminare cifre impare
int stergimp(int n)
{
	if (n == 0) return 0;
	else if (n % 2 == 1) return stergimp(n / 10);
	else return stergimp(n / 10) * 10 + n % 10;
}
//sirul lui fibonacci
int Fibonacci(int n)
{
	if (n<2)
		return n;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}
bool isPrime(int p, int i) 
{
	if (i == p) return 1;
	if (p%i == 0) return 0;
	return isPrime(p, i + 1);
}
void spiral(int n, int v[3][3])
{
	
	int i, k = 0, l = 0;
	while (k < n && l < n)
	{
		for (i = l; i < n; i++)
		{
			cout << v[k][i] << " ";
		}
		k++;
		cout << endl;
		for (i = k; i < n; i++)
		{
			cout << v[i][n - 1] << " ";
			cout << endl;

		}
		n--;
		if (l < n)
		{
			for (i = n - 1; i >= k; i--)
			{
				cout << v[i][l] << " ";
			}
			l++;
			cout << endl;

		}
	}
}
int main()
{
	
	/*int A[101][101], n, m;
	cout << "Linii: ";
	cin >> n;
	cout << "Coloane: ";
	cin >> m;
	citire(A, n, m, 1, 1);
	afisare(A, n, m, 1, 1);		

	int n1;
	printf("Numarul de discuri: ");
	cin >> n1;
	muta(n1, 1, 2, 3);

	int n2;
	cout << "Pentru Fibonacci :n= ";
	cin >> n2;
	cout << Fibonacci(n2);

	int v[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	spiral(3,v);*/
	 
	DWORD input = STD_INPUT_HANDLE;
	DWORD output = STD_OUTPUT_HANDLE;
	int color = FOREGROUND_BLUE;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE);
	cout << "text" << endl;
	color = FOREGROUND_GREEN;
	SetConsoleTextAttribute(GetStdHandle(output), color);
	cout << "text" << endl;
	SetConsoleTextAttribute(GetStdHandle(input), FOREGROUND_INTENSITY);
	system("pause");
	return 0;
}