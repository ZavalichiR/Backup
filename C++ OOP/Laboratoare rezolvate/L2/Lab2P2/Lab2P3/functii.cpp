#include<iostream>
#include<string.h>
#include"header.h"
#include "conio.h"

using namespace std;

void catalog::citire()
{
	char buffer[100];
	char **vsiruri = (char**)calloc(n, sizeof(char*));
	cin.ignore(100, '\n');
	for(int i=0; i<n; i++)
	{
		int len;
		cin.getline(buffer, 100);
		len = strlen(buffer);
		vsiruri[i]=(char*)calloc(len+1,sizeof(char));
		strcpy_s(vsiruri[i],len+1,buffer);
	}
}

void catalog::afisare() {
	cout << "Sirurile sortate sunt:" << endl;
	for(int i=0; i<n; i++) {
		cout << vsiruri[i] << endl;
	}
}
void catalog::dealocareVSiruri()
{
	for (int i=0; i<n; i++)
	{
		delete[]vsiruri[i]; 
	}
	delete[]vsiruri;
}

//modificare

void catalog::sortare1()
{
	int suntPerm = 1;
	while(suntPerm)
	{
		suntPerm = 0;
		for (int i=0; i<n-1; i++)
		{
			if (strlen(vsiruri[i])>strlen(vsiruri[i+1]))
			{
					char *aux = vsiruri[i];
					vsiruri[i] = vsiruri[i+1];
					vsiruri[i+1] = aux;
					suntPerm = 1;
			}
		}
	}
}

void catalog::sortare2()
{
	int suntPerm = 1;
	while(suntPerm)
	{
		suntPerm = 0;
		for (int i=0; i<n-1; i++)
		{
			if(strcmp(vsiruri[i],vsiruri[i+1]) > 0)
			{
					char *aux = vsiruri[i];
					vsiruri[i] = vsiruri[i+1];
					vsiruri[i+1] = aux;
					suntPerm = 1;
			}
		}
	}
}


