#include"Header.h"

Atom CitesteStud(void) {
	Atom stud;
	char buffer[100];
	cout<<"Citeste numele studentului curent : ";
	cin >> buffer;
	stud.nume = new char[strlen(buffer) + 1];
	strcpy_s(stud.nume, strlen(buffer) + 1, buffer);
	return stud;
}


void AfisareStud(PNOD Data, int index) {
	printf("Studentul cu indexul %d are numele : \n ", index);
	cout<< Data->student.nume<<endl;
}

// Se definesc functiile de dispersie :

int ASCII(char *n) {
	unsigned int i;
	int suma = 0;
	for (i = 0; i < strlen(n); i++) {
		suma += *(n + i);
	}
	return (suma % M);
}

int Knuth(char *n) {
	unsigned int i;
	int lenN;
	lenN = strlen(n);
	for (i = lenN; lenN--;) {
		i = ((i << 7) ^ (i << 27)) ^ *n++;
	}
	return (i % M);
}

int Bernstein(char *n) {
	unsigned int i;
	int c;
	for (i = 5381; c = *n++;) {
		i += (i << 5) + c;
	}
	return (i % M);
}

int SDBM(char *n) {
	unsigned int i;
	int c;
	for (i = 0; c = *n++;) {
		i = (i << 6) + (i << 16) - i + c;
	}
	return (i % M);
}

// Se definesc functii pentru structura NOD :

void Initializare_HT(PNOD HT[]) {
	int i;
	for (i = 0; i < M; i++) {
		HT[i] = 0;
	}
}

void Afisare_HT(PNOD HT[]) {
	PNOD p = 0;
	int i;
	for (i = 0; i < M; i++) {
		if (HT[i] != 0) {
			p = HT[i];
			while (p != 0) {
				AfisareStud(p, i);
				p = p->succ;
			}
		}
	}
}


PNOD Cautare_HT(PNOD HT[], char *n, int(*Functie)(char *)) {
	int rez = Functie(n);
	PNOD p = HT[rez];
	if (p) {
		if (strcmp(n, p->student.nume) == 0) {
			return p;
		}
		p = p->succ;
	}
	return 0;
}

int Inserare_HT(PNOD HT[], int(*Functie)(char *)) {
	int nrColiziuni = 0;
	PNOD p = 0;
	PNOD q = 0;
	int rez;
	p = new NOD;
	p->student = CitesteStud();
	rez = Functie(p->student.nume);

	if (HT[rez] == 0) {
		HT[rez] = p;
		p->succ = 0;
	}
	else {
		q = Cautare_HT(HT, p->student.nume, Functie);
		if (q == 0) {
			p->succ = HT[rez];
			HT[rez] = p;
			nrColiziuni++;

		}
	}
	return nrColiziuni;
}














