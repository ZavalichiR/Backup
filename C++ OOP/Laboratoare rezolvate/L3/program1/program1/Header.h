#ifndef _PROGRAM1_
#define _PROGRAM1_
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;


typedef struct _Student{

private:
	char *nume;
	int nota;
public:
	void SetNota(int n);
	int GetNota();
	char *GetNume();
	void SetNume(char sir[]);
	void citire();
	void afisare();
	void ElibMemorie1();

}Student;

typedef int(*PFnComparare)(Student a, Student b);

typedef struct _Grupa {
	void citire();
	void afisare();
	void ElibMemorie();
	char *numeGrupa;
	int nrStud;
	Student *studentii;
	PFnComparare comparator;
	void bSort(void);
}Grupa;

typedef struct _Catalog{

	void citire();
	void afisare();
	int nrGrupe;
	Grupa *grupele;
	void elibMemorie2();
	void sortare(void);
	void setComparator(PFnComparare comparator);

}Catalog;

int comparNumeAlfabetic(Student a, Student b);
int comparNoteDescrescator(Student a, Student b);
int comparNumeDupaLungimeCrescator(Student a, Student b);



#endif
