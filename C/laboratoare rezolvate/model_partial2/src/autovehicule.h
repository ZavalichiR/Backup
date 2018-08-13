/*
 * autovehicule.h
 *
 *  Created on: Apr 22, 2015
 *      Author: skynet
 */

#ifndef SRC_AUTOVEHICULE_H_
#define SRC_AUTOVEHICULE_H_

struct _PARC {
	double nr_total_litri;
	int nr_autovehicule;
	double nr_mediu_litri;
};

typedef struct _PARC PARC;

void citireVector(FILE *in, double v[], int n, int c);
void afisareVector(double v[], int n);
PARC calcul(double v[], int n);
void afisareCalcul(PARC p);
unsigned int rotireStanga(unsigned int x, int k);
void afisareBinara(unsigned int x);

#endif /* SRC_AUTOVEHICULE_H_ */
