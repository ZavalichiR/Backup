#pragma once
#include"Persoana.h"
class StudentAC :public PersoanaAC
{
	int m_ianStudiu;
	int m_inotaP2;
public:
	StudentAC();
	StudentAC(string cnp, string nume, string adresa, int anStudiu, int notaP2);
	~StudentAC();
	void afisareProfil();
	void inscriereAnStudiu(int anStudiuNou);
	int getAn()
	{
		return m_ianStudiu;
	}
	int getNota()
	{
		return m_inotaP2;
	}
	StudentAC compara(StudentAC student);
};

void afisare(StudentAC student);