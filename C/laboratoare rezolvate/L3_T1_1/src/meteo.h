/*
 * meteo.h
 *
 *  Created on: Apr 14, 2015
 *      Author: skynet
 */

#ifndef SRC_METEO_H_
#define SRC_METEO_H_

void citireVector(int a[], int n);
void afisareVector(FILE *out, int a[], int n);
int maxVector(int a[], int n);
int minVector(int a[], int n);
double medieAritmVector(int a[], int n);
double medieGeomVector(int a[], int n);

#endif /* SRC_METEO_H_ */
