#pragma once
#include <iostream>
using namespace std;

class Data {
private:
	int an, luna, zi;
public:
	Data(){ cout << "Constructor vid-DATA" << endl; }
	Data(int an, int luna, int zi);
	~Data(){ cout << "Destructor vid DATA" << endl; };
	int getAn();
	int getLuna();
	int getZi();
	/*returneaza 1 daca this > data2, 0 daca this <=
	data2*/
	int maiMare(Data data2);
};
