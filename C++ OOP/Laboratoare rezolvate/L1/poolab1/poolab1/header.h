#ifndef _SortareSiruri_
#define _SortareSiruri_

typedef struct _catalog{
	int nr;
	char** vsiruri;
	void (*sortare1)(char**,int);
	void (*sortare2)(char**,int);
	char** (*citire)(int);
}catalog;

char **citireVSiruri(int n);
void sortareVSiruriLungime(char ** vsiruri, int n);
void sortareVSiruriAlfabetic(char ** vsiruri, int n);
catalog creareCatalog(int n);
void afisareVSiruri(char **vsiruri, int n);
void dealocareVSiruri(char **vsiruri, int n);
#endif