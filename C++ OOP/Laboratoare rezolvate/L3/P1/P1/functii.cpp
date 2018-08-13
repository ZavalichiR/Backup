
#include"Header.h"
using namespace std;

/*id Catalog::setComparator(PFnComparare comparator)
{
	int i;
	for (i = 0; i < nrGrupe; ++i)
	{
		tabGrupe[i].comparator = comparator;


	}
}

int comparNumeDupaLungimeCrescator(Student a, Student b)
{
	int rez= strlen(a.getNume()) - strlen(b.getNume());
	if (rez > 0)
	{
		rez = 1;

	}
	else
	{
		if (rez < 0)
		{
			rez = -1;
		}
	}
	return rez;
}
*/
int Student::getNota()
{
	return nota;
}

void Student::setNota(int n)
{
	nota = n;
}

void Student::setNume(char sir[])
{
	int len = strlen(sir);
	nume = new char[len + 1];
	strcpy_s(nume, len + 1, sir);


}

void Student::citire()
{
	int n;
	char buffer[100];
	
	cout << "  Nota: ";
	cin >> n;
	setNota(n);

	cout << " Nume: ";

	cin.ignore(100, '\n');
	cin.getline(buffer, 100);
	setNume(buffer);

	
}

void Student::afisare()
{
	cout << "\nNume:" << nume << endl;
	cout << "Nota:" << nota << endl;

}

void Student::elibMem()
{
	delete[] nume;
}


void Grupa::citire()
{
	char buffer[100];
	int lungime;

	cout << "\nNumar studenti: ";
	cin >> nrStud;

	cout << "\nNume grupa:";
	numeGrupa = new char;
	cin.ignore(100, '\n');
	cin.getline(buffer, 100);
	lungime = strlen(buffer);
	strcpy_s(numeGrupa, lungime + 1, buffer);

	

	tabStudenti = new Student[nrStud];
	for (int i = 0; i < nrStud; ++i)
	{
		cout << "Student " << i + 1 << endl;;
		tabStudenti[i].citire();
	}
	

}

void Grupa::afisare()
{
	cout << " Nume Grupa: " << numeGrupa << endl;

	cout << " Numar studenti: " << nrStud << endl;

	for (int i = 0; i < nrStud; ++i)
	{
		cout << "Student " << i + 1 << " : ";
		tabStudenti[i].afisare();
	}
	
	

}

void Grupa::bSort() {
	int ok = 1;
	while (ok) {
		ok = 0;
		for (int i = 0; i<nrStud; i++) {
			if (comparator(tabStudenti[i], tabStudenti[i + 1]) > 0) 
			{
				Student aux = tabStudenti[i];
				tabStudenti[i] = tabStudenti[i + 1];
				tabStudenti[i + 1] = aux;
				ok = 1;
			}
		}
	}
}

void Grupa::elibMem(void)
{
	int s;
	if (numeGrupa)
	{
		cout << " Eliberarea memoriei pentru gupa" << numeGrupa << endl;
		delete[] numeGrupa;
	}
	for (s = 0; s < nrStud; s++)
	{
		tabStudenti[s].elibMem();
		delete[] tabStudenti;
		
	}
	tabStudenti = NULL;
}


void Catalog::citire(void)
{
	cout << " Numar grupe: " << nrGrupe << endl;
	for (int i = 0; i < nrGrupe; ++i)
	{
		cout << " Grupa" << i + 1 << endl;
		tabGrupe[i].citire();
		
	}

}
void Catalog::afisare()
{
	cout << "Nr grupe:" << nrGrupe;
	for (int i = 0; i < nrGrupe; ++i)
	{
		cout << "Grupa " << i + 1 << ":";
		tabGrupe[i].afisare();
	}

}


void Catalog::sortare()
{

	for (int i = 0; i< nrGrupe; ++i)
	{
		tabGrupe[i].bSort();
	}
}

void Catalog::elibMemorie()
{
	for (int i = 0; i < nrGrupe; ++i)
	{
		tabGrupe[i].elibMem();
	}
	free(tabGrupe);
	tabGrupe = NULL;
}


