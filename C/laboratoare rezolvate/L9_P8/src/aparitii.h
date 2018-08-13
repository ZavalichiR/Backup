/*
 * aparitii.h
 *
 *  Created on: Jun 2, 2015
 *      Author: skynet
 */

#ifndef SRC_APARITII_H_
#define SRC_APARITII_H_

#define L 50

void *xmalloc(size_t nrOcteti);
int citireText(char *text[], int lmax);
void afisareText(char *text[], int nl);
void eliberareMemorie(char *text[], int nl);
int nr_ap(char *sir, char*subsir);

#endif /* SRC_APARITII_H_ */
