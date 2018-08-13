#include"Angajat.h"
#include"Student.h"
#include<Windows.h>
int main() {
	/*for (int k = 0; k < 256; ++k)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
		cout << "--------" << k << "--------" << endl;
	}*/
	
	
	cout << endl << "-------------------------Studenti----------------------" << endl;
	Student **vs = new Student*[5];
	vs[0] = new Student("Popescu", "Maria", new Data(1990, 11, 23), 1204);
	vs[1] = new Student("Zavalichi", "Razvan", new Data(1996, 03, 28), 1207);
	vs[2] = new Student("Nichita", "Narics", new Data(1996, 2, 23), 1207);
	vs[3] = new Student("Porusniuc", "Poro", new Data(1994, 11, 23), 1202);
	vs[4] = new Student("Asoltanei", "Maria", new Data(1995, 11, 23), 1205);
	int ok=1;
	while (ok)
	{
		ok = 0;
		for (int i = 0; i < 4; ++i)
		{
			if (vs[i]->GetGrupa()>vs[i + 1]->GetGrupa())
			{
				Student *aux;
				aux = vs[i];
				vs[i] = vs[i + 1];
				vs[i + 1] = aux;
				ok = 1;
			}
			

		}
	} 
	for (int i = 0; i < 5; ++i)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i+1);
		vs[i]->afisare();
	}


	
	cout << endl << "-------------------------Angajati-----------------------" << endl;

	Angajat **an =new Angajat*[5];
		
		an[0] = new Angajat("Zavalichi", "Razvan", new Data(1996, 4, 4), 400, new Data(2016, 1, 1));
		an[1] = new Angajat("Filip", "Andrei", new Data(1996, 3, 3), 400, new Data(2016, 2, 1));
		an[2] = new Angajat("Barancianu", "Serban", new Data(1996, 3, 2), 400, new Data(2013, 3, 2));
		an[3] = new Angajat("Horia", "Mihai", new Data(1996, 3, 3), 400, new Data(2012, 4, 3));
		an[4] = new Angajat("Poro", "Cosmin", new Data(1996, 5, 5), 400, new Data(2011, 5, 4));
	for (int j = 0; j < 5; ++j)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), j+10);
		an[j]->afisare();
		Data ang;
		ang = an[j]->getVarstaAngajare();
		an[j]->afisarePerioadaMuncita(Data(2222, 12, 12));
		cout << "Varsta de angajare: " << ang.getAn() << " ani," << ang.getLuna() << " luni si " << ang.getZi() << " zile" << endl;
		cout << endl;

	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	/*for (int i = 0; i < 5; ++i)
	{
		delete vs[i];
	}
	delete[] vs;
	vs = nullptr;
	for (int i = 0; i < 5; ++i)
	{
		delete an[i];
	}
	delete[] an;
	an = nullptr;
	system("pause");
	return 0;*/
}