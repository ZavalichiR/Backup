#include<iostream>
#include<string.h>
#include"header.h"
#include "conio.h"

using namespace std;

char **citireVSiruri(int n)
{
	char buffer[100];
	char **vsiruri = (char**)calloc(n, sizeof(char*));
	cin.ignore(100, '\n');
	for(int i=0; i<n; i++)
	{
		int len;
		cout << "Sir " << i + 1 << " :  ";

		cin.getline(buffer, 100);
		len = strlen(buffer);
		vsiruri[i]=(char*)calloc(len+1,sizeof(char));
		strcpy_s(vsiruri[i],len+1,buffer);
	}
	return vsiruri;
}

void afisareVSiruri(char **vsiruri, int n) {

	for(int i=0; i<n; i++) {
		cout << vsiruri[i] << endl;
	}
}
void dealocareVSiruri(char **vsiruri, int n)
{
	for (int i=0; i<n; i++)
	{
		free(vsiruri[i]);
	}
	free(vsiruri);
}


void sortareVSiruriLungime(char ** vsiruri, int n)
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

void sortareVSiruriAlfabetic(char ** vsiruri, int n)
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

catalog creareCatalog(int n)
{
	catalog c;
	c.nr=n;
	c.sortare1=&sortareVSiruriAlfabetic;
	c.sortare2=&sortareVSiruriLungime;
	c.citire=&citireVSiruri;
	return c;
}




	