/*
 * main.c
 *
 *  Created on: Apr 16, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "pitici.h"
int main(void)
{
	FILE *in, *out; //declaram doua variabile de tip fisier, unul pentru citire si unul pentru scriere
	double G; //G reprezinta plata pentru o zi de lucru pentru fiecare pitic
	int n, m;
	double a[30][30], cumparaturi[30][30], p[30][30], pt[30][30], stocuri[30][30], plata[30][30];
	/*n este numarul piticilor
	 * m reprezinta numarul de rafturi din camara fiecarei case a fiecarui pitic
	 * a este matricea care va retine pentru fiecare pitic, stocurile pe care le are din fiecare produs
	 * p reprezinta vectorul in care se vor retine preturile pentru fiecare tip de aliment necesar piticilor
	 * "cumparaturi" este matricea in care sunt stocate comenzile date de pitici pentru staroste
	 * "stocuri" este matricea ce retine stocurile piticilor dupa ce starostele a facut cumparaturi
	 * "plata" reprezinta vectorul n dimensional in care se vor gasi sumele ce trebuiesc platite de pitici pentru ce au cumparat
	 */
	in=fopen("PITICI.IN", "r"); //deschidem fisierul de intrare "PITICI.IN"
	if (in==0) //daca nu s-a putut deschide fisierul
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"PITICI.IN\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //iesim din program pentru ca nu putem citi datele de intrare
	}
	out=fopen("PITICI.OUT", "w"); //deschidem fisierul de iesire "PITICI.OUT"
	if (out==0) //daca nu s-a putut deschide fisierul
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"PITICI.OUT\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //iesim din program pentru ca nu putem afisa rezultatele prelucrarilor
	}
	fscanf(in, "%lf", &G); //citim de pe prima linie numarul de galbeni pe care fiecare pitic il primeste zilnic
	printf("Plata pentru o zi de lucru: %lf\n", G);
	fscanf(in, "%d %d", &n, &m); //citim de pe a doua linie numarul de pitici si numarul de rafturi cu produse
	printf("Numarul de pitici: %d\tNumarul de rafturi: %d\n", n, m);
	citire(in, a, n, m); //citim de pe urmatoarele n linii stocurile celor m alimente
	printf("Stocurile:\n");
	afisare(stdout, a, n, m);
	citire(in, p, 1, m); //citim preturile celor m alimente necesare piticilor (vector de dimensiune 1 x m)
	printf("Preturile:\n");
	afisare(stdout, p, 1, m);
	citire(in, cumparaturi, n, m); //citim comenzile date de pitici pentru staroste
	printf("Comenzile: \n");
	afisare(stdout, cumparaturi, n, m);
	suma(a, cumparaturi, stocuri, n, m, n, m); //calculam stocurile piticilor dupa ce s-au facut cumparaturile (adunam ce aveau inainte cu cate produse au fost cumparate de staroste)
	fprintf(out, "Stocurile de alimente dupa ce starostele s-a intors de la magazin: \n");
	afisare(out, stocuri, n, m);
	transpunere(p, pt, 1, m); //transpunem vectorul de preturi, pentru a putea fi inmultit
	produs(cumparaturi, pt, plata, n, m, m, 1); //facem produsul dintre matricea cu stocurile comandate si vectorul de preturi, deci n x m * m x 1 => n x 1
	fprintf(out, "\nPreturile ce trebuiesc platite de pitici pentru cumparaturi:\n");
	afisare(out, plata, n, 1); //rezulta un vector n dimensional, in care se vor afla preturile ce trebuiesc platite de fiecare din cei n pitici
	fprintf(out, "\n");
	zile_munca(out, plata, n, G); //calculam si afisam numarul de zile de munca pentru fiecare pitic in parte
	fclose(in); //inchidem cele 2 fisiere
	fclose(out);
	return 0;
}
