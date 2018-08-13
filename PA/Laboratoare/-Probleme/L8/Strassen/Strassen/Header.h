#ifndef STRASSEN_H_
#define STRASSEN_H_

int** aloca2D(int n);
void dealoca2D(int **&A, int n);
void generareMatrice(int **A, int n);
void afisareMatrice(int **A, int n);
int** adunareMatrice(int** A, int** B, int n);
int** scadereMatrice(int** A, int** B, int n);
int** sfert(int** A, int n, int nrSfert);
int** concatenareMatrice(int** A, int** B, int** C, int** D, int dim);
int** strassen(int** A, int** B, int n);

#endif /* STRASSEN_H_ */