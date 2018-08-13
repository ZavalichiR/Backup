#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Header.h"
using namespace std;

int main(void)
{
	student *vst;
	int n,i;

	cout<<"Nr studenti: ";
	cin>>n;

	vst=new student[n];
	for(i=0;i<n;i++)
	{
		vst[i].Read();
	}
	for (i=0;i<n;++i)
	{
		vst[i].Write();
	}

	_getch();
	return 0;
}