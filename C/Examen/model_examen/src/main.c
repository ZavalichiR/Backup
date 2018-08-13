/*
 * main.c
 *
 *  Created on: May 28, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "magazine.h"
int main(int argc, char* argv[])
{
	int i, j;
	int li; //lungimea argumentului curent in linie de comanda
	int mflag=YES; //optiune implicita 'm'
	int hflag; //flag pentru optiunea '-h'
	int tflag; //flag pentru optiunea '-t'
	double valt; //valoarea totala a stocurilor
	if (argc<2) //daca nu s-a specificat niciun alt argument in afara de numele programului afisam eroare
	{
		fprintf(stderr, "Linie de comanda incorecta. Prea putine argumente.\n");
		fprintf(stderr, "Forma liniei de comanda: %s nume_fisier [-m] [-t] [-h]\n", *argv);
		exit(EXIT_FAILURE);
	}
	else if (argc<6) //daca numarul de argumente este cuprins intre 2 si 5
	{
		if (**(argv+1)=='-') //incepem sa analizam primul argument explicit, care trebuie sa fie un nume de fisier, deci sa nu inceapa cu "-"
		{
			fprintf(stderr, "Linie de comanda incorecta.\n");
			fprintf(stderr, "Forma liniei de comanda: %s nume_fisier [-m] [-t] [-h]\n", *argv);
			exit(EXIT_FAILURE);
		}
		if (argc!=2) //daca exista mai mult de 2 argumente (adica este specificata o optiune din cele 3), atunci punem flag-ul optiunii '-m' pe NO, pentru a nu mai fi implicita
		{
			mflag=NO;
		}
		hflag=NO; //setam flag-urile pe NO (0)
		tflag=NO;
		for (i=2; i<argc; ++i) //parcurgem fiecare argument specificat in parte, incepand cu al treilea (adica fara numele programului si numele fisierului)
		{
			li=strlen(*(argv+i)); //calculam lungimea sirului format de argument (pentru ca se poate considera si argumentul: "-hmt", este la fel de corect, acesta include toate 3 optiunile)
			for (j=1; j<li; ++j) //testam fiecare caracter in parte din argument, exteptand cratima
			{
				switch(*(*(argv+i)+j)) //verificam caracterul curent din argument
				{
				case 'm': mflag=YES; //daca se gaseste printre cele 3 optiuni, setam flagul corespunzator pe YES (1)
				break;
				case 'h': hflag=YES;
				break;
				case 't': tflag=YES;
				break;
				default: //daca nu este una din cele 3 optiuni, afisam eroare
					fprintf(stderr, "Linie de comanda incorecta. Optiunea \"%c\" nu exista.\n", *(*(argv+i)+j));
					fprintf(stderr, "Forma liniei de comanda: %s nume_fisier [-m] [-t] [-h]\n", *argv);
					exit(EXIT_FAILURE);
				}
			}
		}
	}
	else
	{
		fprintf(stderr, "Linie de comanda incorecta. Prea multe argumente.\n");
		fprintf(stderr, "Forma liniei de comanda: %s nume_fisier [-m] [-t] [-h]\n", *argv);
		exit(EXIT_FAILURE);
	}
	FILE *in;
	FIRMA *firma;
	in=fopen(*(argv+1), "r"); //deschidem fisierul de intrare (argumentul 2 al liniei de comanda)
	if (in==0)
	{
		fprintf(stderr, "Eroare la deschiderea fisierului %s.\n", *(argv+1));
		exit(EXIT_FAILURE);
	}
	firma=citire(in); //citim informatiile din fisier
	if (hflag) //daca exista optiunea "-h", afisam meniul de ajutor
	{
		printf("\nProgramul tine evidenta produselor comercializate de firma de magazine alimentare.\nExista urmatoarele optiuni:\n");
		printf("\t-m ->afiseaza valoarea totala a marfii detinuta de firma\n");
		printf("\t-t ->se ordoneaza matricea stocurilor alimentare in ordinea crescatoare a stocului total din fiecare magazin\n");
		printf("\t-h ->afiseaza acest meniu ajutator\n\n");
		printf("Forma liniei de comanda este: %s nume_fisier [-m] [-t] [-h]\n", *argv);
		printf("Optiunea implicita este -m\n\n");
		exit(EXIT_FAILURE); //si nu mai afisam altceva, iesim din program
	}
	else //daca nu exista setata optiunea "-h", afisam informatiile citite din fisier
	{
		afisareInformatii(firma);
	}
	if (mflag) //daca exista optiunea "-m", afisam valoarea totala a marfii
	{
		valt=valoareTotala(firma);
		printf("\nValoarea totala a marfii este %.2lf.\n", valt);
	}
	if (tflag) //daca exista optiunea "-t", ordonam matricea stocurilor si o afisam
	{
		ordonareMatrice(firma);
		printf("\nMatricea stocurilor ordonata:\n");
		afisareMatrice(firma->stoc, firma->nrMagazine, firma->nrCategoriiProduse);
	}
	free(firma->numeFirma); //golim memoria pentru toti pointerii folositi
	firma->numeFirma=0;
	dealoca2d(firma->stoc, firma->nrMagazine);
	firma->stoc=0;
	free(firma);
	firma=0;
	fclose(in); //inchidem fisierul de intrare
	return 0;
}
