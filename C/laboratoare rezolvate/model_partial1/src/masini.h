/*
 * masini.h
 *
 *  Created on: Apr 22, 2015
 *      Author: skynet
 */

#ifndef PARC_AUTOVEHICULE1_SRC_MASINI_H_
#define PARC_AUTOVEHICULE1_SRC_MASINI_H_

struct _PARC_AUTO {
	int nr_total_km[30];
	int nr_masini;
	double nr_mediu_km[30];
};

typedef struct _PARC_AUTO PARC_AUTO;

void citire(FILE *in, int a[][30], int n, int m);
void afisare(int a[][30], int n, int m);
void afisareVector_intregi(int v[30], int n);
void afisareVector_reali(double v[30], int n);
PARC_AUTO calcul(int a[][30], int n, int m);
void afisareCalcul(PARC_AUTO p, int n, int m);
unsigned int rotire_stanga(unsigned int x, int k);
void afisareBinara(unsigned int x);

#endif /* PARC_AUTOVEHICULE1_SRC_MASINI_H_ */
