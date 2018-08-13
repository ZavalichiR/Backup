/*
 * rotire.c
 *
 *  Created on: Apr 18, 2015
 *      Author: skynet
 */
#include <stdio.h>
#include "rotire.h"
L_INT rotireDreapta(L_INT x, int k) //roteste sirul de biti al numarului x la dreapta cu k pozitii
{
	/*
	 * pentru a roti la dreapta un sir de biti cu o pozitie, se retine ultimul bit (LSB), se shifteaza bitii la dreapta cu 1 pozitie si se introduce bit-ul retinut in MSB (pe prima pozitie)
	 * exemplu: x=101001101
	 * se retine ultimul bit astfel:
	 * 101001101 &
	 * 000000001
	 * ---------
	 * 000000001=1=ultimul bit
	 * se shifteaza numarul la dreapta cu o pozitie:
	 * x=010100110
	 * se face SAU logic intre numarul shiftat si bit-ul retinut, adus in pozitia MSB
	 * 010100110 |
	 * 100000000
	 * ---------
	 * 110100110 -> am obtinut numarul rotit cu 1 pozitie la dreapta
	 */
	int n;
	L_INT bit; //reprezinta bit-ul curent care trebuie retinut
	n=(sizeof(x)<<3); //n este numarul de biti ai lui x
	while (k) //cat timp mai avem rotiri de cate 1 pozitie de efectuat
	{
		bit=x&((L_INT)1u); //facem SI logic intre numar si sirul de biti 000...01, obtinand astfel ultimul bit in variabila "bit"
		bit<<=n-1; //aducem bitul extras mai sus in pozitia MSB: b000...0
		x>>=1; //shiftam numarul la dreapta cu o pozitie
		x|=bit; //facem SAU logic intre numarul shiftat la dreapta cu o pozitie si bit-ul adus in pozitia MSB si obtinem astfel numarul rotit cu 1 pozitie la dreapta
		--k; //am executat o rotire, deci decrementam numarul de rotiri ramase
	} //numarul se roteste de k ori, executand aceeasi procedura la fiecare rotire
	return x;
}
L_INT rotireStanga(L_INT x, int k) //roteste sirul de biti al numarului x la stanga cu k pozitii
{
	/*
	 * pentru a roti la stanga un sir de biti cu o pozitie, se retine primul bit (MSB), se shifteaza bitii la stanga cu 1 pozitie si se introduce bit-ul retinut in LSB (pe ultima pozitie)
	 * exemplu: x=101001101
	 * se retine primul bit astfel:
	 * 101001101 &
	 * 100000000
	 * ---------
	 * 100000000 -> se shifteaza la dreapta, trebuind adus pe pozitia LSB: 000000001
	 * se shifteaza numarul la stanga cu o pozitie:
	 * x=010011010
	 * se face SAU logic intre numarul shiftat si bit-ul retinut, adus in pozitia LSB
	 * 010011010 |
	 * 000000001
	 * ---------
	 * 010011011 -> am obtinut numarul rotit cu 1 pozitie la stanga
	 */
	int n;
	L_INT bit, MASCA; //"bit" reprezinta bit-ul curent care trebuie retinut;
	//construim MASCA pentru a extrage bit-ul de pe pozitia MSB (primul bit)
	MASCA=(L_INT)0; //MASCA->000...0 (conversie cast la L_INT, pentru a nu considera constanta 0 ca si avand semn, pentru evitarea extensiei de semn
	MASCA=~MASCA; //MASCA->111...1
	MASCA=MASCA>>1; //MASCA->011...1
	MASCA=~MASCA; //MASCA->100...0
	n=(sizeof(x)<<3); //n este numarul de biti ai lui x
	while (k) //cat timp mai avem rotiri de cate 1 pozitie de efectuat
	{
		bit=x&MASCA; //facem SI logic intre numar si sirul de biti 100...00 si obtinem sirul b00...00
		bit>>=n-1; //apoi, trebuie sa shiftam bit-ul obtinut pe prima pozitie cu n-1 pozitii la dreapta pentru a-l aduce in pozitia LSB
		x<<=1; //shiftam numarul la stanga cu o pozitie
		x|=bit; //facem SAU logic intre numarul shiftat la stanga cu o pozitie si bit-ul adus in pozitia LSB si obtinem astfel numarul rotit cu 1 pozitie la stanga
		--k; //am executat o rotire, deci decrementam numarul de rotiri ramase
	} //numarul se roteste de k ori, executand aceeasi procedura la fiecare rotire
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
