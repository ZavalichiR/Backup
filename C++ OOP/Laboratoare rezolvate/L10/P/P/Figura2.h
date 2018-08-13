#pragma once
#include<iostream>
using namespace std;
class Figura2
{
public:
	virtual void afisare() = 0;//=0-virtual pur
	virtual double Perimetru() = 0;
	virtual double Aria() = 0;
	//deoarece este virtual pura nu se mai poate instantia in main ca exemplul precedent
	//Clasa de baza este una abstracta
};