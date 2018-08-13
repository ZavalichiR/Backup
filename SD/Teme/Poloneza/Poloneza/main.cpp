#include<iostream>
#include"Header.h"
using namespace std; 

int main()
{
	Stiva *S = 0;
	int n, i = 1, elm;
	char infixata[40];
	char operanzi[40]; //0-9
	/*
	cout << "\nNumarul de elemente din stiva" << endl;
	cin >> n;
	creare(S);
	initS(S);
	while (n)
	{

		cout << "Elementul " << i << ":";
		cin >> elm;
		push(S, elm);
		++i;
		n--;
	}
	cout<<top(S)<<endl;
	cout<<pop(S)<<endl;
	cout << pop(S) << endl;
	cout << pop(S) << endl;
	cout << pop(S) << endl;
	*/

	cout << "\nPrecizati forma infixata: ";
	cin.getline(infixata, 41);
	InfixataToPostafixata(infixata);


	
	return 0;
}