#include"Header.h"
int main()
{
	cout << "------------Metoda Divide Et Impera-----------\n" << endl;

	//int x = 61438521;
	//int y = 94736407;
	//rez=5.820.464.730.934.047
	lli x2 = 10;
	lli y2 = 10;
	lli x = 61438521;// 340282367;
	lli y = 94736407;// 340282367;
	llu a = 61438521;// 340282367;
	llu b = 94736407;// 340282367;

	/*cout << "Citire valori: " <<endl;
	cout << "X: ";
	cin >> x;
	cout << "Y: ";
	cin >> y;*/

	long long rez1 = DivideEtImpera_Imbunatatit(x, y);
	long long rez2 = DivideEtImpera(x, y);

	/*cout << "A: ";
	cin >> a;
	cout << "B: ";
	cin >> b;*/

	llu rez3 = DivideEtImperaBinar(a, b, 10);
	llu rez4 = DivideEtImperaBinar_Imbunatatit(a, b, 10);

	cout << "----------------------------------------------------------" << endl;
	cout << "Divide Et Impera Imbunatatit(zecimal):   " << rez1 <<endl;
	cout << "Divide Et Impera(zecimal):               " << rez2 << endl;
	cout << "----------------------------------------------------------" << endl;
	cout << "Divide Et Impera(binar):                 " << rez3 << endl;
	cout << "Divide Et Impera Imbunatatit(binar):     " << rez4 << endl;

	system("pause");
	return 0;
}