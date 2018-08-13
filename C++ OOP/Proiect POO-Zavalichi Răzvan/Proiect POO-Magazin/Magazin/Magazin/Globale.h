#ifndef _globale_
#define _globale_
#pragma warning(disable : 4996)
#include<Windows.h>

//Se asteapta apasarea unei taste
void pauza();

//sterge ecranul
void clrscr();

//Citeste un sir de la tastatura
char *citesteSir();

void mesaj();

bool insideTree(int x, int y, const int width, const int height);
#endif
