/*
 * conversie.c
 *
 *  Created on: Mar 20, 2015
 *      Author: student
 */
void litere_mari(char sir[]) //converteste un sir din litere mici in litere mari
{
	int i;
	i=0; //pornim cu parcurgerea sirului de la indexul 0
	while (sir[i]!='\0') //cat timp nu am ajuns la sfarsitul de sir (caracterul '\0')
	{
		if (sir[i]<='z' && sir[i]>='a') //daca suntem pe un caracter de tip litera mica (intre 'a' si 'z')
		{
			sir[i]-='a'-'A'; // <=> sir[i]=sir[i]-('a'-'A'), adica scadem diferenta dintre o litera mica si una mare, in cod ASCII, pentru a obtine litera mare
			//in codul ASCII, literele mici au valoarea mai mare decat cele mari
		}
		++i; //trecem la procesarea caracterului urmator din sir
	}
}
void litere_mici(char sir[]) //converteste un sir din litere mari in litere mici
{
	int i;
	i=0; //pornim cu parcurgerea sirului de la indexul 0
	while (sir[i]!='\0') //cat timp nu am ajuns la sfarsitul de sir (caracterul '\0')
	{
		if (sir[i]<='Z' && sir[i]>='A') //daca suntem pe un caracter de tip litera mare (intre 'A' si 'Z')
		{
			sir[i]+='a'-'A'; // <=> sir[i]=sir[i]+('a'-'A'), adica adunam diferenta dintre o litera mica si una mare, in cod ASCII, pentru a obtine litera mica
			//in codul ASCII, literele mari au valoarea mai mica decat cele mici
		}
		++i; //trecem la procesarea caracterului urmator din sir
	}
}
