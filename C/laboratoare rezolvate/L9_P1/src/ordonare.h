/*
 * ordonare.h
 *
 *  Created on: Apr 30, 2015
 *      Author: skynet
 */

#ifndef SRC_ORDONARE_H_
#define SRC_ORDONARE_H_

#define L 100

void *xmalloc(int nrOcteti);
int citireText(FILE *in, char *text[], int lMax);
void afisareText(char *text[], int nl);
void sortareLungime(char *text[], int nl);
void sortareAlfabetica(char *text[], int nl);
void sortareText(char *text[], int nl);
void eliberareMemorie(char *text[], int nl);
void schimbaP(char **p1, char **p2);

#endif /* SRC_ORDONARE_H_ */
