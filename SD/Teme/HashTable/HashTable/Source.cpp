#include"Header.h"

int main() {
	PNOD HT[M];
	int i, nrStud;
	int nrC1 = 0, nrC2 = 0, nrC3 = 0, nrC4 = 0;
	int(*Functie1)(char *);
	int(*Functie2)(char *);
	int(*Functie3)(char *);
	int(*Functie4)(char *);

	Functie1 = &ASCII; 
	Functie2 = &Knuth; 
	Functie3 = &Bernstein; 
	Functie4 = &SDBM;

	//La functia de citire voi incerca sa fac citire dintr-un fisier
	//ca sa nu mai trebuiasca sa se citeasca
	//de fiecare data de la tastatura  (nrStud * 4) studenti.
	cout << "\nNumar studenti: ";
	cin >> nrStud;

	cout << "\n----ASCII---" << endl;
	Initializare_HT(HT);
	for (i = 0; i < nrStud; i++) {
		nrC1 += Inserare_HT(HT, Functie1);
	}


	cout << "\n----NUTH---" << endl;
	Initializare_HT(HT);
	for (i = 0; i < nrStud; i++) {
		nrC2 += Inserare_HT(HT, Functie2);
	}

	cout << "\n----Bernstein---" << endl;
	Initializare_HT(HT);
	for (i = 0; i < nrStud; i++) {
		nrC3 += Inserare_HT(HT, Functie3);
	}

	cout << "\n----SDBM---" << endl;
	Initializare_HT(HT);
	for (i = 0; i < nrStud; i++) {
		nrC4 += Inserare_HT(HT, Functie4);
	}

	Afisare_HT(HT);

	cout << "Cu ajutorul functie de dispersie ASCII s-au calculat " << nrC1 << " coliziuni." << endl;

	cout << "Cu ajutorul functie de dispersie Knuth s-au calculat " << nrC2 << " coliziuni ." << endl;

	cout << "Cu ajutorul functie de dispersie Bernstein s-au calculat " << nrC3 << " coliziuni ." << endl;

	cout << "Cu ajutorul functie de dispersie SDBM s-au calculat" << nrC4 << " coliziuni ." << endl;

	return 0;
}

