/*
 * matrici.h
 *
 *  Created on: May 7, 2015
 *      Author: skynet
 */

#ifndef L10_T1_1_SRC_MATRICI_H_
#define L10_T1_1_SRC_MATRICI_H_

void *xmalloc(size_t nrOcteti);
double **aloca2d(int n, int m);
void dealoca2d(double **a, int n);
void citireMatrice(double **a, int n, int m);
void afisareMatrice(double **a, int n, int m);
void sumaMatrice(double **a, double **b, double **s, int n, int m);

#endif /* L10_T1_1_SRC_MATRICI_H_ */
