#include"Header.h"


void Student::SetNume(char sir[])
{
	int lungime = strlen(sir);
	nume = (char*)malloc((lungime + 1)*sizeof(char));
	//nume = new char[lungime + 1];
	strcpy_s(nume, lungime + 1, sir);

}


void Student :: SetNota(int n)
{
	nota = n;
}

void Student::ElibMemorie1()
{
	if (nume)
	{
		free(nume);
	}
}

void Student::citire()
{
	char buffer[100];
	int n;

	cout << "Nota: ";
	cin >> n;
	SetNota(n);

	cout << "Nume:";
	cin.ignore(100, '\n');
	cin.getline(buffer, 100);
	SetNume(buffer);

}

void Student::afisare()
{
	cout << "\nNume: " << nume << endl;
	cout << "Nota: " << nota << endl;
}

void Grupa::citire()
{
	int lungime;
	char buffer[100];
	cout << "Numar studenti: ";
	cin >> nrStud;

	cout << "Nume grupa: ";
	cin.ignore(100, '\n');
	cin.getline(buffer, 100);
	lungime = strlen(buffer);
	numeGrupa = (char*)malloc((lungime + 1)*sizeof(char));
	//numeGrupa = new char(lungime + 1);
	strcpy_s(numeGrupa, lungime + 1, buffer);

	studentii=(Student*)malloc((nrStud) * sizeof(Student));
	//studentii = new Student[nrStud];
	for (int i = 0; i < nrStud; ++i)
	{
		studentii[i].citire();
	}


}

void Grupa::afisare()
{
	cout << "In grupa " << numeGrupa <<" sunt "<<nrStud<<" studenti "<< endl;
	
	for (int i = 0; i < nrStud; ++i)
	{
		cout << "\nStudent " << i + 1 << " ";
		studentii[i].afisare();
	}


}

void Grupa::ElibMemorie()
{
	if (numeGrupa)
	{
		free(numeGrupa);
	}
	for (int i = 0; i < nrStud; ++i)
	{
		studentii[i].ElibMemorie1();
		free(studentii);
	}
	studentii = NULL;
}

void Catalog::citire()
{
	cout << "Numarul de grupe: ";
	cin >> nrGrupe;
	//grupele = new Grupa[nrGrupe];
	grupele = (Grupa*)malloc((nrGrupe) *sizeof(Grupa));
	for (int i = 0; i < nrGrupe; ++i)
	{
		cout << " Grupa:" << i + 1 << " :" << endl;
		grupele[i].citire();
	}
}

void Catalog::afisare()
{
	cout << "Sunt " << nrGrupe << " grupe: " << endl;
	for (int i = 0; i < nrGrupe; ++i)
	{
		grupele[i].afisare();
	}
}

void Catalog::elibMemorie2()
{
	if (grupele)
	{
		for (int i = 0; i < nrGrupe; ++i)
		{
			grupele[i].ElibMemorie();
			free(grupele);
		}
		grupele = NULL;
	}
}

char *Student::GetNume()
{
	return nume;
}

int Student::GetNota()
{
	return nota;
}

void Catalog::setComparator(PFnComparare comparator)
{
	int i;
	for (i = 0; i < nrGrupe; ++i)
	{
		grupele[i].comparator = comparator;
	}
}

int comparNumeDupaLungimeCrescator(Student a, Student b)
{
	int rez = strlen(a.GetNume()) - strlen(b.GetNume());
	if (rez > 0)
		rez = 1;
	else
		if (rez < 0)
			rez = -1;
	return rez;

}

int comparNumeAlfabetic(Student a, Student b)
{
	int rez = strcmp(a.GetNume(), b.GetNume());
 
	return rez;
}
int comparNoteDescrescator(Student a, Student b)
{
	 
	int rez;
	if (a.GetNota()>b.GetNota())
		rez = -1;
	else
		if (a.GetNota()<b.GetNota())
			rez = 1;
	return 0;

}

void Grupa::bSort() {		
	int ok = 1;
	while (ok) {
		ok = 0;
		for (int i = 0; i<nrStud-1; i++) {
			if (comparator(studentii[i], studentii[i + 1]) > 0)
			{
				Student aux = studentii[i];
				studentii[i] = studentii[i + 1];
				studentii[i + 1] = aux;
				ok = 1;
			}
		}
	}
}

void Catalog::sortare()
{
	for (int i = 0; i < nrGrupe; ++i)
	{
		grupele[i].bSort();
	}
}