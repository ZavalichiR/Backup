#include"Student.h"
StudentAC::StudentAC()
{
	cout << "Constr. fara arg. StudentAC" << endl;
	m_ianStudiu = 0;
	m_inotaP2 = 0;
}
StudentAC::StudentAC(string cnp, string nume, string adresa, int anStudiu, int notaP2) :PersoanaAC(cnp, nume, adresa), m_ianStudiu(anStudiu), m_inotaP2(notaP2)
{
	cout << "Constr cu arg. StudentAC" << endl;
}
StudentAC::~StudentAC()
{
	cout << "destructor StudentAC" << endl;
}
void StudentAC::afisareProfil()
{
	cout << "------------------------------------------" << endl;
	PersoanaAC::afisareProfil();
	cout << "An studiu: " << m_ianStudiu << endl;
	cout << "Nota: " << m_inotaP2 << endl;

}
void StudentAC::inscriereAnStudiu(int anStudiuNou)
{
	this->m_ianStudiu = anStudiuNou;
}
void afisare(StudentAC student)
{
	cout << "-------------------------------------------" << endl;
	cout << "             AFISARE 2" << endl;
	cout << "Nume: " << student.getNume() << endl;
	cout << "CNP: " << student.getCnp() << endl;
	cout << "Adresa: " << student.getAdresa() << endl;
	cout << "An studiu" << student.getAn() << endl;
	cout << "Nota: " << student.getNota() << endl;
	cout << "-------------------------------------------" << endl;
}

StudentAC StudentAC::compara(StudentAC student)
{
	StudentAC tmp(*this);
	if (student.getNota() > this->m_inotaP2)
		return student;
	else
		return tmp;

}