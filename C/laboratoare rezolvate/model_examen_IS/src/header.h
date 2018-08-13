/*
 * header.h
 *
 *  Created on: Jun 9, 2015
 *      Author: skynet
 */

#ifndef SRC_HEADER_H_
#define SRC_HEADER_H_

void CitesteMatrice(double m[][11], int nrlin, int nrcol); //functia de la punctul a)

void AfiseazaMatrice(double m[][11], int nrlin, int nrcol); //functia de la punctul b)

double MedieElementePrimaLinieMatrice(double m[][11], int nrlin, int nrcol); //functia de la punctul c)

void CitesteMatriceFisier(FILE *fisier, double m[][11], int nrlin, int nrcol); //functia de la punctul d)
//primul parametru este o variabila de tip FISIER (FILE), care este de fapt un pointer; prin acesta i se transmite functiei fisierul din care citesti

void AfisareRezultateFinale(FILE *fisier_rezultate, double matrice1[][11], int nrlin1, int nrcol1, double matrice2[][11], int nrlin2, int nrcol2); //functia de la punctul e)
//primul parametru este o variabila de tip FISIER (FILE), care este de fapt un pointer; prin acesta i se transmite functiei fisierul in care scrii rezultatele

#endif /* SRC_HEADER_H_ */
