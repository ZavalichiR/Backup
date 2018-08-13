/*
 * matrice.h
 *
 *  Created on: May 9, 2015
 *      Author: skynet
 */

#ifndef SRC_MATRICE_H_
#define SRC_MATRICE_H_

struct _MATRICE {
	char *nume;
	unsigned int n, m;
	double **a;
};

typedef struct _MATRICE MATRICE;

void* xmalloc(size_t nrOcteti);
void aloca2d(double **a, unsigned int n, unsigned int m);
void dealoca2d(double **a, unsigned int n);
double **citireMatrice(unsigned int n, unsigned int m);
void afisareMatrice(MATRICE* matrice);
MATRICE incarcareInformatii(char *nume);

#endif /* SRC_MATRICE_H_ */
