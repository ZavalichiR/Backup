/*
 * main.c
 *
 *  Created on: Jun 9, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "header.h"
int main(void)
{
	FILE *fisier_citire=0; //declaram o variabila de tip fisier (folosind un tip de data FILE = FISIER), folosita pentru a citi din fisierul de intrare
	FILE *fisier_scriere=0; //declaram o variabila de tip fisier (folosind un tip de data FILE = FISIER), folosita pentru a scrie in fisierul de iesire

	fisier_citire=fopen("date.txt", "r"); //deschidem fisierul de intrare "date.txt"
	//functia fopen() a primit 2 parametri:
	//primul reprezinta numele fisierului de pe hard disk (in acest caz, este "date.txt")
	//al doilea parametru este tipul fisierului care se deschide: "r" = "read" = fisier de citire
	//rezultatul functiei fopen(), stocat in variabila fisier_citire este un pointer la adresa fisierului deschis sau 0 daca nu s-a putut deschide (eroare)
	if (fisier_citire==0) //daca fopen() a returnat 0, adica nu s-a putut deschide fisierul (din cauza unei erori)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului date.txt.\n"); //afisam pe ecran o eroare in acest sens, folosind fprintf() cu parametrul stderr
		//stderr = standard error output (adica output-ul implicit pentru afisarea erorilor, in acest caz fiind chiar ecranul)
		exit(EXIT_FAILURE); //apelam functia exit() care iese din program (nu mai are sens sa continuam programul daca nu am putut citi datele)
	}

	fisier_scriere=fopen("rezultate.txt", "w"); //deschidem fisierul de iesire "rezultate.txt"
	//functia fopen() a primit 2 parametri:
	//primul reprezinta numele fisierului de pe hard disk (in acest caz, este "rezultate.txt")
	//al doilea parametru este tipul fisierului care se deschide: "w" = "write" = fisier de scriere
	//rezultatul functiei fopen(), stocat in variabila fisier_scriere este un pointer la adresa fisierului deschis sau 0 daca nu s-a putut deschide (eroare)
	if (fisier_scriere==0) //daca fopen() a returnat 0, adica nu s-a putut deschide fisierul (din cauza unei erori)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului rezultate.txt.\n"); //afisam pe ecran o eroare in acest sens, folosind fprintf() cu parametrul stderr
		//stderr = standard error output (adica output-ul implicit pentru afisarea erorilor, in acest caz fiind chiar ecranul)
		exit(EXIT_FAILURE); //apelam functia exit() care iese din program (nu mai are sens sa continuam programul daca nu avem unde scrie rezultatele calculate
	}

	double a[11][11], b[11][11]; //declaram cele 2 matrici (a va fi cea citita de la tastatura, iar b din fisier)
	int nrlinii_a, nrcoloane_a, nrlinii_b, nrcoloane_b; //dimensiunile matricilor
	double mediePrimaLinie; //variabila in care se va retine media elementelor de pe prima linie

	//citim dimensiunile matricei a
	printf("Introduceti numarul de linii: ");
	scanf("%d", &nrlinii_a);
	printf("Introduceti numarul de coloane: ");
	scanf("%d", &nrcoloane_a);
	CitesteMatrice(a, nrlinii_a, nrcoloane_a); //citim matricea a de la tastatura apeland functia creata la subpunctul a)

	printf("\nMatricea citita este:\n");
	AfiseazaMatrice(a, nrlinii_a, nrcoloane_a); //afisam matricea citita pe ecran apeland functia de afisare creata la subpunctul b)

	mediePrimaLinie=MedieElementePrimaLinieMatrice(a, nrlinii_a, nrcoloane_a); //calculam media elementelor de pe prima linie folosind functia creata la subpunctul c)
	printf("Media elementelor de pe prima linie este: %lf\n", mediePrimaLinie); //afisam aceasta medie pe ecran

	fscanf(fisier_citire, "%d", &nrlinii_b); //citim din fisierul de citire numarul de linii ale matricei b
	fscanf(fisier_citire, "%d", &nrcoloane_b); //citim din fisierul de citire numarul de coloane ale matricei b
	//citim elementele matricei b din fisierul de citire "date.txt", apeland functia creata la subpunctul d)
	//primul parametrul este variabila de tip fisier care a fost folosita pentru a se deschide fisierul "date.txt"
	CitesteMatriceFisier(fisier_citire, b, nrlinii_b, nrcoloane_b);

	AfisareRezultateFinale(fisier_scriere, a, nrlinii_a, nrcoloane_a, b, nrlinii_b, nrcoloane_b); //apelam functia de afisare a rezultatelor finale creata la subpunctul e)

	//inchidem fisierele deschise, apeland functia fclose() (FILE close) care primeste ca parametru variabila de tip fisier care a fost folosita pentru deschiderea fisierului respectiv de pe disc
	fclose(fisier_citire);
	fclose(fisier_scriere);
	return 0;
}
