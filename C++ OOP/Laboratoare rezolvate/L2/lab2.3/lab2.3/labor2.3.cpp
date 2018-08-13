#include <iostream>
#include <cstring>
#include "labor2.3.h"

using namespace std;

void catalog::sortare_alfabetica(void)
{
	int suntPerm = 1;
	while(suntPerm) 
	{
		suntPerm = 0;
		for(int i=0; i<nr_studenti-1; i++) 
		{
			if(strcmp(nume[i],nume[i+1]) > 0) {
				char *aux = nume[i];
				nume[i] = nume[i+1];
				nume[i+1] = aux;
				suntPerm = 1;
			}
		}
	}
}
void catalog::sortare_lungime(void)
{
	int suntPerm = 1;
	while(suntPerm) 
	{
		suntPerm = 0;
		for(int i=0; i<nr_studenti-1; i++) 
		{
			if(strlen(nume[i]) > strlen(nume[i+1])) 
			{
				char *aux = nume[i];
				nume[i] = nume[i+1];
				nume[i+1] = aux;
				suntPerm = 1;
			}
		}
	}
}

void catalog::Read(void)
{
	int i;
	char buffer[100];
	cout <<"Numar studenti:";
	cin >> nr_studenti;
	cin.ignore(100, '\n');
	for(i = 0;i < nr_studenti;++i)
	{
		cout<<"Nume student "<<i+1<<":";
		cin.getline(buffer,100);
		buffer[strlen(buffer)] = '\0';
		nume[i] = new char[strlen(buffer)];
		strcpy_s(nume[i],strlen(buffer)+1,buffer);
	}	
}

void catalog::Write(void)
{
	int i;
	cout <<"Numar studenti:"<<nr_studenti<<endl;
	for(i = 0;i < nr_studenti;++i)
	{
		cout<<"Nume student "<<i+1<<":"<<nume[i]<<endl;
	}
}