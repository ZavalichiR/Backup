/*
* main.cpp
*
*  Created on: Feb 17, 2017
*      Author: zava
*/

#include"header.h"

int main()
{
	//cout<<"Linii=Coloane: ";
	//int n;
	int a[100][100];
	int n;
	cout << "Dimensiunea matricei: ";
	cin >> n;
	/*a[0][0]=1;
	a[0][1]=2;
	a[0][2]=3;

	a[1][0]=1;
	a[1][1]=1;
	a[1][2]=1;

	a[2][0]=1;
	a[2][1]=2;
	a[2][2]=3;
	*/
	citire(a, n);

	afisare(a, n);

	rotire(a, n);

	return 0;
}


