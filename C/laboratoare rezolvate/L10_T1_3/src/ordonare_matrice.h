/*
 * ordonare_matrice.h
 *
 *  Created on: May 7, 2015
 *      Author: skynet
 */

#ifndef L10_T1_3_SRC_ORDONARE_MATRICE_H_
#define L10_T1_3_SRC_ORDONARE_MATRICE_H_

void *xmalloc(size_t nrOcteti);
double **aloca2d(int n, int m);
void dealoca2d(double **a, int n);
void citireMatrice(FILE *in, double **a, int n, int m);
void afisareMatrice(double **a, int n, int m);
double valMax(double *v, int n);
void swap(double **l1, double **l2);
void ordonareMatrice(double **a, int n, int m);

#endif /* L10_T1_3_SRC_ORDONARE_MATRICE_H_ */
