#pragma once
#include<iostream>
#include<string>
#include <vector> 
#include <algorithm> 
#include<iomanip>
using namespace std;
class StudentAC {
	int m_ianStudiu; 
	double m_dnotaP2; 
	string m_scnp; 
	string m_snume; 
	string m_sadresa;
public: 
	StudentAC();
	~StudentAC();
	StudentAC(string cnp, string nume, string adresa, int anStudiu, double notaP2); 
	void afisareProfil(); 
	void inscriereAnStudiu(int anStudiuNou);
	bool operator<(StudentAC s1); //1 pentru mai mic
	friend void sortare(vector<StudentAC> &st);
	friend void sortare2(StudentAC **st);
	friend void sortareDescrescator(vector<StudentAC> &st);
	friend bool comparare(StudentAC s1,StudentAC s2);
};
