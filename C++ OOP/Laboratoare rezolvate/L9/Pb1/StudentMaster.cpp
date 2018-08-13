#include"StudentMaster.h"
StudentMaster::StudentMaster(string cnp,string nume,string adresa,int anStudiu, int notaP2, string NumeDizertatie) :StudentAC(cnp,nume,adresa,anStudiu,notaP2), m_sNumeDizertatie(NumeDizertatie)
{
	cout << "Constr cu arg. StudentMaster" << endl;
}
StudentMaster::StudentMaster()
{
	cout << "Constr vid, SutdentMaster" << endl;
	m_sNumeDizertatie = "";
}
StudentMaster::~StudentMaster()
{
	cout << "Destructor StudentMaster" << endl;
}