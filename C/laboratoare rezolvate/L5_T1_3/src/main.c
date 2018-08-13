/*
 * main.c
 *
 *  Created on: Mar 20, 2015
 *      Author: student
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conversie.h"
int main(void)
{
	FILE *in; //declaram o variabila de tip fisier
	char fisier[32], sir[32]; //declaram variabilele ce vor retine numele fisierului de intrare, respectiv sirul de transformat
	int opt;
	printf("Introduceti numele fisierului de citire: ");
	fgets(fisier, 31, stdin); //citim de la tastatura numele fisierului de intrare
	fisier[strlen(fisier)-1]='\0'; //pentru ca dupa ce am introdus numele fisierului am apasat ENTER, trebuie sa eliminam caracterul '\n' care a fost introdus si el in acel nume
	//altfel, la deschiderea fisierului, programul va cauta sa deschida un fisier cu numele "<nume_fisier>\n", pe care nu il va gasi
	//dupa aceasta operatie, numele fisierului va fi: "<nume_fisier>\0\0"
	do {
		in=fopen(fisier, "r"); //deschidem fisierul al carui nume l-am citit, ca fisier de intrare
		if (in==0) //daca nu s-a reusit deschiderea fisierului
		{
			fprintf(stderr, "Eroare la deschiderea fisierului %s.\n", fisier); //afisam eroare
			exit(EXIT_FAILURE); //iesim din program deoarece nu avem de unde sa citim sirul pentru prelucrat
		}
		printf("\nAlegeti optiunea dorita:\n\n1.TRANSFORMA DIN LITERE MARI IN LITERE MICI\n2.TRANSFORMA DIN LITERE MICI IN LITERE MARI\n3.PARASIRE PROGRAM\n");
		scanf("%d", &opt); //citim optiunea din meniu dorita de utilizator
		getchar(); //sarim enterul ramas in buffer, pentru ca avem nevoie de o citire cu fgets() dupa ce am citit cu scanf()
		switch (opt) //facem switch dupa variabila opt
		{
		case 1: //daca optiunea este 1, adica "litere mari -> litere mici"
			while (fgets(sir, 31, in)) //citim linie cu linie textul din fisier (in variabila "sir" va fi retinuta cate o linie, deoarece fgets() citeste pana la '\n' sau EOF)
			{
				litere_mici(sir); //transformam linia citita in litere mici
				fputs(sir, stdout); //afisam pe ecran linia respectiva, transformata, folosind functia fputs(), deoarece sirul are deja '\n' in componenta, iar fputs() nu adauga automat un newline la sfarsit de sir, spre deosebire de puts()
			}
			break;
		case 2: //daca optiunea este 1, adica "litere mici -> litere mari"
			while (fgets(sir, 31, in)) //citim linie cu linie textul din fisier (in variabila "sir" va fi retinuta cate o linie, deoarece fgets() citeste pana la '\n' sau EOF)
			{
				litere_mari(sir); //transformam linia citita in litere mari
				fputs(sir, stdout); //afisam pe ecran linia respectiva, transformata, folosind functia fputs(), deoarece sirul are deja '\n' in componenta, iar fputs() nu adauga automat un newline la sfarsit de sir, spre deosebire de puts()
			}
			break;
		}
		fclose(in); //inchidem fisierul de citire
	}while (opt==1 || opt==2); //repetam programul cat timp utilizatorul introduce una din cele 2 optiuni de convertire
	return 0;
}
