#include <iostream>
#include <conio.h>
#include <string.h>
#include "globale.h"
#include"meniu.h"
using namespace std;

/****** Membri clasa ElementMeniu ******/

ElementMeniu::ElementMeniu(char *nume) {
	this->nume = new char[strlen(nume) + 1];
	strcpy(this->nume, nume);
	this->parinte = NULL;
}

//afiseaza titlul mai putin caracterele de sfarsit, 
//pentru a putea fi utilizata in afisarea propriului titlu cat si a fiilor.
void ElementMeniu::afisareIncompletaTitlu() {
	if (parinte != NULL) {
		parinte->afisareIncompletaTitlu();
		cout << " -> " << nume;
	}
	else {
		cout << nume;
	}
}

void ElementMeniu::afisareTitlu() {
	afisareIncompletaTitlu();
	cout << ":" << endl << endl;
}

char *ElementMeniu::getNume() {
	return this->nume;
}

ElementMeniu::~ElementMeniu() {
	cout << "Stergere element: " << nume << endl;
	delete[] nume;
}

/****** Membri clasa Operatie ******/

Operatie::Operatie(char *nume)
: ElementMeniu(nume) {}

void Operatie::executa() {
	clrscr();
	this->afisareTitlu();
	this->execOperatie();
}

/****** Membri clasa Meniu ******/

Meniu::Meniu(char *nume) : ElementMeniu(nume) {
	this->elemente = new ElementMeniu*[nrMaxElemente];
	this->nrElemente = 0;
}

//va dealoca memoria pentru toate elementele, eventual recursiv.
Meniu::~Meniu() {
	for (int i = 0; i<nrElemente; i++) {
		delete elemente[i];
	}
	delete[] elemente;
}

void Meniu::adaugaElement(ElementMeniu *element) {
	nrElemente++;
	elemente[nrElemente - 1] = element;
	element->parinte = this;
}

void Meniu::afisare() {
	for (int i = 0; i < this->nrElemente; i++) {
		cout << "\t" << i + 1 << " - " << elemente[i]->getNume();
		cout << endl << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
	cout << "\t" << "ESC sau 0 - Iesire" << endl << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
}

//returneaza indicele elementului activat, sau -1 pentru iesire
int Meniu::citireComanda() {
	while (1) {
		char ch;

		cout << "Introduceti comanda:";
		ch = _getch();
		cout << endl;
		if (ch > '0' && (ch - '0') <= this->nrElemente) {
			//element meniu
			int comanda = ch - '1';// pt '1' va fi elementul 0

			return comanda;
		}
		else  if (ch == '0' || ch == 0x1B) {
			//0 sau ESC - iesire din meniu
			return -1;
		}
		else {
			//tasta invalida
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
			cout << "Tasta invalida: " << ch
				<< " Tastele valide sunt '0' - '" << nrElemente << "'"
				<< endl << endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
		}
	}
}

void Meniu::executa() {
	for (;;) {
		int comanda;

		clrscr();
		afisareTitlu();
		afisare();
		comanda = citireComanda();
		if (comanda >= 0 && comanda < nrElemente) {
			elemente[comanda]->executa();
		}
		else {
			//probabil iesirea - -1
			return;
		}
	}
}
