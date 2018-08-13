
using namespace std;
#include "Header.h"
int main() {
	StudentAC s1("7734567890122", "Vasile", "Neamt", 3, 10); 
	StudentAC s2("8231478901224", "Maria", "Pascani", 1, 2); 
	StudentAC s3("8231478901225", "Andrei", "Iasi", 1, 7); 
	StudentAC s4("7734567890122", "Ioana", "Galati", 3, 4); 
	StudentAC s5("8231478901229", "Andra", "Suceava", 1, 8); 
	StudentAC vs[] = { s1, s2, s3, s4, s5 };

	vector<StudentAC> vecStud(vs, vs + sizeof(vs) / sizeof(StudentAC));
	vector<StudentAC>::iterator i; 
	for (i = vecStud.begin(); i != vecStud.end(); i++)
	{
		cout << endl;
		i->afisareProfil();
	}
		

	cout << "\n-------------Dupa sortare-------------" << endl;
	//sortare(vecStud);
	sortareDescrescator(vecStud);
	for (int j = 0; j < vecStud.size(); j++)
	{
		cout << endl;
		vecStud[j].afisareProfil();
	}

	cout << "\n\n----------Metoda Clasica----------" << endl;
	StudentAC **vs2 = new StudentAC*[5];
	vs2[0] =new StudentAC("7734567890122", "Vasile", "Neamt", 3, 10);
	vs2[1] = new StudentAC("8231478901224", "Maria", "Pascani", 1, 2);
	vs2[2] = new StudentAC("8231478901225", "Andrei", "Iasi", 1, 8);
	vs2[3] = new StudentAC("7734567890122", "Ioana", "Galati", 3, 3);
	vs2[4] = new StudentAC("8231478901229", "Andra", "Suceava", 1, 5);
	for (int i = 0; i < 5; ++i)
	{
		cout << endl;
		vs2[i]->afisareProfil();
	}
	sortare2(vs2);
	cout << "\n-------Dupa sortare------" << endl;
	for (int i = 0; i < 5; ++i)
	{
		cout << endl;
		vs2[i]->afisareProfil();
	}
	system("pause");
	return 0;
}