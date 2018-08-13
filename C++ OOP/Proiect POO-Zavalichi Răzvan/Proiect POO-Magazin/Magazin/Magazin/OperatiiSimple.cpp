#include <iostream>
using namespace std;
#include<assert.h>
#include<string.h>
#include "globale.h"
#include "operatiiSimple.h"
#include<Windows.h>
using namespace std;



ElementDespre::ElementDespre(char *nume) :Operatie(nume) {}

void ElementDespre::execOperatie()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 30);
	cout << "\tProgramul simuleaza gestionarea produselor dintr-un magazin fitness. \n"
		<< "\tMagazinul are drept produse: echipamente de protectie,greutati(mingi fitness, gantere, haltere) si diferite accesorii." << endl;
	cout << "\tExista posibilitatea de a cauta produse dupa cod, de sterge anumite produse dupa indexul din magazin si de afisare a produselor pe categorii" << endl;
	cout << "\tIn magazin se pot adauga, sterge sau extrage diferite produse folosind tastele 0-9" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	
	pauza();
}

OpAdaugareInLista::OpAdaugareInLista(char *nume, Lista *&lista) :Operatie(nume)
{
	this->lista = lista;
}

int verificareCod(char *c, char *ch, Lista *lista)
{
	int ok, nr;
	char *aux;
	aux = new char[strlen(c) + 1];
	assert(aux);
	strcpy(aux, c);
	strcpy(aux, aux + 3);
	if (strncmp(c, ch, 3) == 0)
		ok = 0; 
	else return 1;
	if (strlen(c) == 7)
		ok = 0; 
	else return 1;
	if (isdigit(aux[0]))
		nr = atoi(aux); 
	if (nr<1000 || nr>9999) return 1; 
	Element *cap = lista->getElement(); 
	while (cap != NULL)
	{
		if (strcmp(cap->getFitness()->getCod(), c) == 0)
		{
			ok = 1;
			cap = NULL;
		}
		else
			cap = cap->getUrmator();
	}
	if (ok == 1)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 28);
		cout << "Acest cod este deja asociat altui produs." << endl << "Rintroduceti codul: ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	}
	

	return ok;
}


OpAdaugareProdusNou::OpAdaugareProdusNou(char *nume, Lista *&lista) :OpAdaugareInLista(nume, lista) {}
void OpAdaugareProdusNou::execOperatie()
{
	char c[10];
	this->fit = new Fitness(); 
	assert(this->fit);
	do{
		cout << "Introduceti codul (Caracterele ACS urmate de un numar din 4 cifre): ";
		cin >> c;
	} while (verificareCod(c, "ACS", this->lista) == 1);
	this->fit = citesteFitness(c); 
	(*this->lista) += this->fit;

	cout << "\n\n";
	printf("%c", 254);
	cout << "ACCESORII/DIFERITE PRODUSE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 215);
	cout << "     Tip              Pret           Cod         Garantie\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare(); 
	pauza();
}


OpAdaugareProtectie::OpAdaugareProtectie(char *nume, Lista *&lista) :OpAdaugareInLista(nume, lista) {}
void OpAdaugareProtectie::execOperatie()
{
	char c[10];
	this->fit = new Protectie(); 
	assert(this->fit);
	do{
		cout << "Introduceti codul (Caracterele PRT urmate de un numar din 4 cifre): ";
		cin >> c;
	} while (verificareCod(c, "PRT", this->lista) == 1);
	this->fit = citesteProtectie(c); 
	(*this->lista) += this->fit; 

	cout << "\n\n";
	printf("%c", 254);
	cout << "ECIPAMENT PENTRU PROTECTIE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs           Material         Tip               Pret           Cod         Garantie\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare(); 
	pauza();
}


OpAdaugareMingeFitness::OpAdaugareMingeFitness(char *nume, Lista *&lista) :OpAdaugareInLista(nume, lista) {}
void OpAdaugareMingeFitness::execOperatie()
{
	char c[10];
	this->fit = new MingeFitness(); 
	assert(this->fit);
	do{
		cout << "Introduceti codul (Caracterele MGF urmatade un numar din 4 cifre): ";
		cin >> c;
	} while (verificareCod(c, "MGF", this->lista) == 1);
	this->fit = citesteMinge(c);
	(*lista) += fit;

	cout << "\n\n";
	printf("%c", 254);
	cout << "MINGI DE FITNESS" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs          Greutate             Tip            Pret           Cod         Garantie\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare();
	pauza();
}


