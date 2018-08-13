
#include"Data.h"
Data::Data(int an, int luna, int zi){
	cout << "Constructor cu parametri--DATA" << endl;
	this->an = an;
	this->luna = luna;
	this->zi = zi;
}

//folosim Get pentru a putea accesa acesti membri în altã clasã
int Data::getAn() {
	return an;
}
int Data::getLuna() {
	return luna;
}
int Data::getZi() {
	return zi;
}
/*returneaza 1 daca data1 > (este mai recenta decat)
data2, 0 in caz contrar*/
int Data::maiMare(Data data2) {
	if (an > data2.an) {
		return 1;
	}
	else if (an < data2.an) {
		return 0;
	}
	else {
		if (luna > data2.luna) {
			return 1;
		}
		else if (luna < data2.luna) {
			return 0;
		}
		else {
			if (zi > data2.zi) {
				return 1;
			}
			else if (zi < data2.zi) {
				return 0;
			}
			else {
				return 0;
			}
		}
	}
}