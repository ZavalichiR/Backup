#include"Header.h"
StudentAC::StudentAC(string cnp, string nume, string adresa, int anStudiu, double notaP2)
{
	m_scnp = cnp;
	m_snume = nume;
	m_sadresa = adresa;
	m_ianStudiu = anStudiu;
	m_dnotaP2 = notaP2;
}
StudentAC::StudentAC()
{
	cout << "\nApelare contrusctor" << endl;
	m_scnp = "";
	m_snume ="";
	m_sadresa = "";
	m_ianStudiu = 0;
	m_dnotaP2 = 0;
}
StudentAC::~StudentAC()
{
	//cout << "\nApelare destrusctor" << endl;
	m_scnp = "";
	m_snume = "";
	m_sadresa = "";
	m_ianStudiu = 0;
	m_dnotaP2 = 0;
}
void StudentAC::afisareProfil()
{
	cout << " Nume: " << m_snume;
	cout << " CNP: " << m_scnp;
	cout << " Adresa: " << m_sadresa;
	cout << " An studiu: " << m_ianStudiu;
	cout << " Nota: " << setprecision(3) << m_dnotaP2;
}
bool StudentAC::operator<(StudentAC s1)
{
	if (this->m_dnotaP2 < s1.m_dnotaP2)
		return 1;
	else
		return 0;
}
void sortare(vector<StudentAC> &st)
{
	sort(st.begin(), st.end());
	
}
void sortare2(StudentAC **st)
{
	int dim = sizeof(st)+sizeof(st) / sizeof(st[0]);
	int ok = 1;
	while (ok)
	{
		ok = 0;
		for (int j = 0; j < dim-1; ++j)
		{
			
			if (*st[j]<*st[j+1])
			//if (st[j]->m_dnotaP2<st[j + 1]->m_dnotaP2)
			{
				StudentAC *aux = st[j];
				st[j] = st[j + 1];
				st[j + 1] = aux;
				ok = 1;
			}
		}

	}

}
void sortareDescrescator(vector<StudentAC> &st)
{
	sort(st.begin(), st.end(),comparare);
}

bool comparare(StudentAC s1, StudentAC s2)
{
		if (s1<s2)
			return 0;
		else
			return 1;
}
