#include"Student.h"
class StudentMaster:public StudentAC
{
	string m_sNumeDizertatie;
public:
	StudentMaster();
	StudentMaster(string cnp, string nume, string adresa, int anStudiu, int notaP2, string NumeDizertatie);
	~StudentMaster();
};