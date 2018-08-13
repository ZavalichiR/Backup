#include"Student.h"
#include"StudentMaster.h"
int main()
{
	PersoanaAC p1("1234567890123", "Ana", "Iasi");
	p1.afisareProfil();
	StudentAC s2;
	s2.afisareProfil();
	StudentAC s1("1234567890123", "Ion", "Vaslui", 2, 9);
	StudentAC s3("1234567890123", "Alex", "Iasi", 3, 10);
	StudentAC s4=s1.compara(s3);
	afisare(s4);
	
	afisare(s1);
	s1.afisareProfil();
	s1.schimbareAdresa("Bucuresti");
	s1.inscriereAnStudiu(3);
	s1.afisareProfil();
	system("pause");

	StudentMaster **SM = new StudentMaster*[3];
	SM[0] = new StudentMaster("1234567890123", "Alex", "Iasi", 3, 10, "Num1");
	SM[0] = new StudentMaster("1234567890123", "Andrei", "bUC", 3, 7, "Num2");
	SM[0] = new StudentMaster("1234567890123", "ZaVA", "vASLUI", 3, 5, "Num3");
	return 0;
}