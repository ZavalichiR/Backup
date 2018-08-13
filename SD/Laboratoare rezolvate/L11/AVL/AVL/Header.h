#ifndef _AVL_H
#define _AVL_H

#include<iostream>
using namespace std;
struct AVL{
	int data;
	int bf;
	AVL *stg, *drt;
};
void RDD(AVL *&rad);
void RSS(AVL *&rad);
void RSD(AVL *&rad);
void RDS(AVL *&rad);
void inordine(AVL *rad);
void afisareIndent(AVL *rad, int nivel);
AVL *arboreCurs();

AVL *insereaza(AVL *rad, int val);
AVL *echilibrare(AVL *rad);
void adancime(AVL *rad, int &max, int lung);
void calculBf(AVL *rad);
AVL *stergere(AVL* rad, int val);
void InsAVL(AVL *&a, int x);


#endif
