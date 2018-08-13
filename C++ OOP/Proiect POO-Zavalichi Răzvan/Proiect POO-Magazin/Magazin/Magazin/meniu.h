#ifndef _meniu_
#define _meniu_

//Un element de meniu in general. Poate fi atat o operatie cat si un meniu.
class ElementMeniu {
private:
	char *nume;
	ElementMeniu *parinte;

protected:
	ElementMeniu(char *nume);
	virtual ~ElementMeniu();
	void afisareIncompletaTitlu();//afiseaza titlul mai putin caracterele 
	//de sfarsit, pentru a putea fi utilizata in afisarea propriului titlu
	//cat si a fiilor.
	void afisareTitlu(); // va apela afisareIncompletaTitlu() + va tipari 
	//caracterele de sfarsit	

public:
	char *getNume();

	//va contine logica executata la activarea acestui element
	virtual void executa() = 0;

	//este necesar pentru a putea seta parintele din clasa Meniu, si doar 
	//de acolo.
	friend class Meniu;
};

//un element de meniu care efectueaza o operatie. 
//Reprezinta o frunza in arborele meniului
class Operatie : public ElementMeniu {
protected:
	Operatie(char *nume);

	//operatia specifica acestui element
	virtual void execOperatie() = 0;

public:
	//intreaga logica a elementului - afisare titlu + operatie
	void executa();
};

//Reprezinta un element meniu care la randul sau este meniu. 
//Poate fi atat meniul principal cat si un submeniu
class Meniu : public ElementMeniu {
private:
	static const int nrMaxElemente = 9;
	int nrElemente;

	//Meniul este stapan peste memoria fiilor sai.
	//Astfel, la dealocare va dealoca si memoria fiilor.
	ElementMeniu **elemente;

	//afiseaza meniul la consola
	void afisare();

	//asteapta apasarea unei taste, si activeaza elementul respectiv 
	//de meniu returneaza indicele fiului, sau -1 pentru iesire
	int citireComanda();

public:
	Meniu(char *nume);

	//va dealoca fii sai, eventual recursiv.
	~Meniu();

	void adaugaElement(ElementMeniu *element);
	void executa();
};

#endif