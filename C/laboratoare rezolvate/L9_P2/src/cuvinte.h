/*
 * cuvinte.h
 *
 *  Created on: Apr 30, 2015
 *      Author: skynet
 */

#ifndef SRC_CUVINTE_H_
#define SRC_CUVINTE_H_

#define L 50

void *xmalloc(int nrOcteti);
void eliberareMemorie(char *text[], int nl);
int citireText(char *text[], int lMax);
void afisareText(char *text[], int nl);
void nrCuvinte(char *text[], int nl);
void afisareCuvinte(char *text[], int nl, int nr_linie);

#endif /* SRC_CUVINTE_H_ */
