/*
 * magazine.h
 *
 *  Created on: May 28, 2015
 *      Author: skynet
 */

#ifndef SRC_MAGAZINE_H_
#define SRC_MAGAZINE_H_

#define YES 1
#define NO 0

struct _FIRMA {
	char *numeFirma;
	unsigned int nrMagazine;
	unsigned int nrCategoriiProduse;
	int **stoc;
	float *pret;
};

typedef struct _FIRMA FIRMA;

FIRMA* citire(FILE *in);
void* xmalloc(size_t nrOcteti);
int **aloca2d(int n, int m);
void dealoca2d(int **a, int n);
float* citireVector(FILE *in, int n);
int** citireMatrice(FILE *in, int n, int m);
void afisareMatrice(int **a, int n, int m);
void afisareInformatii(FIRMA *frm);
double valoareTotala(FIRMA *frm);
int stocTotal(int *vectorStoc, int n);
void swap(int **pp1, int **pp2);
void ordonareMatrice(FIRMA *frm);

#endif /* SRC_MAGAZINE_H_ */
