#include<iostream>
#include "globale.h"
#include "meniu.h"
#include "operatiiSimple.h"
#include "lista.h"
#include "Fitness.h"
#include<Windows.h>
using namespace std;


int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 27);
	
	Meniu *meniu = new Meniu("Fitness Store "); 

	Lista *echipament = new Lista(); 
	Lista *mingi = new Lista(); 
	Lista *greutati = new Lista(); 
	Lista *gantere = new Lista(); 
	Lista *haltere = new Lista(); 
	Lista *accesorii = new Lista(); 

	citireListe(echipament,mingi, greutati, gantere, haltere, accesorii);

	Meniu *submeniuEchipament = new Meniu("Echipament de protectie");
	meniu->adaugaElement(submeniuEchipament);
	submeniuEchipament->adaugaElement(new OpAdaugareProtectie("Adaugare produs", echipament));
	submeniuEchipament->adaugaElement(new OpStergereInLista("Stergere produs", echipament));
	submeniuEchipament->adaugaElement(new OpAfisareLista1("Afisare produse", echipament));
	submeniuEchipament->adaugaElement(new OpCautareDupaCod("Cauta produse dupa cod", echipament));

	Meniu *submeniuForta = new Meniu("Echipament pentru forta"); 
	meniu->adaugaElement(submeniuForta);

	Meniu *submeniuMingi = new Meniu("Mingi de fitness"); 
	submeniuForta->adaugaElement(submeniuMingi); 
	submeniuMingi->adaugaElement(new OpAdaugareMingeFitness("Adaugare produse", mingi));
	submeniuMingi->adaugaElement(new OpStergereInLista("Stergere produse", mingi));
	submeniuMingi->adaugaElement(new OpAfisareLista2("Afisare produsee", mingi));
	submeniuMingi->adaugaElement(new OpCautareDupaCod("Cauta produse dupa cod", mingi));


	Meniu *submeniuGreutati = new Meniu("Greutati"); 
	submeniuForta->adaugaElement(submeniuGreutati); 

	Meniu *submeniuGantere = new Meniu("Gantere"); 
	submeniuGreutati->adaugaElement(submeniuGantere); 
	submeniuGantere->adaugaElement(new OpAdaugareGantere("Adaugare produse", gantere));
	submeniuGantere->adaugaElement(new OpStergereInLista("Stergere produse", gantere));
	submeniuGantere->adaugaElement(new OpAfisareLista3("Afisare produse", gantere));
	submeniuGantere->adaugaElement(new OpCautareDupaCod("Cauta produse dupa cod", gantere));

	Meniu *submeniuHaltere = new Meniu("Haltere");
	submeniuGreutati->adaugaElement(submeniuHaltere);
	submeniuHaltere->adaugaElement(new OpAdaugareHaltere("Adaugare produse", haltere));
	submeniuHaltere->adaugaElement(new OpStergereInLista("Stergere produse", haltere));
	submeniuHaltere->adaugaElement(new OpAfisareLista4("Afisare produse", haltere));
	submeniuHaltere->adaugaElement(new OpCautareDupaCod("Cauta produse dupa cod", haltere));

	submeniuGreutati->adaugaElement(new OpAfisareListeGreutati("Afisare produse", gantere, haltere));

	submeniuForta->adaugaElement(new OpAfisareListeForta("Afisare produse", mingi, greutati, gantere, haltere));

	Meniu *submeniuAccesorii = new Meniu("Accesorii"); 
	meniu->adaugaElement(submeniuAccesorii);
	submeniuAccesorii->adaugaElement(new OpAdaugareProdusNou("Adaugare produse", accesorii));
	submeniuAccesorii->adaugaElement(new OpStergereInLista("Stergere produse", accesorii));
	submeniuAccesorii->adaugaElement(new OpAfisareLista("Afisare produse", accesorii));
	submeniuAccesorii->adaugaElement(new OpCautareDupaCod("Cauta produse dupa cod", accesorii));


	meniu->adaugaElement(new OpAfisareListeProduse("Afisare produse din Fitness Store", echipament, mingi, greutati, gantere, haltere, accesorii));

	meniu->adaugaElement(new ElementDespre("Despre program")); 

	meniu->executa(); 

	scrieListe(echipament, mingi, greutati, gantere, haltere, accesorii);

	delete echipament;
	delete accesorii;
	delete mingi;
	delete greutati;
	delete gantere;
	delete haltere;
	delete meniu;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 26);
	clrscr();
	mesaj();

	pauza();

	return 0;
}
