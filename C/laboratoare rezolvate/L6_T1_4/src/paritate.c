/*
 * paritate.c
 *
 *  Created on: Apr 18, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "paritate.h"
L_INT paritate(L_INT x)
{
	int nr_biti, nr_biti_de_1;
	L_INT bit; //"bit" reprezinta bit-ul curent care se proceseaza
	L_INT MASCA;
	L_INT aux; //avem nevoie de o variabila auxiliara, deoarece trebuie sa facem prelucrari asupra numarului x pentru a-i numara bitii de 1
	aux=x;
	nr_biti_de_1=0;
	nr_biti=sizeof(x)<<3; //numarul de biti ai lui x
	/*
	 * numaram bit cu bit cati din acestia sunt 1, contorul fiind variabila "nr_biti_de_1"
	 * fiind paritate para, bit-ul cel mai semnificativ este pus pe 1 daca avem un numar impar de biti de 1, pentru ca, impreuna cu acesta, numarul de biti de 1 sa rezulte par
	 * 						bit-ul cel mai semnificativ este pus pe 0 daca avem un numar par de biti de 1, pentru ca, impreuna cu acesta, numarul de biti de 1 sa rezulte par
	 */
	while (nr_biti) //cat timp mai exista biti de numarat
	{
		bit=aux&(1u); //extragem ultimul bit (LSB) facand SI logic intre sirul de biti ai numarului x si urmatorul sir: 000...01
		if (bit==1) //daca acest bit extras este 1
		{
			++nr_biti_de_1; //il contorizam
		}
		aux>>=1; //shiftam numarul cu o pozitie la dreapta pentru a trece la verificarea urmatorului bit
		--nr_biti; //decrementam numarul de biti ramasi pentru verificare
	}
	MASCA=(L_INT)0; //MASCA->000...0 (conversie cast la L_INT, pentru a nu considera constanta 0 ca si avand semn, pentru evitarea extensiei de semn
	MASCA=~MASCA; //MASCA->111...1
	MASCA=MASCA>>1; //MASCA->011...1
	if ((nr_biti_de_1&(1u))==0) //daca numarul de biti de 1 este par (adica ultimul bit al numarului este 0)
	{
		x&=MASCA; //facem SI logic intre masca 011...1 si numarul x, pentru a-i seta primul bit pe 0, deoarece 0 & b = 0, pentru oricare bit b
	}
	else { //altfel, daca numarul de biti de 1 este impar (aduca ultimul bit al numarului este 1)
		MASCA=~MASCA; //MASCA->100...0
		x|=MASCA; //facem SAU logic intre masca 100...0 si numarul x, pentru a-i seta primul bit pe 1, deoarece 1 | b = 1, pentru oricare bit b
	}
	return x;
}
void afisareBinara(L_INT x) //afiseaza toti bitii unui numar intreg fara semn
{
	L_INT nr=sizeof(L_INT)<<3; //nr reprezinta numarul de biti al tipului respectiv de data; sizeof() returneaza numarul de bytes, deci trebuie inmultit cu 8 = 2^3 (shiftare la stanga cu 3 pozitii) pentru a afla numarul de biti
	//incepem sa construim masca pentru extragerea fiecarui bit (de la stanga, adica de la MSB, la dreapta, adica inspre LSB)
	L_INT MASCA=(L_INT)0; //MASCA->000...0 (conversie cast la L_INT, pentru a nu considera constanta 0 ca si avand semn, pentru evitarea extensiei de semn
	MASCA=~MASCA; //MASCA->111...1
	MASCA=MASCA>>1; //MASCA->011...1
	MASCA=~MASCA; //MASCA->100...0

	L_INT c; //c reprezinta bitul extras curent
	while (nr) //cat timp mai exista biti de extras (numarul de biti ramasi este diferit de 0)
	{
		c=(x&MASCA)>>(nr-1); //facem operatia SI intre numar si MASCA, obtinand efectiv bit-ul de pe pozitia nr
		//acesta trebuie shiftat la dreapta cu nr pozitii pentru a-l aduce pe ultima pozitie; doar astfel, poate fi citit corect, ca si "cifra" (1 sau 0)
		/* exemplu, pentru primul bit, si x=1011001, => nr=7:
		 * x&MASCA -> 1011001 &
		 * 			  1000000
		 * 			 =1000000
		 * (x&MASCA)>>nr-1 -> 0000001 = 1 (in baza 10) => primul bit este 1
		 */
		putchar(c+'0'); //dupa ce am obtinut bit-ul, il afisam ca si caracter pe ecran, deci codul ASCII al lui '0', la care adunam bitul obtinut (1 sau 0)
		MASCA>>=1; //mutam masca cu o pozitie la dreapta, pentru a putea extrage urmatorul bit inspre dreapta din numarul x
		--nr; //decrementam numarul de biti (pozitia) ramasi de extras
	}
}
