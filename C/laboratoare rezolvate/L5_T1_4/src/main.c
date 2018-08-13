/*
 * main.c
 *
 *  Created on: Mar 20, 2015
 *      Author: student
 */
#include <stdio.h>
#include <ctype.h> //pentru a putea folosi functia isspace()
int main(void)
{
	char sir[102]; //declaram un sir de maxim 100 de caractere
	int i, cuv;
	i=0; //i este indexul caracterului curent din sir
	cuv=0; //cuv reprezinta numarul de cuvinte
	printf("Introduceti secventa de caractere (max. 100): ");
	fgets(sir, 101, stdin); //citim de la tastatura sirul, de maxim 101 caractere efective (100+ENTER)
	while (sir[i]!='\0') //parcurgem sirul cat timp nu am dat de caracterul "sfarsit de sir" ('\0')
	{
		if (isspace(sir[i])) //daca am ajuns la un caracter alb (spatiu, tab, newline etc.)
			++cuv; //inseamna ca am trecut de un cuvant, deci il numaram
		++i; //trecem la urmatorul caracter din sir
	}
	printf("Exista %d cuvinte in sirul introdus.\n", cuv); //afisam pe ecran rezultatul
	return 0;
}
