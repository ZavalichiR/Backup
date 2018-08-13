// P2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<conio.h>
#include<iostream>
using namespace std;
typedef int TipO;


struct Element {
 TipO data; // informatia utila
 Element* leg; // legatura
 }; 
void InserareFata(Element *&lista,TipO datanou)
{
	Element *p=new Element;
	p->data=datanou;
	p->leg=lista;
	lista=p;

}

void InserareCoada(Element *&lista,TipO datanou)
{
	Element *q,*p=new Element;
	p->data=datanou;
	p->leg=0;
	if(lista==0)
	{
		lista=p;
	}
	else{
	q=lista;
	while (q->leg)
	{
		q=q->leg;
	}
	q->leg=p;
	}

}

void InserarePozitie(Element *&lista, TipO datanou) //neterminat
{
	
}

Element *cautare(Element *lista, TipO datanou)  //neterminat
{
	Element *p=lista;
	Element *q=new Element;
	while (p->leg)
	{
		p=p->leg;
		if(p->data=datanou)
		{
			q=p;
		}
		else
		{
			return 0;
		}

	}

	return q;
}

void StergeElement(Element *&lista, TipO datanou) //neterminat
{
	Element *p=lista;
	Element *q=new Element;

	if(p)
	{

	}
	p=q->leg;
	q->leg=p->leg;
	
	

}

void afisareCapCoada(Element *lista)
{

	Element *p=lista;

	while(p)
	{
		cout<<p->data<<" ";
		p=p->leg;

	}

}

void afisareCoadaCap(Element *lista)
{

	Element *p=lista;

	if (p)
	{
		afisareCoadaCap(p->leg);
		cout<<p->data<<" ";
		

	}


}


int _tmain(int argc, _TCHAR* argv[])
{
	Element *cap=0;

	/*
	InserareFata(cap, 1);
	InserareFata(cap, 2);
	InserareFata(cap, 3);

	afisareCapCoada(cap);
	cout<<endl;
	afisareCoadaCap(cap);
	cout<<endl;
	*/

	InserareCoada(cap,1);
	InserareCoada(cap,2);
	InserareCoada(cap,3);
	InserareCoada(cap,4);
	InserareCoada(cap,5);

	cout<<endl;
	afisareCapCoada(cap);
	cout<<endl;
	afisareCoadaCap(cap);



	_getch();
	return 0;
}

