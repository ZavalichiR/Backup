#pragma once
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
void InsAVL(AVL *&a, int x);
void inordine(AVL *rad);
void afisareIndent(AVL *rad, int nivel);
AVL *arboreCurs();
void adancime(AVL *rad, int &max, int lung);
void calculBf(AVL *rad);
int adancime(AVL *rad);
int max(AVL *rad);
int min(AVL *rad);