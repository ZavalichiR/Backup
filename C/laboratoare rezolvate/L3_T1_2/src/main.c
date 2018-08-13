/*
 * main.c
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include "trioda.h"
int main(void)
{
	FILE *in; //declaram variabila de tip fisier
	unsigned int nr_comp;
	double preturi[50], preturi_scumpite1[50], preturi_scumpite2[50], valStoc1[50], valStoc2[50], valTotalaStocuri[50], scumpire[50], valScumpire, valTotalaMarfa;
	int stoc_trioda1[50], stoc_trioda2[50], total_stocuri[50];
	in=fopen("trioda.dat", "r"); //deschidem fisierul pentru citire "trioda.dat"; al doilea parametru al functiei fopen() este, asadar, "r" ("read")
	if (in==0) //daca fopen() returneaza 0, adica deschiderea fisierului a esuat
	{
		fprintf(stderr, "Eroare la deschiderea fisierului \"inventar.dat\"!\n"); //afisam eroare
		exit(EXIT_FAILURE); //iesim din program, deoarece nu putem citi datele raportului de inventar
	}
	fscanf(in, "%u", &nr_comp); //citim de pe prima linie a fisierului numarul de componente electronice
	citireVector_reali(in, preturi, nr_comp); //citim de pe a doua linie preturile/bucata pentru fiecare componenta
	citireVector_intregi(in, stoc_trioda1, nr_comp); //citim de pe a treia linie stocurile magazinului Trioda1
	citireVector_intregi(in, stoc_trioda2, nr_comp); //citim de pe a patra linie stocurile magazinului Trioda2
	printf("Introduceti valoarea procentuala a scumpirii: ");
	scanf("%lf", &valScumpire);//citim valoarea in procente a scumpirii
	//cream raportul inventar afisand rezultatele pe ecran
	printf("Raport inventar pentru firma Trioda.\n\n\n");
	//afisam datele citite din fisier
	printf("Firma Trioda comercializeaza %d tipuri de componente electronice.\n", nr_comp);
	printf("Pret/bucata pentru fiecare componenta electronica = ");
	afisareVector_reali(preturi, nr_comp);
	printf("\tStocuri magazin Trioda1 = ");
	afisareVector_intregi(stoc_trioda1, nr_comp);
	printf("\tStocuri magazin Trioda2 = ");
	afisareVector_intregi(stoc_trioda2, nr_comp);
	//urmeaza datele prelucrate
	printf("\t\tTotal stocuri firma = ");
	sumaVectori(stoc_trioda1, stoc_trioda2, total_stocuri, nr_comp); //calculam stocurile totale, sumand cei 2 vectori de stocuri
	afisareVector_intregi(total_stocuri, nr_comp); //afisam stocurile totale
	printf("\tValoare stocuri magazin Trioda1 = ");
	inmultireVectori(stoc_trioda1, preturi, valStoc1, nr_comp); //calculam valoarea stocurilor inmultind stocurile cu preturile / bucata
	afisareVector_reali(valStoc1, nr_comp); //afisam valorile obtinute
	printf("\tValoare stocuri magazin Trioda2 = "); //de asemenea pentru magazinul al doilea
	inmultireVectori(stoc_trioda2, preturi, valStoc2, nr_comp);
	afisareVector_reali(valStoc2, nr_comp);
	printf("\t\tValoare stocuri firma = "); //calculam valoarea totala a stocurilor
	inmultireVectori(total_stocuri, preturi, valTotalaStocuri, nr_comp); //inmultim totalul de stocuri cu preturile / bucata
	afisareVector_reali(valTotalaStocuri, nr_comp); //si obtinem valoarea totala a stocurilor celor 2 magazine
	printf("Valoare totala marfa = ");
	valTotalaMarfa=suma2Vectori(valStoc1, valStoc2, nr_comp); //valoarea totala a marfii este suma valorilor stocurilor ale celor 2 magazine
	printf("%lf\n", valTotalaMarfa);
	printf("\n\nSfarsit raport inventar.\n");
	//urmeaza raportul de dupa scumpire
	printf("\n\nDupa o luna de la inventar: \n");
	printf("\tValoare stocuri magazin Trioda1 = ");
	vectorScalar(valStoc1, scumpire, nr_comp, valScumpire/100); //calculam cu cat se scumpesc preturile inmultindu-le cu scumpirea/100, pentru ca este valoare procentuala
	sumaVectori_reali(scumpire, valStoc1, preturi_scumpite1, nr_comp); //adunam scumpirea la pretul initial pentru a obtine valoarea scumpita
	afisareVector_reali(preturi_scumpite1, nr_comp); //afisam preturile scumpite pentru magazinul 1
	printf("\tValoare stocuri magazin Trioda2 = ");
	vectorScalar(valStoc2, scumpire, nr_comp, valScumpire/100); //calculam cu cat se scumpesc preturile inmultindu-le cu scumpirea/100, pentru ca este valoare procentuala
	sumaVectori_reali(scumpire, valStoc2, preturi_scumpite2, nr_comp); //adunam scumpirea la pretul initial pentru a obtine valoarea scumpita
	afisareVector_reali(preturi_scumpite2, nr_comp); //afisam preturile scumpite pentru magazinul 2
	printf("\t\tValoare stocuri firma = ");
	sumaVectori_reali(preturi_scumpite1, preturi_scumpite2, valTotalaStocuri, nr_comp); //pentru a calcula valoarea totala dupa scumpire, adunam valorile produselor celor 2 magazine, dupa ce le-au fost aplicate scumpirile
	afisareVector_reali(valTotalaStocuri, nr_comp); //afisam valoarea totala obtinuta
	printf("Valoare totala marfa = ");
	valTotalaMarfa=suma2Vectori(preturi_scumpite1, preturi_scumpite2, nr_comp); //calculam valoarea totala a marfii dupa scumpire, sumand elementele celor 2 vectori ce contin valorile produselor dupa ce le-au fost aplicate scumpirile
	printf("%lf\n", valTotalaMarfa); //afisam valoarea obtinuta
	return 0;
}
