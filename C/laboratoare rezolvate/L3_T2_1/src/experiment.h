/*
 * experiment.h
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */

#ifndef SRC_EXPERIMENT_H_
#define SRC_EXPERIMENT_H_

int citesteVector(FILE *in, double a[]);
void scrieVector(FILE *out, double a[], int n);
double valMedie(double a[], int n);
double abatereMedie(double a[], int n, double medie);
void afisareSubMedie(FILE *out, double a[], int n, double medie);
int creare_y(double a[], int n, double b[]);
void scrieVector_5_linie(FILE *out, double a[], int n);

#endif /* SRC_EXPERIMENT_H_ */
