
#ifndef HEADER_H_
#define HEADER_H_
using namespace std;

#define t 2

struct nod
{
	int nr;
	int key[2 * t - 1];
	nod* fii[2 * t];
	bool frunza;
};

void creare(nod *&rad);
int cautare(nod *&rad, int k,int pozitie);
void sparge(nod *&u, int i, nod *&v);
void insereazaBArbore(nod *&rad, int k);
void afisare(nod *&rad, int nivel);
void inserareNodIncomplet(nod *&v, int k);


#endif