//OpAdaugareGreutati::OpAdaugareGreutati(char *nume, Lista *&lista) :OpAdaugareInLista(nume, lista) {}
//void OpAdaugareGreutati::execOperatie()
//{
//	char c[10];
//	this->fit = new Greutati();
//	assert(this->fit);
//	do{
//		cout << "Introduceti codul (Caracterele GRT urmate de un numar din 4 cifre): ";
//		cin >> c;
//	} while (verificareCod(c, "GRT", this->lista) == 1);
//	this->fit = citesteGreutati(c); 
//	(*lista) += fit; 
//	lista->afisare();
//	pauza();
//}


OpAdaugareGantere::OpAdaugareGantere(char *nume, Lista *&lista) :OpAdaugareInLista(nume, lista) {}
void OpAdaugareGantere::execOperatie()
{
	char c[10];
	this->fit = new Gantere(); 
	assert(this->fit);
	do{
		cout << "Introduceti codul (Caracterele GNT urmate de un numar din 4 cifre): ";
		cin >> c;
	} while (verificareCod(c, "GNT", this->lista) == 1);
	this->fit = citesteGantere(c); 
	(*lista) += fit; 

	cout << "\n\n";
	printf("%c", 254);
	printf("%c", 254);
	cout << "GANTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs        Numar    Greutate         Tip            Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                 Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare(); 
	pauza();
}


OpAdaugareHaltere::OpAdaugareHaltere(char *nume, Lista *&lista) :OpAdaugareInLista(nume, lista) {}
void OpAdaugareHaltere::execOperatie()
{
	char c[10];
	this->fit = new Haltere(); 
	assert(this->fit);
	do{
		cout << "Introduceti codul (Caracterele HLT urmate de un numar din 4 cifre): ";
		cin >> c;
	} while (verificareCod(c, "HLT", this->lista) == 1);
	this->fit = citesteHaltere(c); 
	(*lista) += fit; 

	cout << "\n\n";
	printf("%c", 254);
	cout << " HALTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs     Dimensiune        Numar    Greutate        Tip             Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                                Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare(); 
	pauza();
}


OpAfisareLista::OpAfisareLista(char *nume, Lista *lista) : Operatie(nume)
{
	this->lista = lista;
}
void OpAfisareLista::execOperatie()
{
	cout << "\n\n";
	printf("%c", 254);
	cout << "ACCESORII/DIFERITE PRODUSE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "     Tip              Pret           Cod         Garantie\n"<< endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare();
	pauza();
}

OpAfisareLista1::OpAfisareLista1(char *nume, Lista *lista) : Operatie(nume)
{
	this->lista = lista;
}
void OpAfisareLista1::execOperatie()
{
	cout << "\n\n";
	printf("%c", 254);
	cout << "ECIPAMENT PENTRU PROTECTIE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs           Material         Tip               Pret           Cod         Garantie\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare();
	pauza();
}

OpAfisareLista2::OpAfisareLista2(char *nume, Lista *lista) : Operatie(nume)
{
	this->lista = lista;
}
void OpAfisareLista2::execOperatie()
{
	cout << "\n\n";
	printf("%c", 254);
	cout << "MINGI DE FITNESS" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs          Greutate             Tip            Pret           Cod         Garantie\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare();
	pauza();
}

OpAfisareLista3::OpAfisareLista3(char *nume, Lista *lista) : Operatie(nume)
{
	this->lista = lista;
}
void OpAfisareLista3::execOperatie()
{
	cout << "\n\n";
	printf("%c", 254);
	printf("%c", 254);
	cout << "GANTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs        Numar    Greutate         Tip            Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                 Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare();
	pauza();
}

OpAfisareLista4::OpAfisareLista4(char *nume, Lista *lista) : Operatie(nume)
{
	this->lista = lista;
}
void OpAfisareLista4::execOperatie()
{
	cout << "\n\n";
	printf("%c", 254);
	cout << " HALTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs     Dimensiune        Numar    Greutate        Tip             Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                                Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	lista->afisare();
	pauza();
}

