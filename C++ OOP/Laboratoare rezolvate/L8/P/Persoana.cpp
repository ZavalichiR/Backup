
#include"Persoana.h"

Persoana::Persoana(char *nume, char *prenume, Data *dataNastere)
{
	cout << "S-a apelat constructorul cu parametri--PERSOAMA" << endl;
	this->nume = new char[strlen(nume) + 1];
	this->prenume = new char[strlen(prenume) + 1];
	strcpy_s(this->nume,strlen(nume)+1, nume);
	strcpy_s(this->prenume,strlen(prenume)+1, prenume);
	this->dataNastere =new Data(*dataNastere);
}
Persoana::Persoana()
{
	cout << "S-a apelat constructorul vid-PERSOANA" << endl;
	nume = nullptr;
	prenume = nullptr;
	dataNastere = nullptr;

}
Persoana::~Persoana() {
	cout << "S-a apelat destructorul--Persoana" << endl;
	delete[] nume;
	delete[] prenume;
	delete dataNastere;
}
char *Persoana::getNume(){
	return nume;
}
char *Persoana::getPrenume() {
	return prenume;
}
Data *Persoana::getDataNastere() {
	return dataNastere;
}
void Persoana::afisarePersoana() {
	cout << nume << " " << prenume
		<< "\nData de nastere: "
		<< dataNastere->getAn() << "."
		<< dataNastere->getLuna() << "."
		<< dataNastere->getZi();
}
void Persoana::afisare() {
	afisarePersoana();
	cout << endl;
}