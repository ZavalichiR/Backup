/*
 * cmmdc.c
 *
 *  Created on: Feb 26, 2015
 *      Author: skynet
 */
#include "cmmdc.h"
unsigned int cmmdc(unsigned int x, unsigned int y) //functie recursiva ce returneaza CMMDC a 2 numere x si y folosind algoritmul lui Euclid
{
	if (y>0) //daca impartitorul (viitorul rest) este diferit de 0
	{
		return cmmdc(y, x%y); //atunci apelam functia cmmdc din nou, dar de aceasta data deimpartitul devine vechiul impartitor, iar impartitorul devine restul vechi
	}
	else { //daca restul este 0, atunci CMMDC este ultimul rest nenul, adica ultimul x (de pe prima pozitie)
		return x;
	}
}
