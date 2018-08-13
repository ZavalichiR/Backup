/*
 * main.c
 *
 *  Created on: Apr 18, 2015
 *      Author: skynet
 */
#include <stdio.h>
int main(void)
{
	char c_vechi, c_nou; //c_vechi reprezinta caracterul "anterior" citit, iar c_nou este cel citit "curent"
	int litere, cifre, separatori, cuvinte, propozitii, aliniate, caractere; //variabilele ce numara tipul de caracter corespunzator
	litere=cifre=separatori=cuvinte=propozitii=aliniate=caractere=0; //le initializam pe toate deodata cu 0
	printf("Introduceti textul:\n");
	do
	{
		c_vechi=getchar(); //citim un caracter de la tastatura
		++caractere; //incrementam numarul de caractere citite
		if ((c_vechi<='z' && c_vechi>='a') || (c_vechi<='Z' && c_vechi>='A')) //caracterul este litera
		{
			++litere;
		}
		if (c_vechi>='0' && c_vechi<='9') //caracterul este cifra
		{
			++cifre;
		}
		if (c_nou==' ' || c_nou=='\t' || c_nou=='\n' || c_nou=='.' || c_nou==',' || c_nou==':' || c_nou==';' || c_nou=='-') //caracterul este separator
		{
			if ((c_vechi<='z' && c_vechi>='a') || (c_vechi<='Z' && c_vechi>='A')) //caracterul anterior trebuie sa fie o litera pentru ca cel curent sa separe un cuvant
				{
				++cuvinte;
				}
			++separatori;
		}
		if (c_vechi=='.' && c_nou==' ') //daca ne aflam pe un spatiu, iar caracterul anterior este punct, atunci s-a terminat o propozitie
		{
			++propozitii;
		}
		if (c_vechi=='\t' || (c_nou=='\n' && c_vechi=='.')) //daca ne aflam pe o linie noua, iar caracterul anterior a fost punct, sau a fost TAB, atunci a inceput un alineat nou
		{
			++aliniate;
		}
		c_vechi=c_nou; //caracterul "anterior" devine cel "curent"
		c_nou=getchar(); //citim un nou caracter de la tastatura (din BUFFER)
	} while (c_nou!=EOF); //getchar() returneaza EOF la eroare, sau la apasarea tastei CTRL+D, deci repetam citirea caracterelor cat timp nu s-a apasat CTRL+D
	printf("\nNumarul de litere: %d\nNumarul de cifre: %d\nNumarul de separatori: %d\nNUmarul de cuvinte: %d\nNumarul de propozitii: %d\nNumarul de aliniate: %d\n", litere, cifre, separatori, cuvinte, propozitii, aliniate);
	return 0;
}
