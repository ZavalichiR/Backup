#include"Header.h"
int main(){
	vector<Obiect> objInrucsac;
	vector<Obiect> obj = init();
	cout << endl << "\tObiectele sunt:\n";

	for (int i = 0; i <(int)obj.size(); ++i)
		cout << obj[i].greutate << ", " << obj[i].valoare << endl;
	cout << endl << endl;

	vector<vector<Punct>> Sfinal = Rucsac(obj);
	objInrucsac = InRucsac(Sfinal, 8, obj);

	Afisare(Sfinal);

	rucsacAfisareTotala(obj);
	system("pause");
	return 0;

}