OpAfisareListeProduse::OpAfisareListeProduse(char *nume, Lista *lista1, Lista*lista2, Lista *lista3, Lista *lista4, Lista *lista5, Lista *lista6) :Operatie(nume)
{
	this->lista1 = lista1;
	this->lista2 = lista2;
	this->lista3 = lista3;
	this->lista4 = lista4;
	this->lista5 = lista5;
	this->lista6 = lista6;
}
void OpAfisareListeProduse::execOperatie()
{
	int nr = 0;
	cout << "In magazin exista " << lista1->getNrEl() + lista2->getNrEl() + lista3->getNrEl() + lista4->getNrEl() + lista5->getNrEl() + lista6->getNrEl() << " produse" << endl;

	cout << "\n\n";
	printf("%c", 254);
	cout << "ECIPAMENT PENTRU PROTECTIE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs           Material         Tip               Pret           Cod         Garantie\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	nr = lista1->afisare2(nr);

	cout << "\n\n";
	printf("%c", 254);
	cout << "MINGI DE FITNESS" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs          Greutate             Tip            Pret           Cod         Garantie\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	nr = lista2->afisare2(nr);

	cout << "\n\n";
	printf("%c", 254);
	cout << "GANTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs        Numar    Greutate         Tip            Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                 Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	nr = lista3->afisare2(nr);
	
	nr = lista4->afisare2(nr);

	cout << "\n\n";
	printf("%c", 254);
	cout << " HALTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs     Dimensiune        Numar    Greutate        Tip             Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                                Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	nr = lista5->afisare2(nr);

	cout << "\n\n";
	printf("%c", 254);
	cout << "ACCESORII/DIFERITE PRODUSE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "     Tip              Pret           Cod         Garantie\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	nr = lista6->afisare2(nr);
	pauza();
}

OpAfisareListeForta::OpAfisareListeForta(char *nume, Lista *lista1, Lista*lista2, Lista *lista3, Lista *lista4) :Operatie(nume)
{
	this->lista1 = lista1;
	this->lista2 = lista2;
	this->lista3 = lista3;
	this->lista4 = lista4;
}
void OpAfisareListeForta::execOperatie()
{
	int nr = 0;
	cout << "In magazin exista " << lista1->getNrEl() + lista2->getNrEl() + lista3->getNrEl() + lista4->getNrEl() << " echipamente pentru forta:" << endl;
	
	cout << "\n\n";
	printf("%c", 254);
	cout << "MINGI DE FITNESS" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs          Greutate             Tip            Pret           Cod         Garantie\n" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	nr = lista1->afisare2(nr);
	
	nr = lista2->afisare2(nr);

	cout << "\n\n";
	printf("%c", 254);
	cout << "GANTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs        Numar    Greutate         Tip            Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                 Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	nr = lista3->afisare2(nr);
	
	cout << "\n\n";
	printf("%c", 254);
	cout << " HALTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs     Dimensiune        Numar    Greutate        Tip             Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                                Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	
	nr = lista4->afisare2(nr);
	pauza();
}


OpAfisareListeGreutati::OpAfisareListeGreutati(char *nume, Lista *lista1, Lista*lista2) :Operatie(nume)
{
	this->lista1 = lista1;
	this->lista2 = lista2;
}
void OpAfisareListeGreutati::execOperatie()
{
	int nr = 0;
	cout << "In magazin exista " << lista1->getNrEl() + lista2->getNrEl() << " greutati" << endl;

	cout << "\n\n";
	printf("%c", 254);
	cout << "GANTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs        Numar    Greutate         Tip            Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                 Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	nr = lista1->afisare2(nr);

	cout << "\n\n";
	printf("%c", 254);
	cout << " HALTERE" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "    Produs     Dimensiune        Numar    Greutate        Tip             Pret           Cod         Garantie" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 169);
	cout << "                                Discuri                                                                      " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	nr = lista2->afisare2(nr);
	pauza();
}


OpCautareDupaCod::OpCautareDupaCod(char *nume, Lista *lista) :Operatie(nume)
{
	this->lista = lista;
}

void OpCautareDupaCod::execOperatie()
{
	int ok = 0;
	char c[10];
	cout << "Introduceti un cod: ";
	cin >> c;
	Element *cap = this->lista->getElement(); 
	if (cap == 0)
		cout << "Lista este vida !" << endl;
	else
	{
		while (cap != NULL)
		{
			if (strcmp(cap->getFitness()->getCod(), c) == 0)
			{
				cap->getFitness()->afisare(); 
				ok = 1; 
				cap = NULL;
			}
			else
				cap = cap->getUrmator(); 
		}
		if (ok == 0) cout << "Produsul cu codul dat nu exista in lista" << endl; 
	}
	pauza();
}


OpStergereInLista::OpStergereInLista(char *nume, Lista *&lista) :Operatie(nume)
{
	this->lista = lista;
}

void OpStergereInLista::execOperatie()
{
	lista->afisare(); 
	lista->sterge();
	cout << "\n\nDupa stergere: \n";
	lista->afisare(); 
	pauza();
}